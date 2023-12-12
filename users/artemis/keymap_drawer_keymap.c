#include "artemis.h"

#define LAYOUT_split_3x5_3(...) LAYOUT(__VA_ARGS__)

// clang-format on
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    ARTEMIS_DEFAULT_LAYERS
};
