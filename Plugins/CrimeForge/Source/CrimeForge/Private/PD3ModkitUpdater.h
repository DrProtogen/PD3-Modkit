#pragma once

#include "CoreMinimal.h"

/**
 * Editor-side updater for the official PD3 Modkit Git repository.
 *
 * Update checks use Git rather than the GitHub API, so the updater compares the
 * current checkout with the official remote branch after a fetch. Uncommitted
 * working-tree changes do not affect version detection.
 *
 * When the user accepts an update, Unreal saves dirty packages and launches a
 * visible PowerShell/WPF helper before closing. The helper waits for the editor
 * process to exit, creates a full safety backup of the project's Content folder,
 * temporarily stashes tracked and untracked Git changes, performs a fast-forward
 * update, restores those local changes, and then reopens the same .uproject with
 * the same Unreal Editor executable. Local commits are never rewritten.
 */
class FPD3ModkitUpdater
{
public:
    /** Start the delayed, silent startup update check. */
    static void Initialize();

    /** Remove any pending startup callback and prevent late async UI work. */
    static void Shutdown();

    /**
     * Check the canonical PD3 Modkit remote for updates.
     *
     * @param bUserInitiated When true, "up to date" and error messages are
     * shown to the user. Startup checks stay silent unless an update is found.
     */
    static void CheckForUpdates(bool bUserInitiated);

private:
    static bool HandleStartupCheck(float DeltaTime);
};
