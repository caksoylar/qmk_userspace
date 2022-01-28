#include "caksoylar.h"


#ifdef CAPS_WORD_ENABLE
void update_caps_word(bool *active, uint16_t activate_key, uint16_t keycode, keyrecord_t *record) {
    if (!*active) {
        if (keycode == activate_key) {
            *active = true;
            tap_code(KC_CAPS);
        }
        return;
    }
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        if (!record->tap.count) {
            return;
        }
        keycode &= 0xff;
    }
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_P1 ... KC_P0:
        case KC_UNDS:
        case KC_MINS:
            break;
        default:
            if (keycode >= KC_A && keycode <= KC_RIGHT_GUI) {
                tap_code(KC_CAPS);
                *active = false;
            }
            break;
    }
}
#endif

void update_swapper(bool *active, uint16_t hold_key, uint16_t trigger1, uint16_t tap_key1, uint16_t trigger2, uint16_t tap_key2, uint16_t keycode, bool pressed) {
    if (keycode == trigger1 || keycode == trigger2) {
        if (pressed) {
            if (!*active) {
                *active = true;
                register_code16(hold_key);
            }
            register_code16(keycode == trigger1 ? tap_key1 : tap_key2);
        } else {
            unregister_code16(keycode == trigger1 ? tap_key1 : tap_key2);
            // Don't unregister hold_key until some other key is hit or released
        }
    } else if (*active) {
        unregister_code16(hold_key);
        *active = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool win_active = false;
    update_swapper(&win_active, KC_LALT, WIN_RT, KC_TAB, WIN_LT, S(KC_TAB), keycode, record->event.pressed);

#ifdef CAPS_WORD_ENABLE
    static bool caps_word_active = false;
    if (record->event.pressed) {
        update_caps_word(&caps_word_active, CAPSWRD, keycode, record);
    }
#endif

    if (keycode == NAV_BSP) {
        if (get_mods() & MOD_BIT(KC_LEFT_ALT)) {
            if (!record->tap.count) {
                return true;
            }
            record->event.pressed ? register_code(KC_TAB) : unregister_code(KC_TAB);
            return false;
        }
    }
    return true;
}

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_LAYERS
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_layers = my_rgb_layers;
#endif
#ifdef KEYBOARD_keebio_iris_rev4
    if (is_keyboard_left() == is_keyboard_master()) {
        default_layer_set(1UL << GME);
        combo_disable();
    }
#endif
}

#ifdef COMBO_ENABLE
void update_combo_status(layer_state_t layer_state, layer_state_t default_layer_state) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case DEF:
        case CLM:
            combo_enable();
            break;
        default:
            combo_disable();
            break;
    }
}
#endif

layer_state_t default_layer_state_set_user(layer_state_t state) {
#ifdef COMBO_ENABLE
    update_combo_status(layer_state, state);
#endif
#ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(DEF, layer_state_cmp(state, DEF));
    rgblight_set_layer_state(GME, layer_state_cmp(state, GME));
    rgblight_set_layer_state(CLM, layer_state_cmp(state, CLM));
#endif
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, SYM, NAV, FUN);
#ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(SYM, layer_state_cmp(state, SYM));
    rgblight_set_layer_state(NAV, layer_state_cmp(state, NAV));
    rgblight_set_layer_state(FUN, layer_state_cmp(state, FUN));
#endif
#ifdef COMBO_ENABLE
    update_combo_status(state, default_layer_state);
#endif
    return state;
}

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return IS_HRM(keycode) ? TAPPING_TERM + 50 : TAPPING_TERM;
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return IS_HRM(keycode) ? false : true;
}
#endif

#ifdef TAPPING_FORCE_HOLD_PER_KEY
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    return IS_HRM(keycode) ? false : true;
}
#endif

#ifdef COMBO_ENABLE
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    return true;
}
#endif

#ifdef ENCODER_ENABLE
__attribute__ ((weak)) void update_dial(bool direction) {}

bool encoder_update_user(uint8_t index, bool clockwise) {
#if defined(KEYBOARD_keebio_iris_rev4)
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case SYM:
                clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
                break;
            case FUN:
                if (get_mods() & MOD_MASK_SHIFT) {
#ifdef RGBLIGHT_ENABLE
                    clockwise ? rgblight_increase_val_noeeprom() : rgblight_decrease_val_noeeprom();
#endif
                } else {
                    update_dial(clockwise);
                }
                break;
            default:
#ifdef MOUSEKEY_ENABLE
                clockwise ? tap_code(KC_MS_WH_DOWN) : tap_code(KC_MS_WH_UP);
#else
                clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
#endif
                break;
        }
    }
#elif defined(KEYBOARD_capsunlocked_cu7)
    switch (get_highest_layer(layer_state)) {
        case 1:
            clockwise ? rgblight_increase_hue_noeeprom() : rgblight_decrease_hue_noeeprom();
            break;
        default:
            clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
            break;
    }
#endif
    return true;
}
#endif
