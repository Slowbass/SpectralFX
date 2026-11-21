#!/usr/bin/env bash
# Régénère le C++ à partir du code Faust (dsp/resonateur.dsp).
# Usage : scripts/generate.sh [chemin/vers/faust] [dossier des bibliothèques Faust]
set -euo pipefail
cd "$(dirname "$0")/.."

FAUST="${1:-faust}"
LIBS="${2:-}"
INC=()
if [ -n "$LIBS" ]; then INC=(-I "$LIBS"); fi

ARCH="$(mktemp)"
printf '<<includeIntrinsic>>\n<<includeclass>>\n' > "$ARCH"

"$FAUST" "${INC[@]}" -double -lang cpp -a "$ARCH" -cn FaustResonateur -scn FaustBase -o generated/FaustResonateur.h dsp/resonateur.dsp

rm -f "$ARCH"
echo "C++ régénéré dans generated/ (Faust $("$FAUST" --version | head -1))"
