#pragma once

// layer indices
#define DEF 0
#define QWE 1
#define GME 2
#define SYM 3
#define NAV 4
#define FUN 5
#define MSE 6

// custom keycodes
#define MY_SAFE_RANGE 0xfff0
#define WIN_RT        MY_SAFE_RANGE
#define WIN_LT        MY_SAFE_RANGE+1
#define INV_QM        MY_SAFE_RANGE+2

// non-HRM hold-tap definitions
#define CTL_ESC CTL_T(KC_ESC)
#define NAV_BSP LT(NAV, KC_BSPC)
#define SYM_SPC LT(SYM, KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)
#define GUI_TAB GUI_T(KC_TAB)
#define ALT_DEL RALT_T(KC_DEL)

// home-row mods (DEF)
#define HM_A LCTL_T(KC_A)
#define HM_R LGUI_T(KC_R)
#define HM_S LALT_T(KC_S)
#define HM_T LSFT_T(KC_T)
#define HM_N RSFT_T(KC_N)
#define HM_E RALT_T(KC_E)
#define HM_I RGUI_T(KC_I)
#define HM_O RCTL_T(KC_O)

// home-row mods (QWE)
#define QW_A LCTL_T(KC_A)
#define QW_S LGUI_T(KC_S)
#define QW_D LALT_T(KC_D)
#define QW_F LSFT_T(KC_F)
#define QW_J RSFT_T(KC_J)
#define QW_K RALT_T(KC_K)
#define QW_L RGUI_T(KC_L)
#define QW_QUOT RCTL_T(KC_QUOT)

#define SFT_TAB LSFT_T(KC_TAB)

// mouse activator
#ifdef MOUSEKEY_ENABLE
#    define MS_G LT(MSE, KC_G)
#else
#    define MS_G KC_G
#endif

// navigation shortcuts
#define ALT_F4  A(KC_F4)
#define CTL_F4  C(KC_F4)
#define DSK_LT  C(G(KC_LEFT))
#define DSK_RT  C(G(KC_RGHT))
#define SFT_INS S(KC_INS)
#define TAB_RT  C(KC_TAB)
#define TAB_LT  C(S(KC_TAB))

#define LAYOUT_iris_wrapper(...)       LAYOUT(__VA_ARGS__)
#define LAYOUT_choc_ergo_wrapper(...)  LAYOUT(__VA_ARGS__)
#define LAYOUT_gergoplex_wrapper(...)  LAYOUT_split_3x5_3(__VA_ARGS__)
#define LAYOUT_ffkb_wrapper(...)       LAYOUT_ffkb(__VA_ARGS__)
#define LAYOUT_skelexiao_wrapper(...)  LAYOUT_split_3x5_3(__VA_ARGS__)

#define _DEF \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSLS, \
    KC_ESC,  HM_A,    HM_R,    HM_S,    HM_T,    MS_G,    KC_M,    HM_N,    HM_E,    HM_I,    HM_O,    KC_SCLN, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    _______, _______, _______, GUI_TAB, CTL_ESC, NAV_BSP, SYM_SPC, SFT_ENT, ALT_DEL, _______, _______, _______

#define _QWE \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_ESC,  QW_A,    QW_S,    QW_D,    QW_F,    MS_G,    KC_H,    QW_J,    QW_K,    QW_L,    QW_QUOT, KC_SCLN, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    _______, _______, _______, GUI_TAB, CTL_ESC, NAV_BSP, SYM_SPC, SFT_ENT, ALT_DEL, _______, _______, _______ 

#define _GME \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    _______, _______, _______, KC_LCTL, KC_LALT, KC_SPC,  MO(NAV), KC_ENT,  DF(DEF), _______, _______, _______ 

#define _SYM \
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_BSLS, KC_7,    KC_8,    KC_9,    KC_COMM, _______, \
    KC_LBRC, KC_PLUS, KC_EQL,  KC_UNDS, KC_MINS, KC_CIRC, KC_0,    KC_4,    KC_5,    KC_6,    KC_DOT,  KC_RBRC, \
    _______, XXXXXXX, XXXXXXX, INV_QM,  KC_ASTR, KC_AMPR, KC_SCLN, KC_1,    KC_2,    KC_3,    KC_SLSH, _______, \
    _______, _______, _______, _______, KC_SPC,  _______, _______, _______, _______, _______, _______, _______

#define _NAV \
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
    _______, ALT_F4,  TAB_LT,  TAB_RT,  CTL_F4,  KC_VOLU, XXXXXXX, KC_PGDN, KC_UP,   KC_PGUP, KC_CALC, _______, \
    _______, KC_LCTL, KC_LGUI, KC_LALT, SFT_TAB, KC_VOLD, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, \
    _______, XXXXXXX, WIN_LT,  WIN_RT,  SFT_INS, KC_MPLY, KC_INS,  KC_DEL,  KC_MPRV, KC_MNXT, XXXXXXX, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_LSFT, _______, _______, _______, _______

#define _FUN \
    _______, DF(DEF), DF(QWE), DF(GME), _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, RGB_TOG, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_CAPS, XXXXXXX, DF(DEF), DF(QWE), DF(GME), RGB_MOD, \
    QK_BOOT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD, \
    _______, XXXXXXX, DSK_LT,  DSK_RT,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_PSCR, KC_PAUS, XXXXXXX, _______, \
    _______, _______, _______, QK_BOOT, QK_RBT,  _______, _______, QK_RBT,  QK_BOOT, _______, _______, _______

#define _MSE \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_MS_U, KC_WH_U, KC_WH_R, XXXXXXX, \
    XXXXXXX, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN3, KC_BTN5, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

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

#define C_FFKB(k) L_5x12_TO_FFKB(k)
#define L_5x12_TO_FFKB( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b  \
) \
    XXXXXXX, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, XXXXXXX, \
    XXXXXXX, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, XXXXXXX, \
    XXXXXXX, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, XXXXXXX, \
    XXXXXXX,           k43, k44, k45, k46, k47, k48,           XXXXXXX, \
                                  XXXXXXX

#define C_FFKB_GAMING(k) L_5x12_TO_FFKB_GAMING(k)
#define L_5x12_TO_FFKB_GAMING( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b  \
) \
    XXXXXXX, k10, k11, k12, k13, k14, k16, k17, k18, k19, k1a, XXXXXXX, \
    XXXXXXX, k20, k21, k22, k23, k24, k26, k27, k28, k29, k2a, XXXXXXX, \
    XXXXXXX, k30, k31, k32, k33, k34, k36, k37, k38, k39, k3a, XXXXXXX, \
    XXXXXXX,           k43, k44, k45, k46, k47, k48,           XXXXXXX, \
                                  XXXXXXX

#define C_SKELEXIAO(k) L_5x12_TO_SKELEXIAO(k)
#define L_5x12_TO_SKELEXIAO( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b  \
) \
         k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, \
         k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, \
         k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, \
                   k44, k45, k43, k48, k46, k47

#define C_SKELEXIAO_GAMING(k) L_5x12_TO_SKELEXIAO_GAMING(k)
#define L_5x12_TO_SKELEXIAO_GAMING( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b  \
) \
         k10, k11, k12, k13, k14, k16, k17, k18, k19, k1a, \
         k20, k21, k22, k23, k24, k26, k27, k28, k29, k2a, \
         k30, k31, k32, k33, k34, k36, k37, k38, k39, k3a, \
                   k45, k43, k44, k48, k46, k47
