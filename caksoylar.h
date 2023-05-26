#pragma once
#include QMK_KEYBOARD_H

#ifdef COMBO_ENABLE
#    include "g/keymap_combo.h"
#endif

#define IS_HRM(keycode) \
    (IS_QK_MOD_TAP(keycode) \
     && (((keycode & 0xff) >= KC_A && (keycode & 0xff) <= KC_Z) \
         || (keycode & 0xff) == KC_QUOT || (keycode & 0xff) == KC_TAB))

#define IS_ALPHA_KEY(keycode, record) \
    (IS_QK_BASIC(keycode) && keycode >= KC_A && keycode <= KC_Z) \
     || (record->tap.count && (keycode & 0xff) >= KC_A && (keycode & 0xff) <= KC_Z)

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM def_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_BLUE});
const rgblight_segment_t PROGMEM qwe_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_TEAL});
const rgblight_segment_t PROGMEM gme_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_PURPLE});
const rgblight_segment_t PROGMEM sym_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_GREEN});
const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_ORANGE});
const rgblight_segment_t PROGMEM fun_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_RED});
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    def_layer, 
    qwe_layer, 
    gme_layer, 
    sym_layer, 
    nav_layer,
    fun_layer
);
#endif
