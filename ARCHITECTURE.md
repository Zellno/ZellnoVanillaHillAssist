# Architecture

Zellno Vanilla Hill Assist is a configuration-only DayZ mod.

## Structure

- `source/ZellnoVanillaHillAssist/config.cpp`
  - declares the addon through `CfgPatches`;
  - overrides selected vanilla vehicle classes;
  - adjusts vehicle simulation properties;
  - contains the approved M3S sound-controller adaptation.
- `mod.cpp`
  - public launcher metadata.
- `meta.cpp`
  - Steam Workshop publication metadata.
- `build.sh`
  - local build, signing, validation and optional installation workflow.

## Design principles

- No runtime scripts.
- No scheduled update loops.
- No custom network messages.
- No changes to Central Economy files.
- No modification of player-owned vehicle persistence data.
- No copied models, textures or audio samples.
- Each vehicle is tuned independently.
- Approved vehicle configurations remain isolated from later changes.

## Runtime behavior

DayZ merges the configuration patch while loading the mod. Supported vanilla
vehicle classes then use the adjusted simulation values.

Because the original classnames are retained, existing vehicles and their
attachments remain the same persistent entities.
