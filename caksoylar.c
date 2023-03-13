#include "caksoylar.h"


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

#if !defined(KEYBOARD_capsunlocked_cu7)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool win_active = false;
    update_swapper(&win_active, KC_LALT, WIN_RT, KC_TAB, WIN_LT, S(KC_TAB), keycode, record->event.pressed);

    // mod-morph LALT+BSPC to LALT+TAB
    if (keycode == NAV_BSP) {
        if (get_mods() & MOD_BIT(KC_LEFT_ALT)) {
            if (!record->tap.count) {
                return true;
            }
            record->event.pressed ? register_code(KC_TAB) : unregister_code(KC_TAB);
            return false;
        }
    }

    // simple unicode macro for Windows
    if (keycode == INV_QM && record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_KP_1);
        tap_code(KC_KP_6);
        tap_code(KC_KP_8);
        unregister_code(KC_LALT);
        return false;
    }
    return true;
}
#endif

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
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case DEF:
        case CLM:
            return true;
        default:
            return false;
    }
}
#endif

layer_state_t default_layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(DEF, layer_state_cmp(state, DEF));
    rgblight_set_layer_state(CLM, layer_state_cmp(state, CLM));
    rgblight_set_layer_state(GME, layer_state_cmp(state, GME));
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
    return state;
}

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if (IS_HRM(keycode)) {
        if (keycode >> 8 & MOD_MASK_SHIFT) {
            return TAPPING_TERM + 50;
        }
        return TAPPING_TERM + 100;
    }
    return TAPPING_TERM;
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return !IS_HRM(keycode);
}
#endif

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return IS_QK_MOD_TAP(keycode) && !IS_HRM(keycode);
}
#endif

#ifdef QUICK_TAP_TERM_PER_KEY
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    return IS_HRM(keycode) ? 150 : 0;
}
#endif

#ifdef COMBO_ENABLE
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    return true;
}
#endif

#if defined(ENCODER_ENABLE) && defined(KEYBOARD_keebio_iris_rev4)
__attribute__ ((weak)) void update_dial(bool direction) {}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case SYM:
                clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
                break;
            case NAV:
                update_dial(clockwise);
                break;
            case FUN:
#ifdef RGBLIGHT_ENABLE
                clockwise ? rgblight_increase_val_noeeprom() : rgblight_decrease_val_noeeprom();
#endif
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
    return false;
}
#endif

#if defined(KEYBOARD_fingerpunch_ffkb_byomcu_v1) && defined(OLED_ENABLE)
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_logo(void) {
    // ffkb logo, 128x32px
    static const char PROGMEM ffkb_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
        0xf0, 0x10, 0x10, 0x10, 0x90, 0x30, 0x30, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0x3c, 0x3c, 0x38, 0x70,
        0x70, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
        0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0x70,
        0x70, 0x38, 0x3c, 0x3c, 0xfc, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x10, 0x00,
        0x80, 0x90, 0xd0, 0xf0, 0x30, 0x30, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
        0x3f, 0x21, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe7, 0xff, 0x7f, 0x7f, 0xbc, 0x9e, 0x8e, 0x8f,
        0x87, 0x87, 0x83, 0x83, 0x81, 0x81, 0x81, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x81, 0x81, 0x81, 0x83, 0x83, 0x87, 0x87,
        0x8f, 0x8e, 0x9e, 0xbc, 0x7f, 0x7f, 0xff, 0xe7, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x23, 0x07,
        0x0f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x3c, 0x38, 0x30, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
        0xfc, 0x44, 0x44, 0x44, 0xe4, 0x0c, 0x0c, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x06, 0x06, 0x07, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1b, 0x3b, 0x3b, 0x73, 0x73, 0x73, 0xe3,
        0xe3, 0xdf, 0xdf, 0xdf, 0x8b, 0x83, 0x03, 0x03, 0x07, 0x1f, 0xfe, 0xfc, 0xf8, 0xe0, 0x00, 0x00,
        0x00, 0x00, 0xe0, 0xf8, 0xfc, 0xfe, 0x1f, 0x07, 0x03, 0x03, 0x83, 0x8b, 0xdf, 0xdf, 0xdf, 0xe3,
        0xe3, 0x73, 0x73, 0x73, 0x3b, 0x3b, 0x1b, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x07, 0x06, 0x06, 0x02,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x44, 0x44,
        0x44, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xb8, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
        0x0f, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0f, 0x0e, 0x1f, 0x3f, 0x3f, 0x3f, 0x36, 0x36,
        0x36, 0x36, 0x3f, 0x3f, 0x3f, 0x1f, 0x0e, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x08, 0x08,
        0x08, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(ffkb_logo, sizeof(ffkb_logo));
}

bool oled_task_user(void) {
    render_logo();
    return true;
}
#endif
