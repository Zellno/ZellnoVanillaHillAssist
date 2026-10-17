# Zellno Vanilla Hill Assist

Zellno Vanilla Hill Assist is a lightweight configuration mod for DayZ
that improves the hill-climbing performance of vanilla vehicles.

The goal is not to turn every vehicle into a race car. Each vehicle keeps
its own character, drivetrain and general behavior while receiving enough
usable torque to handle steep roads more naturally.

## Supported vehicles

- M3S Covered
- Ada 4x4
- Olga 24
- Sarka 120
- Gunter 2
- Humvee

The configuration is applied to the corresponding vanilla base classes and
therefore also affects their vanilla color variants.

## Main features

- Better performance on steep roads.
- More useful torque through the working RPM range.
- Individual tuning for each supported vehicle.
- Original vehicle identity and drivetrain preserved.
- Vanilla sound assets retained.
- No scripts.
- No custom models or textures.
- No changes to storage capacity or vehicle durability.
- Existing vehicles receive the configuration after the mod is loaded.
- No economy wipe is required.

## Official test route

Development was validated on the steep road leaving Mogilevka in Chernarus.

The sign near the hardest section of the climb is used as the principal
homologation point. Every supported vanilla vehicle was driven through this
route and evaluated for:

- ability to continue climbing;
- speed near the sign;
- gear behavior;
- low and medium RPM response;
- reverse behavior;
- maximum speed;
- handling and controllability;
- engine sound behavior.

## Installation

1. Copy `@ZellnoVanillaHillAssist` to the DayZ server directory.
2. Copy `Zellno.bikey` from the mod's `keys` directory to the server `keys`
   directory.
3. Add `@ZellnoVanillaHillAssist` to the server `-mod` parameter.
4. Add the mod to the server's Steam Workshop collection.
5. Restart the server.

This is a client-and-server mod. Players must load it when joining a server
that uses it.

## Compatibility

Zellno Vanilla Hill Assist 0.1.1 was audited and tested against DayZ 1.30.
No incompatibilities were found and no rebuild of the published PBO was
required.

The DayZ 1.30 vanilla M3S adds `slopeCoef = 0.75` to its throttle
configuration. This mod does not overwrite the M3S throttle configuration,
so the official value remains active. As a result, the M3S may have slightly
better uphill response in DayZ 1.30 than it had in DayZ 1.29, in addition to
the existing Hill Assist tuning.

During testing on 2026-10-17, stationary vehicle oscillation was observed on
vanilla and CarPack vehicles. The same behavior was reproduced without
Zellno Vanilla Hill Assist loaded, including with engines switched off.
Therefore, this observed DayZ 1.30 vehicle behavior is not caused by this mod.

The mod changes vanilla vehicle simulation configuration.

Another mod that overwrites the same `SimulationModule`, engine torque curve,
clutch or gearbox configuration may conflict with it. Load order cannot
guarantee compatibility when two mods replace the same vehicle properties.

The mod does not modify CarPack vehicle classes.

## Building

The included `build.sh` is the maintainer's Linux and Wine build workflow.
It expects an installed copy of DayZ Tools and locally configured signing
keys. Local paths may need adjustment for another development environment.

For the verified BankRev and CfgConvert extraction workflow, including
`winepath` conversion and recurring error diagnostics, see
[DayZ Tools on Linux with Wine](docs/DAYZ_TOOLS_LINUX.md).

Private signing keys are never included in this repository.

## Version

Current public release: `0.1.1`.

The earlier `0.0.x-lab` versions were private development builds used for
vehicle-by-vehicle testing.

## License

The original source code and documentation in this repository are licensed
under the MIT License. See [LICENSE](LICENSE) and
[THIRD_PARTY.md](THIRD_PARTY.md).

DayZ and all original game assets are property of Bohemia Interactive.
This project is unofficial and is not affiliated with or endorsed by
Bohemia Interactive.
