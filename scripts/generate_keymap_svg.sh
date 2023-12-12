#!/bin/bash

CWD=$(pwd)
KEYMAP_YAML=$CWD/artemis_keymap.yaml
CONFIG=$CWD/keymap-drawer/config.yaml
OUTPUT=$CWD/keymap-drawer/artemis_keymap.svg
KEYMAP_C=$CWD/users/artemis/artemis.c

cd ~/keymap-drawer
KEYMAP="poetry run keymap"

ALL_LAYERS='MAIN GAMING GAMING_NUM NAV NUM_SYM MISC FUNC MACRO'
SELECT_LAYERS='MAIN NAV NUM_SYM MISC FUNC MACRO'
if [ "$1" == "--gaming" ]; then
    SELECT_LAYERS='GAMING GAMING_NUM MISC FUNC'
    OUTPUT=$CWD/keymap-drawer/artemis_keymap_gaming.svg
fi

qmk c2json $KEYMAP_C | \
    $KEYMAP -c $CONFIG parse \
        --layer-names $ALL_LAYERS \
        --columns 10 \
        --qmk-keymap-json \
        - >$KEYMAP_YAML

if [ "$1" != "--gaming" ]; then
qmk c2json $KEYMAP_C | \
    $CWD/scripts/generate_keymap_combos.py \
        --layer-names $ALL_LAYERS \
        --drawer-config $CONFIG \
        --keymap-source $KEYMAP_C >> $KEYMAP_YAML
fi

$KEYMAP -c $CONFIG draw \
    --select-layers $SELECT_LAYERS \
    --qmk-keyboard corne_rotated \
    --qmk-layout LAYOUT_split_3x5_3 \
    $KEYMAP_YAML \
    >$OUTPUT

rm $KEYMAP_YAML

echo "Generated $OUTPUT"
cd -
