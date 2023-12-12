#include "extensions.h"

uint16_t map_key_index(uint16_t key_index) {
    const int half = 42;

    int off = key_index % 5;
    if (key_index < 5) return off;
    if (key_index < 10) return half + 2 + off;
    if (key_index < 15) return 7 + off;
    if (key_index < 20) return half + 9 + off;
    if (key_index < 25) return 14 + off;
    if (key_index < 30) return half + 16 + off;
    return key_index;
}
