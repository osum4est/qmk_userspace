#include "artemis.h"
#include "config.h"
#include "utils.h"
#include "extensions.h"
#include "secrets.h"

extended_action_t extended_actions[] = {
    //                                 Mac                 Windows               Linux
    [EX_IDX(IDE_RN)]  = EX_OS_SHORTCUT(LSFT(KC_F10),       LSFT(KC_F10),         0),
    [EX_IDX(IDE_DB)]  = EX_OS_SHORTCUT(LSFT(KC_F9),        LSFT(KC_F9),          0),
    [EX_IDX(IDE_BD)]  = EX_OS_SHORTCUT(LGUI(KC_F9),        LCTL(KC_F9),          0),
    [EX_IDX(IDE_RM)]  = EX_OS_SHORTCUT(LSFT(KC_F6),        LSFT(KC_F6),          0),

    [EX_IDX(DT_SW_N)] = EX_OS_SHORTCUT(LCTL(KC_RIGHT),     LCTL(LGUI(KC_RIGHT)), 0),
    [EX_IDX(DT_SW_P)] = EX_OS_SHORTCUT(LCTL(KC_LEFT),      LCTL(LGUI(KC_LEFT)),  0),
    [EX_IDX(DT_OVEW)] = EX_OS_SHORTCUT(LCTL(KC_UP),        LGUI(KC_TAB),         0),
    [EX_IDX(AW_OVEW)] = EX_OS_SHORTCUT(LCTL(KC_DOWN),      0,                    0),

    [EX_IDX(SCRN_SH)] = EX_OS_SHORTCUT(LGUI(LSFT(KC_4)),   LGUI(LSFT(KC_S)),     0),
    [EX_IDX(SCRN_LK)] = EX_OS_SHORTCUT(LCTL(LGUI(KC_Q)),   LGUI(KC_L),           0),
    [EX_IDX(EMOJI)]   = EX_OS_SHORTCUT(LCTL(LGUI(KC_SPC)), LGUI(KC_SCLN),        0),

    [EX_IDX(APP_LHR)] = EX_OS_SHORTCUT(LGUI(KC_SPC),       LALT(KC_SPC),         0),

    [EX_IDX(AUTO_FL)] = EX_OS_SHORTCUT(LGUI(LSFT(KC_L)),   LCTL(LSFT(KC_L)),     0),

    [EX_IDX(WN_SW_N)] = EX_HOLD_TAP(HD_KEY, QK_LGUI, KC_TAB,       QK_LALT, KC_TAB,       0, 0),
    [EX_IDX(WN_SW_P)] = EX_HOLD_TAP(HD_KEY, QK_LGUI, LSFT(KC_TAB), QK_LALT, LSFT(KC_TAB), 0, 0),
    [EX_IDX(AW_SW_N)] = EX_HOLD_TAP(HD_KEY, QK_LGUI, KC_GRV,       QK_LALT, KC_TAB,       0, 0),
    [EX_IDX(AW_SW_P)] = EX_HOLD_TAP(HD_KEY, QK_LGUI, LSFT(KC_GRV), QK_LALT, LSFT(KC_TAB), 0, 0),
    [EX_IDX(AP_SW_N)] = EX_HOLD_TAP(HD_KEY, QK_LCTL, KC_TAB,       QK_LCTL, KC_TAB,       0, 0),
    [EX_IDX(AP_SW_P)] = EX_HOLD_TAP(HD_KEY, QK_LCTL, LSFT(KC_TAB), QK_LCTL, LSFT(KC_TAB), 0, 0),

    [EX_IDX(TX_HEM)]  = EX_TEXT(TEXT_HOME_EMAIL),
    [EX_IDX(TX_PEM)]  = EX_TEXT(TEXT_PROFESSIONAL_EMAIL),
    [EX_IDX(TX_JEM)]  = EX_TEXT(TEXT_JUNK_EMAIL),
    [EX_IDX(TX_WEM)]  = EX_TEXT(TEXT_WORK_EMAIL),
    [EX_IDX(TX_USR)]  = EX_TEXT(TEXT_USERNAME),
};

size_t extended_actions_count = sizeof(extended_actions) / sizeof(extended_action_t);

size_t combo_layers_start = 0;
size_t combo_layers_count = 0;


combo_t key_combos[] = {
    // EX_COMBO_LAYER_COMBOS(THUMB_1),
    // EX_COMBO_LAYER_COMBOS(THUMB_2),
    // EX_COMBO_LAYER_COMBOS(THUMB_3),
    // EX_COMBO_LAYER_COMBOS(THUMB_4),
    // EX_COMBO_LAYER_COMBOS(THUMB_5),
    // EX_COMBO_LAYER_COMBOS(THUMB_6),

    EX_COMBO(OSL(MACRO), THUMB_3, THUMB_4),
    // EX_COMBO(CW_TOGG, C_MT, COMM_MT),
    // EX_COMBO(KC_LBRC, C_MT, DOT_MT),
    // EX_COMBO(KC_CAPS, C_MT, SLSH_MT),

    // The following combos are laid out like this:
    // 1    2    3        10   11   12
    // 4    5    6        13   14   15
    // 7    8    9        16   17   18

    EX_COMBO(KC_HASH, KC_W,    KC_F),    // 2
    EX_COMBO(KC_HASH, KC_CIRC, KC_PIPE), // 2
    EX_COMBO(KC_PERC, KC_F,    KC_P),    // 3
    EX_COMBO(KC_PERC, KC_PIPE, KC_AMPR), // 3
    EX_COMBO(KC_AT,   KC_R,    KC_S),    // 5
    EX_COMBO(KC_AT,   KC_RCBR, KC_LPRN), // 5
    EX_COMBO(KC_UNDS, KC_S,    KC_T),    // 6
    EX_COMBO(KC_UNDS, KC_LPRN, KC_RPRN), // 6
    EX_COMBO(KC_BSLS, X_MT,    C_MT),    // 8
    EX_COMBO(KC_BSLS, GT_MT,   LB_MT),   // 8
    EX_COMBO(KC_EXLM, C_MT,    KC_D),    // 9
    EX_COMBO(KC_EXLM, LB_MT,   KC_RBRC), // 9

    EX_COMBO(KC_SCLN, KC_L,  KC_U),    // 10
    EX_COMBO(KC_SCLN, KC_7,  KC_8),    // 10
    EX_COMBO(KC_COLN, KC_U,  KC_Y),    // 11
    EX_COMBO(KC_COLN, KC_8,  KC_9),    // 11
    EX_COMBO(KC_DQUO, KC_N,  KC_E),    // 13
    EX_COMBO(KC_DQUO, KC_4,  KC_5),    // 13
    EX_COMBO(KC_QUOT, KC_E,  KC_I),    // 14
    EX_COMBO(KC_QUOT, KC_5,  KC_6),    // 14
    EX_COMBO(KC_COMM, KC_6,  KC_PLUS), // 15
    EX_COMBO(KC_QUES, KC_H,  COMM_MT), // 16
    EX_COMBO(KC_QUES, KC_1,  N2_MT),   // 16
    EX_COMBO(KC_DOT,  N2_MT, N3_MT),   // 17
};

// const key_override_t** key_overrides = (const key_override_t *[])[
//     ko_make_basic(MOD_LSFT, KC_1, KC_1),
// ];
//
// con_oconst


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   ARTEMIS_DEFAULT_LAYERS
};

const uint8_t PROGMEM ledmaps[][RGB_MATRIX_LED_COUNT][3] = {
    ARTEMIS_DEFAULT_LED_LAYERS
};

uint32_t late_init(uint32_t trigger_time, void *user_data) {
    // Detect host OS only works after some period of time after initialization
    #ifdef OS_DETECTION_ENABLE
    current_os = detected_host_os();
    #elif
    current_os = OS_MACOS;
    #endif

    set_os(current_os);

    return 0;
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();

    defer_exec(1000, late_init, NULL);
}

void load_ledmap(uint8_t index) {
    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        rgb_matrix_set_color(i, ledmaps[index][i][0], ledmaps[index][i][1], ledmaps[index][i][2]);
    }
}

bool rgb_matrix_indicators_user(void) {
    load_ledmap(0);
    return true;
}

bool fix_mt(uint16_t keycode, keyrecord_t *record) {
    if (record->tap.count) {
        if (!process_extensions(keycode, record->event.pressed))
            return false;

        if (record->event.pressed) {
            tap_code16(keycode);
            return false;
        }
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LK_MT: return fix_mt(SCRN_LK, record);
        case SWP_MT: return fix_mt(AP_SW_P, record);
        case SS_MT: return fix_mt(SCRN_SH, record);
        case SWN_MT: return fix_mt(AP_SW_N, record);
        case LT_MT: return fix_mt(KC_LT, record);
        case GT_MT: return fix_mt(KC_GT, record);
        case LB_MT: return fix_mt(KC_LBRC, record);
        case RB_MT: return fix_mt(KC_RBRC, record);
    }

    if (!process_extensions(keycode, record->event.pressed)) {
        return false;
    }

    if (record->event.pressed) {
        switch (keycode) {
            case SW_MAC:
                layer_clear();
                set_os(OS_MACOS);
                return false;
            case SW_WIN:
                layer_clear();
                set_os(OS_WINDOWS);
                return false;
            default:
                break;
        }
    }

    return true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    process_combo_extensions(combo_index, pressed);
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case THUMB_2:
        case THUMB_5:
            return 0;
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case Z_MT:
        case X_MT:
        case C_MT:
            return 300;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case THUMB_1:
        case THUMB_2:
        case THUMB_3:
        case THUMB_4:
        case THUMB_6:
            return true;
        default:
            return false;
    }

}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (combo->keys[0]) {
        case THUMB_1:
        case THUMB_2:
        case THUMB_3:
        case THUMB_4:
        case THUMB_5:
        case THUMB_6:
            return 5;
    }

    if ((combo->keys[0] == KC_S && combo->keys[1] == KC_T) ||
        (combo->keys[0] == KC_L && combo->keys[1] == KC_U) ||
        (combo->keys[0] == KC_N && combo->keys[1] == KC_E)) {
        return 20;
    }

    switch (combo->keycode) {
        case CW_TOGG:
        case KC_CAPS_LOCK:
        case KC_DOUBLE_QUOTE:
        case KC_QUOTE:
            return 50;
    }

    return COMBO_TERM;
}
