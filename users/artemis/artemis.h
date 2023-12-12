#pragma once

#include "config.h"
#include QMK_KEYBOARD_H

enum layers {
    MAIN,
    GAMING,
    GAMING_NUM,
    NAV,
    NUM_SYM,
    MISC,
    FUNC,
    MACRO
};

enum custom_keycodes {
    // Extensions

    // OS Shortcuts
    IDE_RN = SAFE_RANGE, // IDE run
    IDE_DB, // IDE debug
    IDE_BD, // IDE build
    IDE_RM, // IDE rename

    DT_SW_N, // Desktop switch next
    DT_SW_P, // Desktop switch previous
    DT_OVEW, // Desktop overview
    AW_OVEW, // App Window overview

    SCRN_SH, // Screen shot
    SCRN_LK, // Lock screen
    EMOJI,   // Emoji picker TODO

    APP_LHR, // App launcher

    AUTO_FL, // Bitwarden Auto fill

    // Tap holds
    WN_SW_N, // Window switch next
    WN_SW_P, // Window switch previous
    AW_SW_N, // App window switch next
    AW_SW_P, // App window switch previous
    AP_SW_N, // App switch next
    AP_SW_P, // App switch previous

    // Texts
    TX_HEM,  // Home email
    TX_PEM,  // Project email
    TX_JEM,  // Junk email
    TX_WEM,  // Work email
    TX_USR,  // Username

    // Non-extensions
    SW_MAC,  // Switch to mac
    SW_WIN,  // Switch to windows/linux
};

// Mod Taps
#define Z_MT    LCTL_T(KC_Z)
#define X_MT    LALT_T(KC_X)
#define C_MT    LSFT_T(KC_C)
#define D_MT    LGUI_T(KC_D)
#define H_MT    RGUI_T(KC_H)
#define COMM_MT RSFT_T(KC_COMM)
#define DOT_MT  RALT_T(KC_DOT)
#define SLSH_MT RCTL_T(KC_SLSH)

#define LK_MT  LCTL_T(SCRN_LK)
#define SWP_MT LALT_T(AP_SW_P)
#define SS_MT  LSFT_T(SCRN_SH)
#define SWN_MT LGUI_T(AP_SW_N)

#define LT_MT LCTL_T(KC_LT)
#define GT_MT LALT_T(KC_GT)
#define LB_MT LSFT_T(KC_LBRC)
#define RB_MT LGUI_T(KC_RBRC)
#define N1_MT RGUI_T(KC_1)
#define N2_MT RSFT_T(KC_2)
#define N3_MT RALT_T(KC_3)
#define SL_MT RCTL_T(KC_SLSH)


// Thumbs
#define THUMB_1 MT(MOD_LGUI, KC_BACKSPACE)
#define THUMB_2 LT(NAV, KC_ESCAPE)
#define THUMB_3 MT(MOD_LSFT, KC_TAB)
#define THUMB_4 LT(MISC, KC_ENTER)
#define THUMB_5 LT(NUM_SYM, KC_SPACE)
#define THUMB_6 LT(FUNC, KC_DELETE)

// Layer swaps
#define TO_GAME TO(GAMING)
#define MO_GAM2 LT(GAMING_NUM, KC_ESCAPE)

// Key used for the hold tap extension
#define HD_KEY THUMB_2

// Layers
#define MAIN_R1           KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,             KC_J,    KC_L,    KC_U,    KC_Y,    _______
#define MAIN_R2           KC_A,    KC_R,    KC_S,    KC_T,    KC_G,             KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define MAIN_R3           Z_MT,    X_MT,    C_MT,    KC_D,    KC_V,             KC_K,    KC_H,    COMM_MT, DOT_MT, SLSH_MT
#define MAIN_R4                          THUMB_1, THUMB_2, THUMB_3,             THUMB_4, THUMB_5, THUMB_6

#define NAV_R1            _______, WN_SW_P, DT_OVEW, WN_SW_N, _______,          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______
#define NAV_R2            AW_SW_P, DT_SW_P, AW_OVEW, DT_SW_N, AW_SW_N,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TAB
#define NAV_R3            LK_MT,   SWP_MT,  SS_MT,   SWN_MT,  LSFT(KC_V),       KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______
#define NAV_R4                              _______, _______, _______,          KC_ENT,  APP_LHR, KC_BSPC

#define NUM_SYM_R1        KC_GRV,  KC_CIRC, KC_PIPE, KC_AMPR, KC_TILD,          KC_ASTR, KC_7,    KC_8,    KC_9,    KC_MINS
#define NUM_SYM_R2        KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_DLR,           KC_EQL,  KC_4,    KC_5,    KC_6,    KC_PLUS
#define NUM_SYM_R3        LT_MT,   GT_MT,   LB_MT,   KC_RBRC, QK_REP,           KC_0,    KC_1,    N2_MT,   N3_MT,   SL_MT
#define NUM_SYM_R4                          THUMB_1, KC_SPC,  KC_ENT,           _______, _______, _______

#define MISC_R1           _______, _______, KC_MS_U, _______, _______,          _______, DT_DOWN, DT_UP,   DT_PRNT, _______
#define MISC_R2           _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,          _______, KC_VOLD, KC_VOLU, KC_MUTE, _______
#define MISC_R3           KC_BTN4, KC_BTN5, KC_BTN2, KC_BTN1, _______,          _______, KC_MPRV, KC_MPLY, KC_MNXT, _______
#define MISC_R4                             _______, _______, _______,          _______, _______, _______

#define FUNC_R1           _______, _______, _______, _______, _______,          _______, KC_F7,   KC_F8,   KC_F9,   KC_F10
#define FUNC_R2           _______, _______, _______, _______, _______,          _______, KC_F4,   KC_F5,   KC_F6,   KC_F11
#define FUNC_R3           _______, _______, _______, D_MT,    _______,          _______, KC_F1,   KC_F2,   KC_F3,   KC_F12
#define FUNC_R4                             _______, _______, _______,          _______, _______, _______

#define MACRO_R1          _______, TX_WEM,  _______,  TX_PEM,  IDE_BD,          TX_JEM,  _______,  TX_USR, _______, QK_BOOT
#define MACRO_R2          _______, IDE_RN,  _______, _______, TO_GAME,          SW_MAC,  IDE_RM,   EMOJI,  SW_WIN,  _______
#define MACRO_R3          _______, _______, _______, IDE_DB,  _______,          _______, TX_HEM,  _______, _______, _______
#define MACRO_R4                            _______, _______, _______,          _______, _______, _______

#define GAMING_R1         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,             _______, _______, KC_UP,   _______, _______
#define GAMING_R2         KC_LCTL, KC_W,    KC_A,    KC_D,    KC_F,             _______, KC_LEFT, KC_DOWN, KC_RGHT, _______
#define GAMING_R3         KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,             _______, _______, _______, _______, _______
#define GAMING_R4                           _______, KC_SPC,  MO_GAM2,          _______, _______, _______

#define GAMING_NUM_R1     _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
#define GAMING_NUM_R2     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             _______, _______, _______, _______, _______
#define GAMING_NUM_R3     _______, _______, KC_M,    KC_I,    KC_B,             _______, _______, _______, _______, _______
#define GAMING_NUM_R4                       _______, _______, _______,          _______, _______, _______

#define MAIN_LAYOUT       LAYOUT_split_3x5_3(MAIN_R1, MAIN_R2, MAIN_R3, MAIN_R4)
#define NAV_LAYOUT        LAYOUT_split_3x5_3(NAV_R1, NAV_R2, NAV_R3, NAV_R4)
#define NUM_SYM_LAYOUT    LAYOUT_split_3x5_3(NUM_SYM_R1, NUM_SYM_R2, NUM_SYM_R3, NUM_SYM_R4)
#define MISC_LAYOUT       LAYOUT_split_3x5_3(MISC_R1, MISC_R2, MISC_R3, MISC_R4)
#define FUNC_LAYOUT       LAYOUT_split_3x5_3(FUNC_R1, FUNC_R2, FUNC_R3, FUNC_R4)
#define MACRO_LAYOUT      LAYOUT_split_3x5_3(MACRO_R1, MACRO_R2, MACRO_R3, MACRO_R4)
#define GAMING_LAYOUT     LAYOUT_split_3x5_3(GAMING_R1, GAMING_R2, GAMING_R3, GAMING_R4)
#define GAMING_NUM_LAYOUT LAYOUT_split_3x5_3(GAMING_NUM_R1, GAMING_NUM_R2, GAMING_NUM_R3, GAMING_NUM_R4)

#define ARTEMIS_DEFAULT_LAYERS        \
    [MAIN]       = MAIN_LAYOUT,       \
    [GAMING]     = GAMING_LAYOUT,     \
    [GAMING_NUM] = GAMING_NUM_LAYOUT, \
    [NAV]        = NAV_LAYOUT,        \
    [NUM_SYM]    = NUM_SYM_LAYOUT,    \
    [MISC]       = MISC_LAYOUT,       \
    [FUNC]       = FUNC_LAYOUT,       \
    [MACRO]      = MACRO_LAYOUT

extern const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS];

extern combo_t key_combos[];


#define rgb(r, g, b) { r, g, b }
#define ___ { 0, 0, 0}
#define l______ ___

#define GRADT_1 rgb(255, 217, 0)
#define GRADT_2 rgb(255, 174, 0)
#define GRADT_3 rgb(255, 131, 0)
#define GRADT_4 rgb(255, 88, 0)
#define GRADT_5 rgb(255, 0, 106)
#define GRADT_6 rgb(255, 0, 200)
#define GRADT_7 rgb(147, 0, 255)
#define GRADT_8 rgb(0, 94, 255)
#define GRADT_9 rgb(0, 255, 255)

#define SUNRISE_GRADIENT LED_LAYOUT_split_3x5_3(                                                               \
    GRADT_1, GRADT_2, GRADT_3, GRADT_4, GRADT_5,          GRADT_5, GRADT_4, GRADT_3, GRADT_2, GRADT_1, \
    GRADT_2, GRADT_3, GRADT_4, GRADT_5, GRADT_6,          GRADT_6, GRADT_5, GRADT_4, GRADT_3, GRADT_2, \
    GRADT_3, GRADT_4, GRADT_5, GRADT_6, GRADT_7,          GRADT_7, GRADT_6, GRADT_5, GRADT_4, GRADT_3, \
                      GRADT_6, GRADT_8, GRADT_9,          GRADT_9, GRADT_8, GRADT_6                    \
)

#define ARTEMIS_DEFAULT_LED_LAYERS \
    [0] = SUNRISE_GRADIENT

extern const uint8_t PROGMEM ledmaps[][RGB_MATRIX_LED_COUNT][3];
