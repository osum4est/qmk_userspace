#include "extensions.h"
#include "artemis.h"
#include "utils.h"

tap_hold_state_t tap_hold_state = {false, 0, 0};

extended_action_t* get_extended_action(uint16_t keycode) {
    int index = EX_IDX(keycode);
    if (index >= extended_actions_count || index < 0) {
        return NULL;
    }

    return &extended_actions[index];
}

bool process_os_shortcut(os_shortcut_action_t* action, uint16_t keycode, bool pressed) {
    if (pressed) {
        switch (current_os) {
            case OS_MACOS:
                tap_code16(action->mac);
                return false;
            case OS_WINDOWS:
                tap_code16(action->win);
                return false;
            case OS_LINUX:
                tap_code16(action->lin);
                return false;
            default:
                break;
        }
    }

    return true;
}

bool process_hold_tap(hold_tap_action_t* action, uint16_t keycode, bool pressed) {
    uint16_t hold = 0;
    uint16_t tap = 0;
    switch (current_os) {
        case OS_MACOS:
            hold = action->mac_hold;
            tap = action->mac_tap;
            break;
        case OS_WINDOWS:
            hold = action->win_hold;
            tap = action->win_tap;
            break;
        case OS_LINUX:
            hold = action->nix_hold;
            tap = action->nix_tap;
            break;
        default:
            break;
    }

    if (pressed) {
        if (tap_hold_state.is_tapping) {
            if (tap_hold_state.hold != hold) {
                unregister_code16(tap_hold_state.hold);
                register_code16(hold);
                tap_hold_state.hold = hold;
            }
        } else {
            tap_hold_state.is_tapping = true;
            tap_hold_state.enable_key = action->enable_key;
            tap_hold_state.hold = hold;
            register_code16(hold);
        }

        // OR the mod so that it stays pressed
        register_code16(hold | tap);
    } else {
        // Keep the mod pressed
        unregister_code16(tap);
    }

    return false;
}

bool process_hold_tap_stop(extended_action_t* action, uint16_t keycode, bool pressed) {
    if (tap_hold_state.is_tapping && keycode == tap_hold_state.enable_key && !pressed) {
        unregister_code16(tap_hold_state.hold);
        tap_hold_state.is_tapping = false;
        tap_hold_state.enable_key = 0;
        tap_hold_state.hold = 0;
        return true; // Let processing continue so that the layer gets inactvated
    }

    // If we're holding a key, allow other keys to be pressed with it held as well
    if (tap_hold_state.is_tapping && (action == NULL || action->type != EX_HOLD_TAP)) {
        if (pressed)
            register_code16(tap_hold_state.hold | keycode);
        else
            unregister_code16(keycode);
        return false;
    }

    return true;
}

bool process_text(text_action_t* action, uint16_t keycode, bool pressed) {
    if (pressed) {
        send_string(action->text);
        return false;
    }

    return true;
}

void process_combo_extensions(uint16_t combo_index, bool pressed) {
    uint16_t combo_layer_index = combo_index / 30;
    if (combo_layer_index >= combo_layers_count) {
        return;
    }

    combo_t *combo = &key_combos[combo_index];
    uint16_t key_index = map_key_index((combo_layers_start + combo_index) % 30);
    uint16_t hold_key = combo->keys[0];

    // For now, only MT or LT are supporte
    if (hold_key >= QK_LAYER_TAP && hold_key <= QK_LAYER_TAP_MAX) {
        uint16_t layer = QK_LAYER_TAP_GET_LAYER(hold_key);
        uint16_t target_key = ((uint16_t*)keymaps[layer])[key_index];

        extended_action_t* action = get_extended_action(target_key);
        if (action != NULL) {
            process_extensions(target_key, pressed);
        } else {
            if (pressed) {
                register_code16(target_key);
            } else {
                unregister_code16(target_key);
            }
        }
    } else if (hold_key >= QK_MOD_TAP && hold_key <= QK_MOD_TAP_MAX) {
        uint16_t mods = QK_MOD_TAP_GET_MODS(hold_key);
        uint16_t current_layer = biton32(layer_state);
        uint16_t target_key = ((uint16_t*)keymaps[current_layer])[key_index];

        if (pressed) {
            register_mods(mods);
            register_code16(target_key);
        } else {
            unregister_code16(target_key);
            unregister_mods(mods);
        }
    } else {
        return;
    }
}

bool process_extensions(uint16_t keycode, bool pressed) {
    extended_action_t* action = get_extended_action(keycode);
    if (!process_hold_tap_stop(action, keycode, pressed)) {
        return false;
    }

    if (action == NULL) {
        return true;
    }

    switch (action->type) {
        case EX_OS_SHORTCUT:
            return process_os_shortcut((os_shortcut_action_t*) &action->data, keycode, pressed);
        case EX_HOLD_TAP:
            return process_hold_tap((hold_tap_action_t*) &action->data, keycode, pressed);
        case EX_TEXT:
            return process_text((text_action_t*) &action->data, keycode, pressed);
        default:
            return false;
    }
}
