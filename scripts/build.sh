#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

make moonlander:artemis \
  && $SCRIPT_DIR/generate_keymap_svg.sh \
  && $SCRIPT_DIR/generate_keymap_svg.sh --gaming
