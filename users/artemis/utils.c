#include "utils.h"
#include "artemis.h"
#include "keycode_config.h"
#include "keymap_us.h"

os_variant_t current_os = OS_MACOS;

uint16_t get_os_modifier(uint16_t modifier) {
    switch (modifier) {
        case KC_LCTL:
            SWITCH_OS(return KC_LCTL, return KC_LGUI, return KC_LGUI);
            break;
        case KC_LGUI:
            SWITCH_OS(return KC_LGUI, return KC_LCTL, return KC_LCTL);
            break;
        case KC_LSFT:
            return KC_LSFT;
        case KC_LALT:
            return KC_LALT;
    }

    return modifier;
}

void set_os(os_variant_t os) {
    current_os = os;

    keymap_config.raw = eeconfig_read_keymap();
    switch (current_os) {
        case OS_WINDOWS:
        case OS_LINUX:
            xprintf("Setting OS to Windows/Linux\n");
            keymap_config.swap_lctl_lgui = true;
            break;
        default:
            xprintf("Setting OS to macOS\n");
            keymap_config.swap_lctl_lgui = false;
            current_os = OS_MACOS;
            break;
    }

    eeconfig_update_keymap(keymap_config.raw);
    clear_keyboard();
}

// void init_combo_layer(uint16_t combo_index) {
    // uint16_t layer = key_combos[combo_index].keycode;seseseseseseseseseessesee
    // uint16_t result = ((uint16_t*)keymaps[layer])[0];
    // uint16_t hold_key = key_combos[combo_index].keys[0];
    // uint16_t tap_key = ((uint16_t*)keymaps[MAIN])[0];
    // key_combos[combo_index] = EX_COMBO(result, tap_key, hold_key);
    // key_combos[combo_index] = EX_COMBO(KC_AMPERSAND, THUMB_5, KC_A);
    // key_combos[combo_index].keys = (uint16_t[]){ THUMB_5, KC_B };
// }

// td_state_t cur_dance(tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
//         // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
//         else return TD_SINGLE_HOLD;
//     } else if (state->count == 2) {
//         // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
//         // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
//         // keystrokes of the key, and not the 'double tap' action/macro.
//         if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
//         else if (state->pressed) return TD_DOUBLE_HOLD;
//         else return TD_DOUBLE_TAP;
//     }

//     // Assumes no one is trying to type the same letter three times (at least not quickly).
//     // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
//     // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
//     if (state->count == 3) {
//         if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
//         else return TD_TRIPLE_HOLD;
//     } else return TD_UNKNOWN;
// }

// void etd_finished(tap_dance_state_t *state, void *data) {
//     extended_tap_dance_action_t* action = (extended_tap_dance_action_t*) data;
//     action->state = cur_dance(state);

//     switch (action->state) {
//         case TD_SINGLE_TAP:
//             register_code16(get_os_modifier(action->single_tap));
//             break;
//         case TD_SINGLE_HOLD:
//             register_code16(get_os_modifier(action->single_hold));
//             break;
//         case TD_DOUBLE_TAP:
//             register_code16(get_os_modifier(action->double_tap));
//             break;
//         case TD_DOUBLE_HOLD:
//             register_code16(get_os_modifier(action->double_hold));
//             break;
//         default:
//             break;
//     }
// }

// void etd_reset(tap_dance_state_t *state, void *data) {
//     extended_tap_dance_action_t* action = (extended_tap_dance_action_t*) data;

//     switch (action->state) {
//         case TD_SINGLE_TAP:
//             unregister_code16(get_os_modifier(action->single_tap));
//             break;
//         case TD_SINGLE_HOLD:
//             unregister_code16(get_os_modifier(action->single_hold));
//             break;
//         case TD_DOUBLE_TAP:
//             unregister_code16(get_os_modifier(action->double_tap));
//             break;
//         case TD_DOUBLE_HOLD:
//             unregister_code16(get_os_modifier(action->double_hold));
//             break;
//         default:
//             break;
//     }

//     action->state = TD_NONE;
// }
