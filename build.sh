#!/bin/bash
set -euo pipefail

PROJECT_DIR="$(
    cd "$(dirname "${BASH_SOURCE[0]}")"
    pwd
)"

SOURCE_DIR="$PROJECT_DIR/source/ZellnoVanillaHillAssist"
BUILD_ROOT="$PROJECT_DIR/build"
BUILD_MOD="$BUILD_ROOT/@ZellnoVanillaHillAssist"
BUILD_ADDONS="$BUILD_MOD/addons"
BUILD_KEYS="$BUILD_MOD/keys"

DAYZ_TOOLS="$HOME/.local/share/Steam/steamapps/common/DayZ Tools/Bin"
FILEBANK="$DAYZ_TOOLS/PboUtils/FileBank.exe"
BANKREV="$DAYZ_TOOLS/PboUtils/BankRev.exe"
DSSIGNFILE="$DAYZ_TOOLS/DsUtils/DSSignFile.exe"
DSCHECK="$DAYZ_TOOLS/DsUtils/DSCheckSignatures.exe"

PRIVATE_KEY="$HOME/dayz/modding/keys/Zellno/Zellno.biprivatekey"
PUBLIC_KEY="$HOME/dayz/modding/keys/Zellno/Zellno.bikey"

SERVER_MOD="$HOME/dayz/server/@ZellnoVanillaHillAssist"
SERVER_KEYS="$HOME/dayz/server/keys"
INSTALL_BACKUPS="$PROJECT_DIR/backups/install"

EXPECTED_SOURCE_HASH="64d73a875239800f495137b69e9a8740c84a3562590e8469c47dda59321f423d"
ACTUAL_SOURCE_HASH="$(
    sha256sum "$SOURCE_DIR/config.cpp" |
    awk '{print $1}'
)"

if [ "$ACTUAL_SOURCE_HASH" != "$EXPECTED_SOURCE_HASH" ]; then
    echo "O config.cpp mudou depois da validação." >&2
    echo "Esperado: $EXPECTED_SOURCE_HASH" >&2
    echo "Atual:    $ACTUAL_SOURCE_HASH" >&2
    exit 1
fi

for required in     "$SOURCE_DIR/config.cpp"     "$PROJECT_DIR/mod.cpp"     "$PROJECT_DIR/meta.cpp"     "$FILEBANK"     "$BANKREV"     "$DSSIGNFILE"     "$DSCHECK"     "$PRIVATE_KEY"     "$PUBLIC_KEY"
do
    if [ ! -f "$required" ]; then
        echo "Arquivo obrigatório não encontrado:" >&2
        echo "$required" >&2
        exit 1
    fi
done

if [ -e "$BUILD_MOD" ]; then
    rm -rf -- "$BUILD_MOD"
fi

mkdir -p "$BUILD_ADDONS" "$BUILD_KEYS"

wine "$FILEBANK"     -property prefix=ZellnoVanillaHillAssist     -dst "$(winepath -w "$BUILD_ADDONS")"     "$(winepath -w "$SOURCE_DIR")"

PBO="$BUILD_ADDONS/ZellnoVanillaHillAssist.pbo"

if [ ! -f "$PBO" ]; then
    echo "O FileBank não criou o PBO esperado:" >&2
    echo "$PBO" >&2
    exit 1
fi

wine "$DSSIGNFILE"     "$(winepath -w "$PRIVATE_KEY")"     "$(winepath -w "$PBO")"

SIGNATURE="$PBO.Zellno.bisign"

if [ ! -f "$SIGNATURE" ]; then
    echo "A assinatura esperada não foi criada:" >&2
    echo "$SIGNATURE" >&2
    exit 1
fi

cp "$PUBLIC_KEY" "$BUILD_KEYS/"
cp "$PROJECT_DIR/mod.cpp" "$BUILD_MOD/"
cp "$PROJECT_DIR/meta.cpp" "$BUILD_MOD/"
cp "$PROJECT_DIR/README.md" "$BUILD_MOD/"

VERIFY_OUTPUT="$(
    wine "$DSCHECK"         "$(winepath -w "$BUILD_ADDONS")"         "$(winepath -w "$(dirname "$PUBLIC_KEY")")"         2>&1
)"

echo "$VERIFY_OUTPUT"

if ! grep -q 'is OK' <<< "$VERIFY_OUTPUT"; then
    echo "Falha na validação da assinatura." >&2
    exit 1
fi

echo
echo "Propriedades do PBO:"

wine "$BANKREV"     -properties     "$(winepath -w "$PBO")"

echo
echo "Hashes do build:"

sha256sum "$PBO" "$SIGNATURE"

echo
echo "Build validado:"
echo "$BUILD_MOD"

if [ "${1:-}" != "--install" ]; then
    echo
    echo "Nenhuma instalação foi realizada."
    echo "Use ./build.sh --install somente após aprovação."
    exit 0
fi

if pgrep -x DayZServer >/dev/null; then
    echo "O DayZServer está rodando." >&2
    echo "Encerre-o antes da instalação." >&2
    exit 1
fi

mkdir -p "$INSTALL_BACKUPS" "$SERVER_KEYS"

if [ -e "$SERVER_MOD" ]; then
    TIMESTAMP="$(date '+%Y%m%d-%H%M%S')"
    BACKUP="$INSTALL_BACKUPS/@ZellnoVanillaHillAssist-$TIMESTAMP"

    mv "$SERVER_MOD" "$BACKUP"

    echo "Versão anterior preservada em:"
    echo "$BACKUP"
fi

cp -a "$BUILD_MOD" "$SERVER_MOD"
cp "$PUBLIC_KEY" "$SERVER_KEYS/Zellno.bikey"

echo
echo "Build instalado em:"
echo "$SERVER_MOD"
