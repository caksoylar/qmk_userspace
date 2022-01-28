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

#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY

#ifdef COMBO_ENABLE
#    define COMBO_MUST_TAP_PER_COMBO
#    define COMBO_ONLY_FROM_LAYER 0  // DEF layer

#    undef COMBO_TERM
#    define COMBO_TERM 40
#endif

#if defined(RGBLIGHT_ENABLE) && defined(KEYBOARD_keebio_iris_rev4)
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_SLEEP
#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_LAYERS_RETAIN_VAL
#endif

#include "layouts.h"
