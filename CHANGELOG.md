# Changelog

All notable public changes to this project are documented here.

## Compatibility audit — 2026-10-17

- Audited and tested version `0.1.1` against DayZ 1.30.
- No incompatibilities were found.
- Confirmed that the mod does not overwrite the M3S throttle configuration.
- The vanilla DayZ 1.30 `slopeCoef = 0.75` therefore remains active and may
  slightly improve the M3S uphill response compared with DayZ 1.29.
- Stationary oscillation was observed on vanilla and CarPack vehicles,
  including with engines switched off.
- The same oscillation was reproduced without Zellno Vanilla Hill Assist
  loaded, confirming that the observed behavior is not caused by this mod.
- No source, PBO, signature, Workshop package or mod version change was
  required.

## 0.1.1 — 2026-09-26

### Changed

- Revised the vanilla M3S gearbox ratios.
- Reverse and first gear now use the same `9` ratio.
- Forward ratios are now `9`, `6`, `4` and `3`.
- Other supported vehicle configurations remain unchanged.

### Notes

- No vehicle durability, suspension, steering or storage values were changed.
- No scripts, custom models or textures were added.


## 0.1.0 — 2026-09-09

Initial public release.

### Added

- Hill-climbing improvements for the vanilla M3S.
- Hill-climbing improvements for the vanilla Ada 4x4.
- Hill-climbing improvements for the vanilla Olga 24.
- Hill-climbing improvements for the vanilla Sarka 120.
- Hill-climbing improvements for the vanilla Gunter 2.
- Hill-climbing improvements for the vanilla Humvee.
- Individual torque profiles for every supported vehicle.
- M3S sound-controller adaptation for its extended physical RPM range.
- Smoother Humvee automatic clutch coupling.
- Signed PBO build and validation workflow.
- Public documentation and Workshop description.

### Notes

Versions from `0.0.1-lab` through `0.0.26-lab` were internal development and
homologation builds and were not public releases.
