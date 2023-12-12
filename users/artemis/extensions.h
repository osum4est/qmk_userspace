#pragma once

#include QMK_KEYBOARD_H

// OS shortcuts
typedef struct {
    uint16_t mac;
    uint16_t win;
    uint16_t lin;
} os_shortcut_action_t;

#define EX_OS_SHORTCUT(mac, win, lin) \
    { .type = EX_OS_SHORTCUT, .data = { .shortcut_action = {mac, win, lin} } }

// Hold tap
typedef struct {
    uint16_t enable_key;
    uint16_t mac_hold;
    uint16_t mac_tap;
    uint16_t win_hold;
    uint16_t win_tap;
    uint16_t nix_hold;
    uint16_t nix_tap;
} hold_tap_action_t;

#define EX_HOLD_TAP(enable_key, mac_hold, mac_tap, win_hold, win_tap, nix_hold, nix_tap) \
    { .type = EX_HOLD_TAP, .data = { .hold_tap_action = {enable_key, mac_hold, mac_tap, win_hold, win_tap, nix_hold, nix_tap} } }

// Text
typedef struct {
    const char *text;
} text_action_t;

#define EX_TEXT(text) \
    { .type = EX_TEXT, .data = { .text_action = {text} } }

// Combo layers
#define EX_COMBO(result, ...) \
    (combo_t){.keys = (uint16_t[]){__VA_ARGS__, COMBO_END}, .keycode = result}

#define _CL(hold_key, key) \
    EX_COMBO(KC_NO, hold_key, key)

#define _EX_COMBO_LAYER_COMBOS(h) \
    _CL(h, KC_Q), _CL(h, KC_W), _CL(h, KC_F), _CL(h, KC_P), _CL(h, KC_B), \
    _CL(h, KC_J), _CL(h, KC_L), _CL(h, KC_U), _CL(h, KC_Y), _CL(h, KC_SCLN), \
    _CL(h, KC_A), _CL(h, KC_R), _CL(h, KC_S), _CL(h, KC_T), _CL(h, KC_G), \
    _CL(h, KC_M), _CL(h, KC_N), _CL(h, KC_E), _CL(h, KC_I), _CL(h, KC_O), \
    _CL(h, Z_MT), _CL(h, X_MT), _CL(h, C_MT), _CL(h, KC_D), _CL(h, KC_V), \
    _CL(h, KC_K), _CL(h, KC_H), _CL(h, COMM_MT), _CL(h, DOT_MT), _CL(h, SLSH_MT)

#define EX_COMBO_LAYER_COMBOS(hk) \
    _EX_COMBO_LAYER_COMBOS(hk)

extern size_t combo_layers_start;
extern size_t combo_layers_count;

#define EX_COMBO_LAYER(key) \
    { .hold_key = key }

#define EX_COMBO_LAYER_END { .hold_key = KC_NO }

// Extension handling
enum extended_action_type {
    EX_OS_SHORTCUT,
    EX_HOLD_TAP,
    EX_TEXT
};

typedef union {
    os_shortcut_action_t shortcut_action;
    hold_tap_action_t hold_tap_action;
    text_action_t text_action;
} extended_action_data_t;

typedef struct {
    enum extended_action_type type;
    extended_action_data_t data;
} extended_action_t;

extern extended_action_t extended_actions[];
extern size_t extended_actions_count;

#define EX_IDX(num) num - SAFE_RANGE
#define EX_LEN sizeof(extended_actions) / sizeof(extended_actions[0])

typedef struct {
    bool is_tapping;
    uint16_t enable_key;
    uint16_t hold;
} tap_hold_state_t;

void process_combo_extensions(uint16_t combo_index, bool pressed);
bool process_extensions(uint16_t keycode, bool pressed);

extern uint16_t map_key_index(uint16_t key_index);
