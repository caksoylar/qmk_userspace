#pragma once

// layer indices
#define DEF 0
#define GME 1
#define CLM 2
#define SYM 3
#define NAV 4
#define FUN 5

// custom keycodes
#define MY_SAFE_RANGE 0xfff0
#define WIN_RT        MY_SAFE_RANGE
#define WIN_LT        MY_SAFE_RANGE+1
#define CAPSWRD       MY_SAFE_RANGE+2

// non-HRM hold-tap definitions
#define CTL_ESC CTL_T(KC_ESC)
#define NAV_BSP LT(NAV, KC_BSPC)
#define SYM_SPC LT(SYM, KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)
#define SFT_TAB SFT_T(KC_ENT)
#define GUI_TAB GUI_T(KC_TAB)
#define ALT_DEL RALT_T(KC_DEL)

// home-row mods (for combos)
#define HM_A LCTL_T(KC_A)
#define HM_S LGUI_T(KC_S)
#define HM_D LALT_T(KC_D)
#define HM_F LSFT_T(KC_F)
#define HM_J RSFT_T(KC_J)
#define HM_K RALT_T(KC_K)
#define HM_L RGUI_T(KC_L)
#define HM_QUOT RCTL_T(KC_QUOT)
#define HM_TAB LSFT_T(KC_TAB)

// navigation shortcuts
#define ALT_F4  A(KC_F4)
#define CTL_F4  C(KC_F4)
#define DSK_LT  C(G(KC_LEFT))
#define DSK_RT  C(G(KC_RGHT))
#define SFT_INS S(KC_INS)
#define TAB_RT  C(KC_TAB)
#define TAB_LT  C(S(KC_TAB))

#define IRIS_wrapper(...)       LAYOUT(__VA_ARGS__)
#define CHOC_ERGO_wrapper(...)  LAYOUT(__VA_ARGS__)
#define GERGOPLEX_wrapper(...)  LAYOUT_split_3x5_3(__VA_ARGS__)

#define _DEF \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_SCLN, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    _______, _______, _______, GUI_TAB, CTL_ESC, NAV_BSP, SYM_SPC, SFT_ENT, ALT_DEL, _______, _______, _______ 

#define _GME \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    _______, _______, _______, KC_LCTL, KC_LALT, KC_SPC,  MO(NAV), KC_ENT,  DF(DEF), _______, _______, _______ 

#define _CLM \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSLS, \
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    _______, _______, _______, GUI_TAB, CTL_ESC, NAV_BSP, SYM_SPC, SFT_ENT, ALT_DEL, _______, _______, _______

#define _SYM \
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    KC_LBRC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, KC_RBRC, \
    _______, DF(DEF), DF(GME), DF(CLM), KC_SCLN, KC_AMPR, KC_ASTR, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

#define _NAV \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, ALT_F4,  TAB_LT,  TAB_RT,  CTL_F4,  KC_VOLU, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PAUS, _______, \
    _______, KC_LCTL, KC_LGUI, KC_LALT, HM_TAB,  KC_VOLD, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CALC, _______, \
    _______, XXXXXXX, WIN_LT,  WIN_RT,  SFT_INS, KC_MPLY, KC_INS,  KC_DEL,  KC_MPRV, KC_MNXT, KC_PSCR, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

#define _FUN \
    _______, DF(DEF), DF(GME), DF(CLM), _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, RGB_TOG, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_CAPS, KC_P7,   KC_P8,   KC_P9,   KC_COMM, RGB_MOD, \
    RESET,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_NLCK, KC_P4,   KC_P5,   KC_P6,   KC_DOT,  RGB_RMOD, \
    _______, XXXXXXX, DSK_LT,  DSK_RT,  KC_F11,  KC_F12,  KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, \
    _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______

#define HRM(k) HRM_HOLDTAP(k)
#define HRM_HOLDTAP( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b  \
) \
    k00, k01,         k02,         k03,         k04,         k05, k06, k07,         k08,         k09,         k0a,         k0b, \
    k10, k11,         k12,         k13,         k14,         k15, k16, k17,         k18,         k19,         k1a,         k1b, \
    k20, LCTL_T(k21), LGUI_T(k22), LALT_T(k23), LSFT_T(k24), k25, k26, RSFT_T(k27), RALT_T(k28), RGUI_T(k29), RCTL_T(k2a), k2b, \
    k30, k31,         k32,         k33,         k34,         k35, k36, k37,         k38,         k39,         k3a,         k3b, \
    k40, k41,         k42,         k43,         k44,         k45, k46, k47,         k48,         k49,         k4a,         k4b

#define C_36(k) L_5x12_TO_3x5_3(k)
#define L_5x12_TO_3x5_3( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b  \
) \
         k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a,      \
         k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a,      \
         k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a,      \
                   k43, k44, k45, k46, k47, k48

#define C_34(k) L_5x12_TO_3x5_2(k)
#define L_5x12_TO_3x5_2( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b  \
) \
         k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a,      \
         k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a,      \
         k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a,      \
                        k44, k45, k46, k47

#define C_IRIS(k) L_5x12_TO_IRIS(k)
#define L_5x12_TO_IRIS( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b  \
) \
    k00, k01, k02, k03, k04, k05,                   k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15,                   k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25,                   k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, KC_MPLY, XXXXXXX, k36, k37, k38, k39, k3a, k3b, \
                        k43, k44, k45,     k46,     k47, k48