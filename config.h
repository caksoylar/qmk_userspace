#pragma once

#ifdef LOCKING_SUPPORT_ENABLE
#    undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#    undef LOCKING_RESYNC_ENABLE
#endif

#define LAYER_STATE_8BIT

#undef TAPPING_TERM
#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY

#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define QUICK_TAP_TERM_PER_KEY

#ifdef COMBO_ENABLE
#    define COMBO_SHOULD_TRIGGER
#    define COMBO_MUST_TAP_PER_COMBO
#    define COMBO_ONLY_FROM_LAYER 0  // DEF layer

#    undef COMBO_TERM
#    define COMBO_TERM 40
#endif

#if defined(RGBLIGHT_ENABLE) && defined(KEYBOARD_keebio_iris_rev4)
#    ifdef RGBLIGHT_ANIMATIONS
#        undef RGBLIGHT_ANIMATIONS
#    endif
#    define RGBLIGHT_EFFECT_STATIC_LIGHT
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#    define RGBLIGHT_EFFECT_SNAKE
//#    define RGBLIGHT_EFFECT_KNIGHT
//#    define RGBLIGHT_EFFECT_CHRISTMAS
//#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#    define RGBLIGHT_EFFECT_RGB_TEST
//#    define RGBLIGHT_EFFECT_ALTERNATING
//#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_SLEEP
#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_LAYERS_RETAIN_VAL
#endif

#ifdef MOUSEKEY_ENABLE
#    define MOUSEKEY_DELAY              0
#    define MOUSEKEY_INTERVAL           8
#    define MOUSEKEY_MOVE_DELTA         6
#    define MOUSEKEY_MAX_SPEED         10
#    define MOUSEKEY_TIME_TO_MAX      160
#    define MOUSEKEY_WHEEL_DELAY       16
#    define MOUSEKEY_WHEEL_INTERVAL    40
#    define MOUSEKEY_WHEEL_MAX_SPEED    8
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 80
#endif

#include "layouts.h"
