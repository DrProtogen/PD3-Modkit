param(
    [string]$ConfigPath = ''
)

$ErrorActionPreference = 'Stop'
$ProgressPreference = 'SilentlyContinue'

$script:AllowClose = $false
$script:State = 'WaitingForEditor'
$script:EditorClosedAt = $null
$script:ActiveProcess = $null
$script:ActiveStdOutTask = $null
$script:ActiveStdErrTask = $null
$script:UpdateCompleted = $false
$script:PullSucceeded = $false
$script:StashCreated = $false
$script:StashName = 'stash@{0}'
$script:RestoreReason = ''
$script:ReopenAt = $null
$script:BackupRoot = ''
$script:BackupContentPath = ''
$script:BackupCreated = $false
$script:ReadySignaled = $false

$bootstrapLogPath = Join-Path $PSScriptRoot 'PD3ModkitUpdate.bootstrap.log'

function Write-BootstrapLog {
    param([string]$Message)

    try {
        $timestamp = Get-Date -Format 'yyyy-MM-dd HH:mm:ss'
        "[$timestamp] $Message" | Out-File -FilePath $bootstrapLogPath -Append -Encoding utf8
    }
    catch {
    }
}

Write-BootstrapLog "Updater script entered. PowerShell PID: $PID"
Write-BootstrapLog "PowerShell version: $($PSVersionTable.PSVersion)"
Write-BootstrapLog "Script path: $PSCommandPath"
Write-BootstrapLog "Config path argument: $ConfigPath"

$EditorPid = 0
$RepositoryRoot = ''
$RemoteName = ''
$BranchName = ''
$LogPath = ''
$EditorExecutable = ''
$ProjectFile = ''
$ReadyFile = ''

try {
    if ([string]::IsNullOrWhiteSpace($ConfigPath)) {
        throw 'ConfigPath was not supplied.'
    }

    if (-not (Test-Path -LiteralPath $ConfigPath -PathType Leaf)) {
        throw "Updater config file does not exist: $ConfigPath"
    }

    $config = Get-Content -LiteralPath $ConfigPath -Raw -Encoding UTF8 | ConvertFrom-Json

    $EditorPid = [int]$config.EditorPid
    $RepositoryRoot = [string]$config.RepositoryRoot
    $RemoteName = [string]$config.RemoteName
    $BranchName = [string]$config.BranchName
    $LogPath = [string]$config.LogPath
    $EditorExecutable = [string]$config.EditorExecutable
    $ProjectFile = [string]$config.ProjectFile
    $ReadyFile = [string]$config.ReadyFile

    Write-BootstrapLog 'Updater config loaded successfully.'
}
catch {
    $fatalMessage = "FATAL config load error: $($_.Exception.Message)"
    Write-BootstrapLog $fatalMessage
    exit 8
}

if ([string]::IsNullOrWhiteSpace($LogPath)) {
    $LogPath = Join-Path $PSScriptRoot 'PD3ModkitUpdate.log'
}

function Write-UpdateLog {
    param([string]$Message)

    try {
        $timestamp = Get-Date -Format 'yyyy-MM-dd HH:mm:ss'
        "[$timestamp] $Message" | Out-File -FilePath $LogPath -Append -Encoding utf8
    }
    catch {
        Write-BootstrapLog "Logging failure: $($_.Exception.Message)"
    }
}

try {
    $logDirectory = Split-Path -Parent $LogPath
    if (-not [string]::IsNullOrWhiteSpace($logDirectory)) {
        New-Item -ItemType Directory -Path $logDirectory -Force | Out-Null
    }

    New-Item -ItemType File -Path $LogPath -Force | Out-Null
    Clear-Content -Path $LogPath

    if ($EditorPid -le 0) {
        throw 'EditorPid was not supplied or was invalid.'
    }

    if ([string]::IsNullOrWhiteSpace($RepositoryRoot)) {
        throw 'RepositoryRoot was not supplied.'
    }

    if ([string]::IsNullOrWhiteSpace($RemoteName)) {
        throw 'RemoteName was not supplied.'
    }

    if ([string]::IsNullOrWhiteSpace($BranchName)) {
        throw 'BranchName was not supplied.'
    }

    if ([string]::IsNullOrWhiteSpace($EditorExecutable)) {
        throw 'EditorExecutable was not supplied.'
    }

    if ([string]::IsNullOrWhiteSpace($ProjectFile)) {
        throw 'ProjectFile was not supplied.'
    }

    if ([string]::IsNullOrWhiteSpace($ReadyFile)) {
        throw 'ReadyFile was not supplied.'
    }

    $projectDirectory = Split-Path -Parent $ProjectFile
    if ([string]::IsNullOrWhiteSpace($projectDirectory)) {
        throw "Could not determine the project directory from '$ProjectFile'."
    }

    $contentDirectory = Join-Path $projectDirectory 'Content'
    $localAppData = [System.Environment]::GetFolderPath([System.Environment+SpecialFolder]::LocalApplicationData)
    if ([string]::IsNullOrWhiteSpace($localAppData)) {
        throw 'Windows did not return a LocalAppData directory.'
    }

    $backupBase = Join-Path $localAppData 'PAYDAY3-Modding\PD3-Modkit\UpdateBackups'

    Write-UpdateLog "Updater process started. PID: $PID"
    Write-UpdateLog "Repository: $RepositoryRoot"
    Write-UpdateLog "Remote: $RemoteName"
    Write-UpdateLog "Branch: $BranchName"
    Write-UpdateLog "Project: $ProjectFile"
    Write-UpdateLog "Editor: $EditorExecutable"
    Write-UpdateLog "Ready handshake: $ReadyFile"
    Write-BootstrapLog 'Startup parameters validated successfully.'
}
catch {
    $fatalMessage = "FATAL startup initialization error: $($_.Exception.Message)"
    Write-BootstrapLog $fatalMessage
    Write-UpdateLog $fatalMessage
    exit 9
}

try {
    Add-Type -AssemblyName PresentationFramework
    Add-Type -AssemblyName PresentationCore
    Add-Type -AssemblyName WindowsBase
}
catch {
    $fatalMessage = "FATAL: Could not load WPF assemblies: $($_.Exception.Message)"
    Write-BootstrapLog $fatalMessage
    Write-UpdateLog $fatalMessage
    exit 10
}

function Quote-NativeArgument {
    param([string]$Value)

    if ($null -eq $Value) {
        return '""'
    }

    return '"' + $Value.Replace('"', '\"') + '"'
}

function Write-ProcessOutputToLog {
    param(
        [string]$StdOut,
        [string]$StdErr
    )

    foreach ($line in ($StdOut -split "`r?`n")) {
        if (-not [string]::IsNullOrWhiteSpace($line)) {
            Write-UpdateLog $line
        }
    }

    foreach ($line in ($StdErr -split "`r?`n")) {
        if (-not [string]::IsNullOrWhiteSpace($line)) {
            Write-UpdateLog $line
        }
    }
}

function Start-ManagedProcess {
    param(
        [string]$FileName,
        [string]$Arguments,
        [string]$NextState,
        [string]$Status,
        [string]$Detail
    )

    Set-Status -Status $Status -Detail $Detail
    Write-UpdateLog "Starting: $FileName $Arguments"

    $startInfo = New-Object System.Diagnostics.ProcessStartInfo
    $startInfo.FileName = $FileName
    $startInfo.Arguments = $Arguments
    $startInfo.UseShellExecute = $false
    $startInfo.CreateNoWindow = $true
    $startInfo.RedirectStandardOutput = $true
    $startInfo.RedirectStandardError = $true

    $script:ActiveProcess = New-Object System.Diagnostics.Process
    $script:ActiveProcess.StartInfo = $startInfo

    if (-not $script:ActiveProcess.Start()) {
        throw "Could not start $FileName."
    }

    $script:ActiveStdOutTask = $script:ActiveProcess.StandardOutput.ReadToEndAsync()
    $script:ActiveStdErrTask = $script:ActiveProcess.StandardError.ReadToEndAsync()
    $script:State = $NextState
}

function Complete-ActiveProcess {
    $stdOut = $script:ActiveStdOutTask.Result
    $stdErr = $script:ActiveStdErrTask.Result
    $exitCode = $script:ActiveProcess.ExitCode

    Write-ProcessOutputToLog -StdOut $stdOut -StdErr $stdErr

    $result = [PSCustomObject]@{
        ExitCode = $exitCode
        StdOut = $stdOut
        StdErr = $stdErr
    }

    $script:ActiveProcess = $null
    $script:ActiveStdOutTask = $null
    $script:ActiveStdErrTask = $null
    return $result
}

$windowXaml = @"
<Window xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="PD3 Modkit Updater"
        Width="560"
        Height="320"
        ResizeMode="NoResize"
        WindowStartupLocation="CenterScreen"
        ShowInTaskbar="True"
        Topmost="True"
        Background="#202020"
        Foreground="#F2F2F2"
        FontFamily="Segoe UI">
    <Grid Margin="24">
        <Grid.RowDefinitions>
            <RowDefinition Height="Auto"/>
            <RowDefinition Height="Auto"/>
            <RowDefinition Height="Auto"/>
            <RowDefinition Height="Auto"/>
            <RowDefinition Height="*"/>
            <RowDefinition Height="Auto"/>
        </Grid.RowDefinitions>

        <TextBlock Grid.Row="0"
                   Text="Updating PD3 Modkit"
                   FontSize="22"
                   FontWeight="SemiBold"
                   Margin="0,0,0,10"/>

        <TextBlock Grid.Row="1"
                   Name="WarningText"
                   Text="Please do not reopen the project while the update is in progress."
                   Foreground="#CFCFCF"
                   TextWrapping="Wrap"
                   Margin="0,0,0,20"/>

        <ProgressBar Grid.Row="2"
                     Name="ProgressBar"
                     Height="12"
                     IsIndeterminate="True"
                     Margin="0,0,0,18"/>

        <TextBlock Grid.Row="3"
                   Name="StatusText"
                   Text="Waiting for Unreal Editor to close..."
                   FontSize="14"
                   FontWeight="SemiBold"
                   TextWrapping="Wrap"
                   Margin="0,0,0,8"/>

        <TextBlock Grid.Row="4"
                   Name="DetailText"
                   Text="The update will begin automatically as soon as Unreal Editor has fully exited."
                   Foreground="#AFAFAF"
                   TextWrapping="Wrap"/>

        <StackPanel Grid.Row="5"
                    Name="ButtonPanel"
                    Orientation="Horizontal"
                    HorizontalAlignment="Right"
                    Visibility="Collapsed"
                    Margin="0,20,0,0">
            <Button Name="OpenBackupButton"
                    Content="Open Content Backup"
                    MinWidth="140"
                    Height="30"
                    Margin="0,0,8,0"
                    Padding="12,0"
                    Visibility="Collapsed"/>
            <Button Name="ViewLogButton"
                    Content="View Update Log"
                    MinWidth="120"
                    Height="30"
                    Margin="0,0,8,0"
                    Padding="12,0"/>
            <Button Name="ReopenButton"
                    Content="Reopen Project"
                    MinWidth="110"
                    Height="30"
                    Margin="0,0,8,0"
                    Padding="12,0"
                    Visibility="Collapsed"/>
            <Button Name="CloseButton"
                    Content="Close"
                    MinWidth="82"
                    Height="30"
                    Padding="12,0"/>
        </StackPanel>
    </Grid>
</Window>
"@

try {
    $xmlReader = New-Object System.Xml.XmlNodeReader ([xml]$windowXaml)
    $window = [System.Windows.Markup.XamlReader]::Load($xmlReader)
}
catch {
    $fatalMessage = "FATAL: Could not create updater window: $($_.Exception.Message)"
    Write-BootstrapLog $fatalMessage
    Write-UpdateLog $fatalMessage
    exit 11
}

$progressBar = $window.FindName('ProgressBar')
$statusText = $window.FindName('StatusText')
$detailText = $window.FindName('DetailText')
$warningText = $window.FindName('WarningText')
$buttonPanel = $window.FindName('ButtonPanel')
$openBackupButton = $window.FindName('OpenBackupButton')
$viewLogButton = $window.FindName('ViewLogButton')
$reopenButton = $window.FindName('ReopenButton')
$closeButton = $window.FindName('CloseButton')

function Set-Status {
    param(
        [string]$Status,
        [string]$Detail
    )

    $statusText.Text = $Status
    $detailText.Text = $Detail
}

function Show-Failure {
    param(
        [string]$Status,
        [string]$Detail,
        [bool]$CanRetryReopen
    )

    Write-UpdateLog "$Status $Detail"
    $script:State = 'Failed'
    $script:AllowClose = $true
    $progressBar.IsIndeterminate = $false
    $progressBar.Value = 0
    $warningText.Text = 'The updater has stopped. Review the message below before reopening the project.'
    Set-Status -Status $Status -Detail $Detail
    $buttonPanel.Visibility = 'Visible'

    if ($script:BackupCreated -and (Test-Path -LiteralPath $script:BackupRoot)) {
        $openBackupButton.Visibility = 'Visible'
    }
    else {
        $openBackupButton.Visibility = 'Collapsed'
    }

    if ($CanRetryReopen) {
        $reopenButton.Visibility = 'Visible'
    }
    else {
        $reopenButton.Visibility = 'Collapsed'
    }
}

function Start-Editor {
    try {
        Write-UpdateLog "Reopening project: $ProjectFile"

        $launchInfo = New-Object System.Diagnostics.ProcessStartInfo
        $launchInfo.FileName = $EditorExecutable
        $launchInfo.Arguments = '"' + $ProjectFile.Replace('"', '\"') + '"'
        $launchInfo.WorkingDirectory = Split-Path -Parent $ProjectFile
        $launchInfo.UseShellExecute = $true

        $launched = [System.Diagnostics.Process]::Start($launchInfo)
        if ($null -eq $launched) {
            throw 'The Unreal Editor process did not start.'
        }

        return $true
    }
    catch {
        Write-UpdateLog "REOPEN FAILED: $($_.Exception.Message)"
        return $false
    }
}

function Save-LastBackupPointer {
    try {
        if (-not $script:BackupCreated) {
            return
        }

        New-Item -ItemType Directory -Path $backupBase -Force | Out-Null
        $lastBackupFile = Join-Path $backupBase 'LastContentBackup.txt'
        $script:BackupRoot | Set-Content -LiteralPath $lastBackupFile -Encoding UTF8
    }
    catch {
        Write-UpdateLog "Could not write LastContentBackup.txt: $($_.Exception.Message)"
    }
}

function Start-ContentBackup {
    try {
        if (-not (Test-Path -LiteralPath $contentDirectory -PathType Container)) {
            Write-UpdateLog "No Content directory found at $contentDirectory. Skipping Content backup."
            Set-Status -Status 'Preparing local changes...' -Detail 'No project Content folder was found, so there was nothing to back up.'
            Start-GitStatus
            return
        }

        $timestamp = Get-Date -Format 'yyyy-MM-dd_HHmmss'
        $script:BackupRoot = Join-Path $backupBase $timestamp
        $script:BackupContentPath = Join-Path $script:BackupRoot 'Content'

        New-Item -ItemType Directory -Path $script:BackupContentPath -Force | Out-Null

        $metadata = @(
            "PD3 Modkit automatic Content backup",
            "Created: $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')",
            "Project: $ProjectFile",
            "Repository: $RepositoryRoot",
            "Branch: $BranchName"
        )
        $metadata | Set-Content -LiteralPath (Join-Path $script:BackupRoot 'BackupInfo.txt') -Encoding UTF8

        $arguments = (Quote-NativeArgument $contentDirectory) + ' ' +
                     (Quote-NativeArgument $script:BackupContentPath) +
                     ' /E /COPY:DAT /DCOPY:DAT /R:2 /W:1 /XJ /NP /NFL /NDL /NJH'

        Start-ManagedProcess `
            -FileName 'robocopy.exe' `
            -Arguments $arguments `
            -NextState 'BackingUpContent' `
            -Status 'Backing up project Content...' `
            -Detail "Creating a safety copy before Git changes anything.`n$($script:BackupContentPath)"
    }
    catch {
        Show-Failure -Status 'Content backup failed.' -Detail "No update was attempted. $($_.Exception.Message)" -CanRetryReopen $true
    }
}

function Finish-ContentBackup {
    $result = Complete-ActiveProcess

    # Robocopy uses 0-7 for successful/acceptable outcomes. 8+ is failure.
    if ($result.ExitCode -ge 8) {
        Show-Failure -Status 'Content backup failed.' -Detail "Robocopy exited with code $($result.ExitCode). No Git update was attempted. Open the update log for details." -CanRetryReopen $true
        return
    }

    $script:BackupCreated = $true
    Save-LastBackupPointer
    Write-UpdateLog "Content backup completed: $($script:BackupContentPath)"
    Start-GitStatus
}

function Start-GitStatus {
    try {
        $arguments = '-C ' + (Quote-NativeArgument $RepositoryRoot) + ' status --porcelain=v1 --untracked-files=all'
        Start-ManagedProcess `
            -FileName 'git.exe' `
            -Arguments $arguments `
            -NextState 'CheckingLocalChanges' `
            -Status 'Preparing local changes...' `
            -Detail 'Checking for uncommitted and untracked files that need to be preserved.'
    }
    catch {
        Show-Failure -Status 'Update failed.' -Detail "Could not inspect the Git working tree: $($_.Exception.Message)" -CanRetryReopen $true
    }
}

function Finish-GitStatus {
    $result = Complete-ActiveProcess
    if ($result.ExitCode -ne 0) {
        Show-Failure -Status 'Update failed.' -Detail 'Could not inspect the Git working tree. No update was attempted. Open the update log for details.' -CanRetryReopen $true
        return
    }

    if ([string]::IsNullOrWhiteSpace($result.StdOut)) {
        Write-UpdateLog 'No uncommitted or untracked Git changes detected.'
        Start-GitPull
        return
    }

    Start-GitStash
}

function Start-GitStash {
    try {
        $stashMessage = 'PD3 Modkit Updater Backup ' + (Get-Date -Format 'yyyy-MM-dd HH:mm:ss')
        $arguments = '-C ' + (Quote-NativeArgument $RepositoryRoot) +
                     ' stash push --include-untracked -m ' + (Quote-NativeArgument $stashMessage)

        Start-ManagedProcess `
            -FileName 'git.exe' `
            -Arguments $arguments `
            -NextState 'StashingLocalChanges' `
            -Status 'Protecting your local changes...' `
            -Detail 'Temporarily stashing uncommitted tracked and untracked files. They will be restored after the update.'
    }
    catch {
        Show-Failure -Status 'Could not protect local changes.' -Detail "No update was attempted. $($_.Exception.Message)" -CanRetryReopen $true
    }
}

function Finish-GitStash {
    $result = Complete-ActiveProcess
    if ($result.ExitCode -ne 0) {
        Show-Failure -Status 'Could not protect local changes.' -Detail 'Git stash failed, so the updater stopped before pulling anything. Your Content backup is safe. Open the log for details.' -CanRetryReopen $true
        return
    }

    $script:StashCreated = $true
    Write-UpdateLog "Local changes stored in $($script:StashName)."
    Start-GitPull
}

function Start-GitPull {
    try {
        $arguments = '-C ' + (Quote-NativeArgument $RepositoryRoot) +
                     ' pull --ff-only ' + (Quote-NativeArgument $RemoteName) + ' ' + (Quote-NativeArgument $BranchName)

        Start-ManagedProcess `
            -FileName 'git.exe' `
            -Arguments $arguments `
            -NextState 'Pulling' `
            -Status 'Downloading and applying the latest update...' `
            -Detail "Pulling $RemoteName/$BranchName from the official PD3 Modkit repository."
    }
    catch {
        if ($script:StashCreated) {
            $script:RestoreReason = 'PullFailed'
            Start-GitRestore
        }
        else {
            Show-Failure -Status 'Update failed.' -Detail "Could not start Git: $($_.Exception.Message)" -CanRetryReopen $true
        }
    }
}

function Finish-GitPull {
    $result = Complete-ActiveProcess

    if ($result.ExitCode -ne 0) {
        Write-UpdateLog "git pull failed with exit code $($result.ExitCode)."

        if ($script:StashCreated) {
            $script:RestoreReason = 'PullFailed'
            Start-GitRestore
        }
        else {
            Show-Failure -Status 'Update failed.' -Detail "git pull failed with exit code $($result.ExitCode). No local Git changes were stashed. Open the update log for details." -CanRetryReopen $true
        }
        return
    }

    $script:PullSucceeded = $true
    $script:UpdateCompleted = $true
    Write-UpdateLog 'PD3 Modkit Git update completed successfully.'

    if ($script:StashCreated) {
        $script:RestoreReason = 'AfterUpdate'
        Start-GitRestore
    }
    else {
        Complete-UpdateAndScheduleReopen
    }
}

function Start-GitRestore {
    # The working tree can become dirty again after the user's stash has been
    # created. Rider/MSBuild/Unreal helper processes can rewrite tracked obj
    # files or regenerate untracked binaries while Git is pulling. Those files
    # were created after the user's real changes were safely stashed, so clean
    # the post-stash working tree before attempting to reapply the user stash.
    try {
        $arguments = '-C ' + (Quote-NativeArgument $RepositoryRoot) + ' reset --hard HEAD'

        Start-ManagedProcess `
            -FileName 'git.exe' `
            -Arguments $arguments `
            -NextState 'PreparingRestoreReset' `
            -Status 'Preparing to restore your changes...' `
            -Detail 'Removing temporary tracked-file changes created while the Modkit was updating.'
    }
    catch {
        Show-RestoreFailure -Reason $script:RestoreReason -Extra "Could not prepare the working tree for restore. $($_.Exception.Message)"
    }
}

function Finish-GitRestoreReset {
    $result = Complete-ActiveProcess

    if ($result.ExitCode -ne 0) {
        Show-RestoreFailure -Reason $script:RestoreReason -Extra "git reset --hard HEAD exited with code $($result.ExitCode). The updater stash has been kept."
        return
    }

    Write-UpdateLog 'Post-stash tracked-file changes cleared before restoring the user stash.'
    Start-GitRestoreClean
}

function Start-GitRestoreClean {
    try {
        $arguments = '-C ' + (Quote-NativeArgument $RepositoryRoot) + ' clean -fd'

        Start-ManagedProcess `
            -FileName 'git.exe' `
            -Arguments $arguments `
            -NextState 'PreparingRestoreClean' `
            -Status 'Preparing to restore your changes...' `
            -Detail 'Removing temporary untracked build files created while the Modkit was updating.'
    }
    catch {
        Show-RestoreFailure -Reason $script:RestoreReason -Extra "Could not clean temporary untracked files before restore. $($_.Exception.Message)"
    }
}

function Finish-GitRestoreClean {
    $result = Complete-ActiveProcess

    if ($result.ExitCode -ne 0) {
        Show-RestoreFailure -Reason $script:RestoreReason -Extra "git clean -fd exited with code $($result.ExitCode). The updater stash has been kept."
        return
    }

    Write-UpdateLog 'Post-stash untracked files cleared before restoring the user stash.'
    Start-GitRestoreApply
}

function Start-GitRestoreApply {
    try {
        $arguments = '-C ' + (Quote-NativeArgument $RepositoryRoot) +
                     ' stash apply --index ' + (Quote-NativeArgument $script:StashName)

        Start-ManagedProcess `
            -FileName 'git.exe' `
            -Arguments $arguments `
            -NextState 'RestoringLocalChanges' `
            -Status 'Restoring your local changes...' `
            -Detail 'Reapplying the uncommitted files that were protected before the update.'
    }
    catch {
        Show-RestoreFailure -Reason $script:RestoreReason -Extra $($_.Exception.Message)
    }
}

function Finish-GitRestore {
    $result = Complete-ActiveProcess

    if ($result.ExitCode -ne 0) {
        Show-RestoreFailure -Reason $script:RestoreReason -Extra "git stash apply exited with code $($result.ExitCode)."
        return
    }

    Write-UpdateLog 'Local changes restored successfully.'
    Start-GitDropStash
}

function Start-GitDropStash {
    try {
        $arguments = '-C ' + (Quote-NativeArgument $RepositoryRoot) +
                     ' stash drop ' + (Quote-NativeArgument $script:StashName)

        Start-ManagedProcess `
            -FileName 'git.exe' `
            -Arguments $arguments `
            -NextState 'DroppingUpdaterStash' `
            -Status 'Finishing update...' `
            -Detail 'Local changes were restored. Cleaning up the temporary updater stash.'
    }
    catch {
        Write-UpdateLog "Could not drop updater stash: $($_.Exception.Message). The restored changes are still present and the stash has been kept as an extra backup."
        Finish-AfterRestore
    }
}

function Finish-GitDropStash {
    $result = Complete-ActiveProcess

    if ($result.ExitCode -ne 0) {
        Write-UpdateLog "Could not drop $($script:StashName). It has been left in the stash list as an additional safety copy."
    }
    else {
        $script:StashCreated = $false
        Write-UpdateLog 'Temporary updater stash removed after successful restore.'
    }

    Finish-AfterRestore
}

function Finish-AfterRestore {
    if ($script:RestoreReason -eq 'PullFailed') {
        Show-Failure `
            -Status 'Update failed, but your local changes were restored.' `
            -Detail "The Git update did not complete. Your working changes were restored and the Content backup is available at:`n$($script:BackupRoot)" `
            -CanRetryReopen $true
        return
    }

    Complete-UpdateAndScheduleReopen
}

function Show-RestoreFailure {
    param(
        [string]$Reason,
        [string]$Extra
    )

    $backupNote = if ($script:BackupCreated) { " A full Content backup is available at: $($script:BackupRoot)." } else { '' }

    if ($Reason -eq 'AfterUpdate') {
        Show-Failure `
            -Status 'Update installed, but local changes need manual attention.' `
            -Detail "The Modkit update succeeded, but Git could not reapply your local changes cleanly. The temporary stash has NOT been deleted and may be partially applied. Resolve the Git conflicts manually before reopening the project.$backupNote $Extra" `
            -CanRetryReopen $false
    }
    else {
        Show-Failure `
            -Status 'Update failed and local changes need manual attention.' `
            -Detail "The update did not complete, and Git could not automatically restore the temporary stash. The stash has NOT been deleted.$backupNote $Extra" `
            -CanRetryReopen $false
    }
}

function Complete-UpdateAndScheduleReopen {
    Save-LastBackupPointer
    Write-UpdateLog 'PD3 Modkit update and local-change restoration completed successfully.'
    if ($script:BackupCreated) {
        Write-UpdateLog "Content safety backup: $($script:BackupRoot)"
    }

    Set-Status -Status 'Update complete.' -Detail 'Your Content backup is safe and local changes have been restored. Reopening PD3 Modkit...'
    $warningText.Text = 'The update was installed successfully. The project will reopen automatically.'
    $script:ReopenAt = [DateTime]::UtcNow.AddMilliseconds(900)
    $script:State = 'ReopenPending'
}

Write-UpdateLog "Updater UI initialized. Waiting for Unreal Editor process $EditorPid to close."
Write-UpdateLog "Content backup base: $backupBase"

$window.Add_ContentRendered({
    if (-not $script:ReadySignaled) {
        try {
            $readyDirectory = Split-Path -Parent $ReadyFile
            if (-not [string]::IsNullOrWhiteSpace($readyDirectory)) {
                New-Item -ItemType Directory -Path $readyDirectory -Force | Out-Null
            }

            "ready" | Set-Content -LiteralPath $ReadyFile -Encoding ASCII
            $script:ReadySignaled = $true
            Write-UpdateLog 'Updater window rendered and readiness handshake written.'
        }
        catch {
            $fatalMessage = "FATAL: Could not write readiness handshake: $($_.Exception.Message)"
            Write-BootstrapLog $fatalMessage
            Write-UpdateLog $fatalMessage
            $script:AllowClose = $true
            $window.Close()
        }
    }
})

$openBackupButton.Add_Click({
    try {
        if ($script:BackupCreated -and (Test-Path -LiteralPath $script:BackupRoot)) {
            Start-Process -FilePath 'explorer.exe' -ArgumentList ('"' + $script:BackupRoot + '"')
        }
    }
    catch {
    }
})

$viewLogButton.Add_Click({
    try {
        Start-Process -FilePath 'notepad.exe' -ArgumentList ('"' + $LogPath + '"')
    }
    catch {
    }
})

$reopenButton.Add_Click({
    if (Start-Editor) {
        $script:AllowClose = $true
        $window.Close()
    }
    else {
        Set-Status -Status 'The project could not be reopened.' -Detail 'You can close this window and reopen the .uproject manually.'
    }
})

$closeButton.Add_Click({
    $script:AllowClose = $true
    $window.Close()
})

$window.Add_Closing({
    param($sender, $eventArgs)

    if (-not $script:AllowClose) {
        $eventArgs.Cancel = $true
    }
})

$timer = New-Object System.Windows.Threading.DispatcherTimer
$timer.Interval = [TimeSpan]::FromMilliseconds(250)
$timer.Add_Tick({
    try {
        switch ($script:State) {
            'WaitingForEditor' {
                $editorStillRunning = $null -ne (Get-Process -Id $EditorPid -ErrorAction SilentlyContinue)

                if (-not $editorStillRunning) {
                    Write-UpdateLog 'Unreal Editor has exited.'
                    Set-Status -Status 'Preparing update...' -Detail 'Unreal Editor has closed. The project Content folder will be backed up before Git changes anything.'
                    $script:EditorClosedAt = [DateTime]::UtcNow
                    $script:State = 'EditorClosedDelay'
                }
            }

            'EditorClosedDelay' {
                if (([DateTime]::UtcNow - $script:EditorClosedAt).TotalMilliseconds -ge 750) {
                    Start-ContentBackup
                }
            }

            'BackingUpContent' {
                if ($null -ne $script:ActiveProcess -and $script:ActiveProcess.HasExited) {
                    Finish-ContentBackup
                }
            }

            'CheckingLocalChanges' {
                if ($null -ne $script:ActiveProcess -and $script:ActiveProcess.HasExited) {
                    Finish-GitStatus
                }
            }

            'StashingLocalChanges' {
                if ($null -ne $script:ActiveProcess -and $script:ActiveProcess.HasExited) {
                    Finish-GitStash
                }
            }

            'Pulling' {
                if ($null -ne $script:ActiveProcess -and $script:ActiveProcess.HasExited) {
                    Finish-GitPull
                }
            }

            'PreparingRestoreReset' {
                if ($null -ne $script:ActiveProcess -and $script:ActiveProcess.HasExited) {
                    Finish-GitRestoreReset
                }
            }

            'PreparingRestoreClean' {
                if ($null -ne $script:ActiveProcess -and $script:ActiveProcess.HasExited) {
                    Finish-GitRestoreClean
                }
            }

            'RestoringLocalChanges' {
                if ($null -ne $script:ActiveProcess -and $script:ActiveProcess.HasExited) {
                    Finish-GitRestore
                }
            }

            'DroppingUpdaterStash' {
                if ($null -ne $script:ActiveProcess -and $script:ActiveProcess.HasExited) {
                    Finish-GitDropStash
                }
            }

            'ReopenPending' {
                if ([DateTime]::UtcNow -ge $script:ReopenAt) {
                    if (Start-Editor) {
                        Write-UpdateLog 'Editor relaunch requested successfully.'
                        $script:AllowClose = $true
                        $timer.Stop()
                        $window.Close()
                    }
                    else {
                        Show-Failure -Status 'Update installed, but the project could not be reopened.' -Detail 'The update completed successfully. Use Reopen Project to retry, or close this window and launch the .uproject manually.' -CanRetryReopen $true
                    }
                }
            }
        }
    }
    catch {
        Show-Failure -Status 'Updater error.' -Detail "$($_.Exception.Message)" -CanRetryReopen $script:UpdateCompleted
    }
})

$timer.Start()
[void]$window.ShowDialog()
$timer.Stop()
Write-BootstrapLog 'Updater script exited.'
