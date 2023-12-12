#pragma once

#include "artemis.h"

#ifdef OS_DETECTION_ENABLE
#include "os_detection.h"
os_variant_t current_os;
#elif
typedef enum {
    OS_MACOS,
    OS_WINDOWS,
    OS_LINUX
} os_variant_t;
#endif


#define SWITCH_OS(macos, windows, linux) \
    switch (current_os) {                \
        case OS_MACOS:                   \
            macos;                       \
            break;                       \
        case OS_WINDOWS:                 \
            windows;                     \
            break;                      \
        case OS_LINUX:                   \
            linux;                       \
            break;                       \
        default:                         \
            break;                       \
    }

uint16_t get_os_modifier(uint16_t modifier);

void set_os(os_variant_t os);
