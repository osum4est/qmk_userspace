#define MOONLANDER_LAYOUT_WRAPPER_MIDDLE(                  \
    k0A, k0B, k0C, k0D, k0E,      k0F, k0G, k0H, k0I, k0J, \
    k1A, k1B, k1C, k1D, k1E,      k1F, k1G, k1H, k1I, k1J, \
    k2A, k2B, k2C, k2D, k2E,      k2F, k2G, k2H, k2I, k2J, \
              k3C, k3D, k3E,      k3F, k3G, k3H            \
) LAYOUT(                                                                                                                                   \
    _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, \
    _______, k0A,     k0B,     k0C,     k0D,     k0E,     _______,           _______, k0F,     k0G,     k0H,     k0I,     k0J,     _______, \
    _______, k1A,     k1B,     k1C,     k1D,     k1E,     _______,           _______, k1F,     k1G,     k1H,     k1I,     k1J,     _______, \
    _______, k2A,     k2B,     k2C,     k2D,     k2E,                                 k2F,     k2G,     k2H,     k2I,     k2J,     _______, \
    _______, _______, _______, _______, k3C,              _______,           _______,          k3H,     _______, _______, _______, _______, \
                                        k3D,     k3E,     _______,           _______, k3F,     k3G                                          \
)

#define MOONLANDER_LAYOUT_WRAPPER_CORNER(                  \
    k0A, k0B, k0C, k0D, k0E,      k0F, k0G, k0H, k0I, k0J, \
    k1A, k1B, k1C, k1D, k1E,      k1F, k1G, k1H, k1I, k1J, \
    k2A, k2B, k2C, k2D, k2E,      k2F, k2G, k2H, k2I, k2J, \
              k3C, k3D, k3E,      k3F, k3G, k3H            \
) LAYOUT(                                                                                                                                   \
    k0A,     k0B,     k0C,     k0D,     k0E,     _______, _______,           _______, _______, k0F,     k0G,     k0H,     k0I,     k0J,     \
    k1A,     k1B,     k1C,     k1D,     k1E,     _______, _______,           _______, _______, k1F,     k1G,     k1H,     k1I,     k1J,     \
    k2A,     k2B,     k2C,     k2D,     k2E,     _______, _______,           _______, _______, k2F,     k2G,     k2H,     k2I,     k2J,     \
    _______, _______, _______, k3C,     k3D,     k3E,                                 k3F,     k3G,     k3H,     _______, _______, _______, \
    _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______, \
                                        _______, _______, _______,           _______, _______, _______                                      \
)

#define MOONLANDER_LAYOUT_WRAPPER_EX_CORNER(               \
    k0A, k0B, k0C, k0D, k0E,      k0F, k0G, k0H, k0I, k0J, \
    k1A, k1B, k1C, k1D, k1E,      k1F, k1G, k1H, k1I, k1J, \
    k2A, k2B, k2C, k2D, k2E,      k2F, k2G, k2H, k2I, k2J, \
              k3C, k3D, k3E,      k3F, k3G, k3H,           \
                        k4E,      k4F                      \
) LAYOUT(                                                                                                                                   \
    k0A,     k0B,     k0C,     k0D,     k0E,     _______, _______,           _______, _______, k0F,     k0G,     k0H,     k0I,     k0J,     \
    k1A,     k1B,     k1C,     k1D,     k1E,     _______, _______,           _______, _______, k1F,     k1G,     k1H,     k1I,     k1J,     \
    k2A,     k2B,     k2C,     k2D,     k2E,     _______, _______,           _______, _______, k2F,     k2G,     k2H,     k2I,     k2J,     \
    _______, _______, _______, k3C,     k3D,     k3E,                                 k3F,     k3G,     k3H,     _______, _______, _______, \
    _______, _______, _______, _______, _______,          k4E,               k4F,              _______, _______, _______, _______, _______, \
                                        _______, _______, _______,           _______, _______, _______                                      \
)

#define MOONLANDER_ALL_LEDS(                                                   \
    k0A, k0B, k0C, k0D, k0E, k0F, k0G,      k0H, k0I, k0J, k0K, k0L, k0M, k0N, \
    k1A, k1B, k1C, k1D, k1E, k1F, k1G,      k1H, k1I, k1J, k1K, k1L, k1M, k1N, \
    k2A, k2B, k2C, k2D, k2E, k2F, k2G,      k2H, k2I, k2J, k2K, k2L, k2M, k2N, \
    k3A, k3B, k3C, k3D, k3E, k3F,                k3I, k3J, k3K, k3L, k3M, k3N, \
    k4A, k4B, k4C, k4D, k4E,      k4G,      k4H,      k4J, k4K, k4L, k4M, k4N, \
                        k5E, k5F, k5G,      k5H, k5I, k5J                      \
) {                          \
    k0A, k1A, k2A, k3A, k4A, \
    k0B, k1B, k2B, k3B, k4B, \
    k0C, k1C, k2C, k3C, k4C, \
    k0D, k1D, k2D, k3D, k4D, \
    k0E, k1E, k2E, k3E, k4E, \
    k0F, k1F, k2F, k3F,      \
    k0G, k1G, k2G,           \
                             \
    k5E, k5F, k5G, k4G,      \
                             \
    k0N, k1N, k2N, k3N, k4N, \
    k0M, k1M, k2M, k3M, k4M, \
    k0L, k1L, k2L, k3L, k4L, \
    k0K, k1K, k2K, k3K, k4K, \
    k0J, k1J, k2J, k3J, k4J, \
    k0I, k1I, k2I, k3I,      \
    k0H, k1H, k2H,           \
                             \
    k5J, k5I, k5H, k4H,      \
}

#define MOONLANDER_LED_LAYOUT_WRAPPER_MIDDLE(              \
    k1B, k1C, k1D, k1E, k1F,      k1I, k1J, k1K, k1L, k1M, \
    k2B, k2C, k2D, k2E, k2F,      k2I, k2J, k2K, k2L, k2M, \
    k3B, k3C, k3D, k3E, k3F,      k3I, k3J, k3K, k3L, k3M, \
              k4E, k5E, k5F,      k5I, k5J, k4J            \
) {                          \
    ___, ___, ___, ___, ___, \
    ___, k1B, k2B, k3B, ___, \
    ___, k1C, k2C, k3C, ___, \
    ___, k1D, k2D, k3D, ___, \
    ___, k1E, k2E, k3E, k4E, \
    ___, k1F, k2F, k3F,      \
    ___, ___, ___,           \
                             \
    k5E, k5F, ___, ___,      \
                             \
    ___, ___, ___, ___, ___, \
    ___, k1M, k2M, k3M, ___, \
    ___, k1L, k2L, k3L, ___, \
    ___, k1K, k2K, k3K, ___, \
    ___, k1J, k2J, k3J, k4J, \
    ___, k1I, k2I, k3I,      \
    ___, ___, ___,           \
                             \
    k5J, k5I, ___, ___,      \
}

#define MOONLANDER_LED_LAYOUT_WRAPPER_CORNER(              \
    k1B, k1C, k1D, k1E, k1F,      k1I, k1J, k1K, k1L, k1M, \
    k2B, k2C, k2D, k2E, k2F,      k2I, k2J, k2K, k2L, k2M, \
    k3B, k3C, k3D, k3E, k3F,      k3I, k3J, k3K, k3L, k3M, \
              k4D, k4E, k4F,      k4I, k4J, k4K            \
) {                          \
    k1B, k2B, k3B, ___, ___, \
    k1C, k2C, k3C, ___, ___, \
    k1D, k2D, k3D, ___, ___, \
    k1E, k2E, k3E, k4D, ___, \
    k1F, k2F, k3F, k4E, ___, \
    ___, ___, ___, k4F,      \
    ___, ___, ___,           \
                             \
    ___, ___, ___, ___,      \
                             \
    k1M, k2M, k3M, ___, ___, \
    k1L, k2L, k3L, ___, ___, \
    k1K, k2K, k3K, ___, ___, \
    k1J, k2J, k3J, k4K, ___, \
    k1I, k2I, k3I, k4J, ___, \
    ___, ___, ___, k4I,      \
    ___, ___, ___,           \
                             \
    ___, ___, ___, ___       \
}
