#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "CrimeForgeSettings.generated.h"

UENUM()
enum class ECrimeForgeStartGameType : uint8 {
    NONE = 0 UMETA(DisplayName = "Do not launch"),
    STEAM = 1 UMETA(DisplayName = "Steam"),
    MICROSOFT_STORE = 2 UMETA(DisplayName = "Microsoft Store / Xbox"),
    EPIC_GAMES = 3 UMETA(DisplayName = "Epic Games Store"),
};

/**
 * Single Project Settings object for all CrimeForge configuration.
 *
 * It is registered manually under Project Settings -> Plugins -> CrimeForge so the editor shows
 * one CrimeForge page with normal expandable categories.
 */
UCLASS(config = EditorPerProjectUserSettings)
class CRIMEFORGE_API UCrimeForgeSettings : public UObject
{
    GENERATED_BODY()

public:
    static UCrimeForgeSettings* Get();
    void SaveSettings();

    /* General ------------------------------------------------------------------------------ */

    UPROPERTY(EditAnywhere, Config, Category = "General|PAYDAY 3", meta = (DisplayName = "PAYDAY 3 Game Path"))
    FDirectoryPath PD3GamePath;

    UPROPERTY(EditAnywhere, Config, Category = "General|PAYDAY 3", meta = (DisplayName = "Copy Mods To Game"))
    bool bCopyModsToGame = false;

    UPROPERTY(EditAnywhere, Config, Category = "General|PAYDAY 3", meta = (DisplayName = "Launch Game After Packing"))
    ECrimeForgeStartGameType LaunchGameAfterPacking = ECrimeForgeStartGameType::NONE;

    /* Internal state ----------------------------------------------------------------------- */

    UPROPERTY(Config)
    TMap<FString, bool> ModSelection;

    UPROPERTY(Config)
    bool bMigratedLegacyCrimeForgeGameSettings = false;
};
