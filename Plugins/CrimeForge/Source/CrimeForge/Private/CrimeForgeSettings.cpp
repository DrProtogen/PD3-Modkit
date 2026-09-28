#include "CrimeForgeSettings.h"

#include "Misc/ConfigCacheIni.h"
#include "UObject/UnrealType.h"

namespace
{
    static const TCHAR* CrimeForgeUserConfigSection = TEXT("CrimeForge.PD3");

    static const TCHAR* PD3GamePathConfigKey = TEXT("PD3GamePath");
    static const TCHAR* CopyModsToGameConfigKey = TEXT("CopyModsToGame");
    static const TCHAR* LaunchGameAfterPackingConfigKey = TEXT("LaunchGameAfterPacking");
}

UCrimeForgeSettings* UCrimeForgeSettings::Get()
{
    UCrimeForgeSettings* Settings = GetMutableDefault<UCrimeForgeSettings>();

    /* Preserve the existing custom per-user/per-project storage for the three original
     * CrimeForge settings so existing installs keep their configured PAYDAY 3 path. */
    static bool bLoadedUserSettings = false;
    if (!bLoadedUserSettings)
    {
        bLoadedUserSettings = true;

        if (GConfig)
        {
            FString SavedGamePath;
            if (GConfig->GetString(
                CrimeForgeUserConfigSection,
                PD3GamePathConfigKey,
                SavedGamePath,
                GEditorPerProjectIni))
            {
                Settings->PD3GamePath.Path = SavedGamePath;
            }

            bool bSavedCopyModsToGame = Settings->bCopyModsToGame;
            if (GConfig->GetBool(
                CrimeForgeUserConfigSection,
                CopyModsToGameConfigKey,
                bSavedCopyModsToGame,
                GEditorPerProjectIni))
            {
                Settings->bCopyModsToGame = bSavedCopyModsToGame;
            }

            int32 SavedLaunchGameAfterPacking = static_cast<int32>(Settings->LaunchGameAfterPacking);
            if (GConfig->GetInt(
                CrimeForgeUserConfigSection,
                LaunchGameAfterPackingConfigKey,
                SavedLaunchGameAfterPacking,
                GEditorPerProjectIni))
            {
                Settings->LaunchGameAfterPacking = static_cast<ECrimeForgeStartGameType>(SavedLaunchGameAfterPacking);
            }
        }
    }

    /* The original CrimeForge settings class used config=Game, so preserve saved mod checkbox
     * state the first time the unified per-user settings object is loaded. */
    if (!Settings->bMigratedLegacyCrimeForgeGameSettings)
    {
        if (GConfig)
        {
            FString LegacyModSelection;
            if (GConfig->GetString(
                TEXT("/Script/CrimeForge.CrimeForgeSettings"),
                TEXT("ModSelection"),
                LegacyModSelection,
                GGameIni))
            {
                if (FMapProperty* ModSelectionProperty = FindFProperty<FMapProperty>(
                    UCrimeForgeSettings::StaticClass(),
                    GET_MEMBER_NAME_CHECKED(UCrimeForgeSettings, ModSelection)))
                {
                    ModSelectionProperty->ImportText_InContainer(
                        *LegacyModSelection,
                        Settings,
                        Settings,
                        PPF_None);
                }
            }
        }

        Settings->bMigratedLegacyCrimeForgeGameSettings = true;
        Settings->SaveConfig();
    }

    return Settings;
}

void UCrimeForgeSettings::SaveSettings()
{
    SaveConfig();

    if (GConfig)
    {
        GConfig->SetString(
            CrimeForgeUserConfigSection,
            PD3GamePathConfigKey,
            *PD3GamePath.Path,
            GEditorPerProjectIni);

        GConfig->SetBool(
            CrimeForgeUserConfigSection,
            CopyModsToGameConfigKey,
            bCopyModsToGame,
            GEditorPerProjectIni);

        GConfig->SetInt(
            CrimeForgeUserConfigSection,
            LaunchGameAfterPackingConfigKey,
            static_cast<int32>(LaunchGameAfterPacking),
            GEditorPerProjectIni);

        GConfig->Flush(false, GEditorPerProjectIni);
    }
}
