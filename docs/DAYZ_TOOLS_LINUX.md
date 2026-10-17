# DayZ Tools on Linux with Wine

This document records the Linux/Wine procedure used to inspect DayZ PBO files
while maintaining Zellno Vanilla Hill Assist.

It exists because two easy-to-repeat mistakes produce misleading Wine or
BankRev errors:

1. Passing Linux paths such as `/home/user/...` directly to a Windows DayZ
   Tools executable.
2. Copying only the final command while variables such as `BANKREV`, `PBO`
   or `DESTINATION` are undefined in the current shell.

## Rules

- Run the complete block, not only the last three commands.
- Use `set -euo pipefail` so undefined variables abort immediately.
- Create the destination directory before calling BankRev.
- Convert every input and output path supplied to a Windows executable with
  `winepath -w`.
- BankRev extraction syntax is:

  ```text
  BankRev.exe -f <destination-folder> <archive.pbo>
  ```

## Complete extraction example

```bash
(
    set -euo pipefail

    TOOLS="$HOME/.local/share/Steam/steamapps/common/DayZ Tools/Bin"
    BANKREV="$TOOLS/PboUtils/BankRev.exe"

    PBO="$HOME/.local/share/Steam/steamapps/common/DayZ/Addons/vehicles_wheeled.pbo"
    DESTINATION="$HOME/dayz/tmp/vehicles_wheeled-extracted"

    test -f "$BANKREV"
    test -f "$PBO"
    test ! -e "$DESTINATION"

    mkdir -p "$DESTINATION"

    BANKREV_WIN="$(winepath -w "$BANKREV")"
    PBO_WIN="$(winepath -w "$PBO")"
    DESTINATION_WIN="$(winepath -w "$DESTINATION")"

    wine "$BANKREV_WIN"         -f "$DESTINATION_WIN"         "$PBO_WIN"

    find "$DESTINATION" -maxdepth 4 -type f -print
)
```

## Converting config.bin to text

```bash
(
    set -euo pipefail

    TOOLS="$HOME/.local/share/Steam/steamapps/common/DayZ Tools/Bin"
    CFGCONVERT="$TOOLS/CfgConvert/CfgConvert.exe"

    SOURCE_BIN="$HOME/dayz/tmp/vehicles_wheeled-extracted/vehicles_wheeled/config.bin"
    TARGET_CPP="$HOME/dayz/tmp/vehicles_wheeled-config.cpp"

    test -f "$CFGCONVERT"
    test -f "$SOURCE_BIN"
    test ! -e "$TARGET_CPP"

    CFGCONVERT_WIN="$(winepath -w "$CFGCONVERT")"
    SOURCE_BIN_WIN="$(winepath -w "$SOURCE_BIN")"
    TARGET_CPP_WIN="$(winepath -w "$TARGET_CPP")"

    wine "$CFGCONVERT_WIN"         -txt         -dst "$TARGET_CPP_WIN"         "$SOURCE_BIN_WIN"

    test -s "$TARGET_CPP"
    file "$TARGET_CPP"
    sha256sum "$SOURCE_BIN" "$TARGET_CPP"
)
```

The extracted directory layout can vary with the PBO prefix. If the expected
`config.bin` path is not present, locate it without modifying anything:

```bash
find "$DESTINATION" -type f -iname 'config.bin' -print
```

## Error reference

### `unknown command /home/...`

BankRev received a Linux path directly and interpreted the leading slash as a
command switch. Convert the destination and PBO paths with `winepath -w`.

### `ShellExecuteEx failed: File not found`

The executable variable was empty, undefined in a different shell, or pointed
to a missing file. Run the complete block and validate it first with
`test -f "$BANKREV"` or `test -f "$CFGCONVERT"`.

### `unable to open Z:\\...`

Confirm that the destination directory already exists and that its path was
converted with `winepath -w`.

## Safety

Extraction and conversion should write only below a dedicated temporary
directory such as `$HOME/dayz/tmp`. They must not overwrite the mod source,
the active server package, the Steam Workshop copy or hosted-server files.
