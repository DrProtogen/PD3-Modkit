# PD3-Modkit

PD3-Modkit is a PAYDAY 3 modding project built around a custom **UE5-PD3 Editor** and **Suzie**!

The custom editor is designed to work with PAYDAY 3 cooked content directly from the user's installed game, while Suzie reconstructs PAYDAY 3 classes and reflection data from a locally generated Jmap.

The repository does **not** include PAYDAY 3 game data, the Jmap, or the Wwise third-party SDKs. These must be supplied locally by each user.

## Requirements

Before opening the project, you will need:

- **PD3-Modkit**
- **UE5-PD3 Editor**: https://github.com/NadzW/UnrealEngine-PD3Compatibility
- A local installation of **PAYDAY 3**
- A valid PAYDAY 3 **AES key**
- **FModel**: https://fmodel.app
- **Jmap**: https://github.com/trumank/jmap
- **Wwise**: https://www.audiokinetic.com/en/wwise/

> The modkit is intended to be opened with the custom UE5-PD3 Editor, not a standard Epic Games Launcher build of Unreal Engine.

## Setup

### 1. Install the UE5-PD3 Editor

Install or build the custom **UE5-PD3 Editor** from:

https://github.com/NadzW/UnrealEngine-PD3Compatibility

Then associate the PD3-Modkit `.uproject` with it.

The custom editor contains the compatibility changes needed to:

- Mount PAYDAY 3 retail IoStore containers
- Load PAYDAY 3 cooked assets in the editor
- Display retail assets in the Content Browser
- Work with Suzie-generated PAYDAY 3 classes
- Open PAYDAY 3 cooked levels and assets that stock Unreal Editor cannot handle

## 2. Configure PAYDAY 3

When the project is opened for the first time, the custom editor will ask for:

- **PAYDAY 3 Installation Directory**
- **AES Key**

These values are stored in the project's editor user settings.

After entering valid values, restart the editor when prompted.

The game path should point to the PAYDAY 3 installation root, for example:

```text
C:/Program Files (x86)/Steam/steamapps/common/PAYDAY3
```

The editor uses this path to locate:

```text
PAYDAY3/Content/Paks
```

If either the game path or AES key is missing or invalid, PAYDAY 3 retail assets will not be available in the Content Browser.

## 3. Generate the PAYDAY 3 Jmap

PD3-Modkit includes a modified `jmap_dumper.exe` under:

```text
Tools/jmap_dumper.exe
```

The project root also contains:

```text
GenerateJmap.bat
```

Run `GenerateJmap.bat` to generate the Jmap automatically.

The script will:

1. Launch PAYDAY 3 through Steam if it is not already running.
2. Wait for the PAYDAY 3 Unreal Engine process.
3. Get the game's process ID.
4. Run:

```text
.\Tools\jmap_dumper.exe --pid <PID> --engine-version 5.5 --case-preserving --all -vv PD3.jmap
```

5. Move the completed Jmap to:

```text
Content/DynamicClasses/PD3.jmap
```

If PAYDAY 3 is already running, the script uses the existing process instead of launching another copy.

If you are using a non-Steam version of the game, start PAYDAY 3 manually before running the batch file.

Suzie uses `PD3.jmap` to reconstruct PAYDAY 3 reflection data and generate the editor-side class definitions required by cooked assets.

The Jmap should match the version of PAYDAY 3 you are currently using.

Using an outdated Jmap after a game update may result in:

- Missing classes
- Incorrect properties
- Serialization mismatches
- Cooked assets failing to load correctly

The upstream Jmap project is available at:

https://github.com/trumank/jmap
## 4. Extract `AssetRegistry.bin`

Use **FModel** to extract the current PAYDAY 3:

https://fmodel.app

Extract:

```text
AssetRegistry.bin
```

Place it in the root of the modkit project:

```text
PD3-Modkit/
├── AssetRegistry.bin
├── Content/
├── Config/
├── Plugins/
└── PD3-Modkit.uproject
```

The custom editor uses this registry to discover the PAYDAY 3 cooked assets mounted from the retail installation.

The `AssetRegistry.bin` and Jmap should come from the **same game version**.

## 5. Install the Wwise Third-Party SDKs

The Wwise plugin is included with the project, but the required third-party SDK files are not.

Download/install Wwise from:

https://www.audiokinetic.com/en/wwise/

Install the required Wwise SDK components into:

```text
PD3-Modkit/
└── Plugins/
    └── Wwise/
```

The installed SDK must match what the included Wwise plugin expects.

If the required third-party files are missing, the Wwise modules may fail to compile or load.

## 6. Open the Project

Once setup is complete, the project should look roughly like this:

```text
PD3-Modkit/
│
├── AssetRegistry.bin
├── PD3-Modkit.uproject
├── GenerateJmap.bat
│
├── Tools/
│   └── jmap_dumper.exe
│
├── Config/
│
├── Content/
│   └── DynamicClasses/
│       └── PD3.jmap
│
└── Plugins/
    ├── Suzie/
    └── Wwise/
        └── <installed Wwise third-party SDK files>
```

Open the `.uproject` using the custom **UE5-PD3 Editor**.

On startup:

1. The editor mounts the configured PAYDAY 3 retail containers.
2. `AssetRegistry.bin` provides the retail asset metadata.
3. Suzie reads the current Jmap and reconstructs PAYDAY 3 class information.
4. PAYDAY 3 assets become available in the Content Browser.

The original PAYDAY 3 installation remains separate from the modkit. Retail assets are loaded from the installed game and are not copied into the project as editable source assets.

# Updating After a PAYDAY 3 Update

After a PAYDAY 3 update, you normally only need to replace two files:

```text
AssetRegistry.bin
Jmap
```

## Update Steps

After a PAYDAY 3 update:

1. Run:

```text
GenerateJmap.bat
```

This replaces:

```text
Content/DynamicClasses/PD3.jmap
```

with a fresh Jmap generated from the updated game.

2. Extract the new `AssetRegistry.bin` using FModel.
3. Replace:

```text
PD3-Modkit/AssetRegistry.bin
```

4. Launch the UE5-PD3 Editor again.

Suzie can then regenerate/update the PAYDAY 3 class data from the new Jmap and registry.

You do **not** need to manually replace the Suzie-generated headers individually.

The normal update process is:

```text
PAYDAY 3 updates
        ↓
Run GenerateJmap.bat
        +
Extract new AssetRegistry.bin
        ↓
Launch UE5-PD3
        ↓
Suzie updates generated class data
```
## Files That Normally Do Not Need Replacing

You should not normally need to replace these after every game update:

- UE5-PD3 Editor
- Suzie plugin
- Wwise SDK
- Modkit project files
- Suzie-generated headers individually

These only need updating if a PAYDAY 3 update introduces an engine-level or Suzie compatibility change.

# Troubleshooting

## PAYDAY 3 assets do not appear in the Content Browser

Check that:

- The PAYDAY 3 install path is configured correctly
- The AES key is valid
- `AssetRegistry.bin` exists in the project root
- The Jmap exists in `Content/DynamicClasses`
- The Jmap and `AssetRegistry.bin` match the same PAYDAY 3 version

## Wwise modules fail to load or compile

Check that the required Wwise third-party SDK files are installed under:

```text
Plugins/Wwise/
```

## Plugin modules fail to load even though the plugin and DLLs are present

If Unreal reports that a plugin module cannot be found or loaded, for example:

```text
Plugin 'Wwise' failed to load because module 'Wwise' could not be found.
```

and the plugin folder and DLLs are already present, the plugin may have stale build artifacts from a different editor build.

Close Unreal Editor, then delete the `Binaries` and `Intermediate` folders for the affected plugin or plugins. For example:

```text
Plugins/Wwise/Binaries/
Plugins/Wwise/Intermediate/

Plugins/Suzie/Binaries/
Plugins/Suzie/Intermediate/

Plugins/CrimeForge/Binaries/
Plugins/CrimeForge/Intermediate/
```

Then open the PD3-Modkit solution (`.sln`) and build the project using the custom UE5-PD3 Editor configuration.

This regenerates the plugin binaries and module manifests against the current editor build. After the build completes, reopen the project.

You only need to remove the generated folders for the plugins that are failing to load.

## Assets fail to load after a game update

Regenerate and replace both:

```text
AssetRegistry.bin
Jmap
```

before assuming the editor or generated headers need to be updated.
