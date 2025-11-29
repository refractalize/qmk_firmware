#include QMK_KEYBOARD_H
#include "keymap_us_international.h"

#if __has_include("keymap.h")
#    include "keymap.h"
#endif

void keyboard_pre_init_user(void) {
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}

enum layer_names {
    L_NIGHT,
    L_NAV,
    L_SYM,
    L_NUM,
    L_MINI_NAV,
    L_ACCENTS,
};

enum custom_keycodes { // Make sure have the awesome keycode ready
    ALT_TAB = SAFE_RANGE,
    SHIFT_ALT_TAB,
    MOTION_START,
    MOTION_NEXT,
    MOTION_PREV,
    OS_COPY,
    OS_PASTE,
    ACC_A_GRV,
    ACC_E_GRV,
    ACC_U_GRV,
    ACC_O_CIRC,
    ACC_O_UM,
    ACC_I_UM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_NIGHT] = LAYOUT(
        KC_PSCR               , KC_ENT                , KC_UP                 , KC_DOWN               , OS_COPY               , OS_PASTE              ,                                                 KC_6                  , KC_0                  , KC_1                  , KC_2                  , KC_0                  , CW_TOGG               ,
        KC_TAB                , KC_B                  , KC_F                  , LT(L_NUM, KC_L)       , KC_K                  , KC_Q                  ,                                                 KC_P                  , KC_G                  , KC_O                  , KC_U                  , KC_COLN               , KC_BSPC               ,
        LT(L_MINI_NAV, KC_ESC), LGUI_T(KC_N)          , LCTL_T(KC_S)          , LALT_T(KC_H)          , LGUI_T(KC_T)          , KC_M                  ,                                                 KC_Y                  , RGUI_T(KC_C)          , LALT_T(KC_A)          , RCTL_T(KC_E)          , RGUI_T(KC_I)          , RSFT_T(KC_ENT)        ,
        _______               , KC_X                  , KC_V                  , KC_J                  , LT(L_ACCENTS, KC_D)   , KC_Z                  , _______               , _______               , KC_QUOT               , KC_W                  , KC_DOT                , KC_SLSH               , KC_COMM               , _______               ,
                                                        KC_LGUI               , KC_LALT               , KC_LCTL               , LT(L_SYM, KC_MINS)    , LSFT_T(KC_R)          , LSFT_T(KC_SPC)        , LT(L_NAV, KC_UNDS)    , KC_RCTL               , KC_RALT               , KC_RGUI
    ),

    [L_NAV] = LAYOUT(
        _______               , PDF(L_NIGHT)          , PDF(L_NUM)            , _______               , KC_VOLD               , KC_VOLU               ,                                                 KC_MPLY               , KC_MRWD               , KC_MFFD               , KC_MPRV               , KC_MNXT               , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , KC_HOME               , KC_UP                 , KC_END                , _______               , _______               ,
        _______               , KC_LEFT_GUI           , KC_LEFT_CTRL          , KC_LEFT_ALT           , KC_LEFT_GUI           , _______               ,                                                 _______               , KC_LEFT               , KC_DOWN               , KC_RGHT               , _______               , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , SHIFT_ALT_TAB         , ALT_TAB               , _______               , _______               , _______               ,
                                                        _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______
    ),

    [L_SYM] = LAYOUT(
        KC_F1                 , KC_F2                 , KC_F3                 , KC_F4                 , KC_F5                 , KC_F6                 ,                                                 KC_F7                 , KC_F8                 , KC_F9                 , KC_F10                , KC_F11                , KC_F12                ,
        _______               , KC_PERC               , KC_DLR                , KC_LCBR               , KC_RCBR               , KC_TILD               ,                                                 KC_CIRC               , KC_LABK               , KC_RABK               , KC_MINS               , KC_AMPR               , _______               ,
        _______               , LGUI_T(KC_AT)         , LCTL_T(KC_MINS)       , LALT_T(KC_LPRN)       , LGUI_T(KC_RPRN)       , KC_PLUS               ,                                                 KC_EXLM               , RGUI_T(KC_EQL)        , LALT_T(KC_COLN)       , RCTL_T(KC_DQUO)       , KC_SCLN               , _______               ,
        _______               , KC_BSLS               , KC_SLSH               , KC_LBRC               , KC_RBRC               , KC_HASH               , _______               , _______               , KC_QUES               , KC_ASTR               , KC_PIPE               , KC_GRV                , KC_QUOT               , _______               ,
                                                        _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______
    ),

    [L_NUM] = LAYOUT(
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , KC_7                  , KC_8                  , KC_9                  , _______               , _______               ,
        _______               , KC_LEFT_GUI           , KC_LEFT_CTRL          , KC_LEFT_ALT           , KC_LEFT_GUI           , _______               ,                                                 _______               , RGUI_T(KC_0)          , LALT_T(KC_1)          , RCTL_T(KC_2)          , RGUI_T(KC_3)          , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , KC_4                  , KC_5                  , KC_6                  , _______               , _______               ,
                                                        _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______
    ),

    [L_MINI_NAV] = LAYOUT(
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , C(KC_PGUP)            , KC_UP                 , C(KC_PGDN)            , _______               ,                                                 _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , OS_COPY               , KC_DOWN               , OS_PASTE              , _______               ,                                                 _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , _______               , SHIFT_ALT_TAB         , ALT_TAB               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               ,
                                                        _______               , _______               , _______               , KC_BSPC               , KC_ENT                , _______               , _______               , _______               , _______               , _______
    ),

    [L_ACCENTS] = LAYOUT(
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , ACC_O_UM              , ACC_O_CIRC            , ACC_U_GRV             , RALT(KC_DQUO)         , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , US_CCED               , ACC_A_GRV             , US_EACU               , ACC_I_UM              , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , ACC_E_GRV             , _______               , _______               , _______               , _______               ,
                                                        _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______               , _______
    ),
};

bool is_flow_tap_key(uint16_t keycode) {
    uint8_t highest_layer = get_highest_layer(default_layer_state);

    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        case KC_SPC:
        case KC_R:
        case KC_D:
            return highest_layer != L_NIGHT;
        case KC_A ... KC_C:
        case KC_E ... KC_Q:
        case KC_S ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SLSH:
            return true;
    }
    return false;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [L_NIGHT] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MRWD, KC_MFFD)},
    [L_NAV] = {ENCODER_CCW_CW(UG_HUED, UG_HUEU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [L_SYM] = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(UG_SATD, UG_SATU)},
    [L_NUM] = {ENCODER_CCW_CW(UG_VALD, UG_VALU), ENCODER_CCW_CW(UG_SPDD, UG_SPDU)},
    [L_MINI_NAV] = {ENCODER_CCW_CW(UG_VALD, UG_VALU), ENCODER_CCW_CW(UG_SPDD, UG_SPDU)},
    [L_ACCENTS] = {ENCODER_CCW_CW(UG_VALD, UG_VALU), ENCODER_CCW_CW(UG_SPDD, UG_SPDU)},
};
#endif

const uint16_t PROGMEM browser_forward_combo[] = {KC_DOWN, KC_RGHT, COMBO_END};
const uint16_t PROGMEM browser_back_combo[] = {KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM browser_refresh_combo[] = {KC_LEFT, KC_RGHT, COMBO_END};

combo_t key_combos[]   = {
    COMBO(browser_forward_combo, KC_WFWD),
    COMBO(browser_back_combo, KC_WBAK),
    COMBO(browser_refresh_combo, KC_WREF),
};

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
};

uint16_t os_cmd_or_ctrl(void) {
    switch (detected_host_os()) {
        case OS_MACOS:
        case OS_IOS:
            return QK_LGUI;
        case OS_WINDOWS:
        case OS_LINUX:
        case OS_UNSURE:
        default:
            return QK_LCTL;
    }
}

uint8_t os_tab_or_cmd(void) {
    switch (detected_host_os()) {
        case OS_MACOS:
        case OS_IOS:
            return KC_LGUI;
        case OS_WINDOWS:
        case OS_LINUX:
        case OS_UNSURE:
        default:
            return KC_LALT;
    }
}

bool is_alt_tab_active = false;

// from https://www.reddit.com/r/MechanicalKeyboards/comments/mrnxrj/better_super_alttab/
layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_alt_tab_active) {
        unregister_code(os_tab_or_cmd());
        is_alt_tab_active = false;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_TAB: // super alt tab macro
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(os_tab_or_cmd());
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case SHIFT_ALT_TAB: // super alt tab macro
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(os_tab_or_cmd());
                }
                register_code16(S(KC_TAB));
            } else {
                unregister_code16(S(KC_TAB));
            }
            break;
        case OS_COPY:
            if (record->event.pressed) {
                tap_code16(os_cmd_or_ctrl() | KC_C);
            }
            return false;
        case OS_PASTE:
            if (record->event.pressed) {
                tap_code16(os_cmd_or_ctrl() | KC_V);
            }
            return false;
        case ACC_A_GRV:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("`") "a");
            }
            break;
        case ACC_E_GRV:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("`") "e");
            }
            break;
        case ACC_U_GRV:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("`") "u");
            }
            break;
        case ACC_O_CIRC:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("6") "o");
            }
            break;
        case ACC_O_UM:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("\"") "o");
            }
            break;
        case ACC_I_UM:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("\"") "i");
            }
            break;
        case MOTION_START:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("n") "s");
            }
            break;
        case MOTION_NEXT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("n") "]");
            }
            break;
        case MOTION_PREV:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("n") "[");
            }
            break;
        case LSFT_T(KC_COLN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_COLN);
                return false;
            }
            break;
        case LT(L_NAV, KC_UNDS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;
        case LGUI_T(KC_AT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_AT);
                return false;
            }
            break;
        case LALT_T(KC_LPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;
        case LGUI_T(KC_RPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;
        case RGUI_T(KC_EQL):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_EQL);
                return false;
            }
            break;
        case RALT_T(KC_UNDS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;
        case RCTL_T(KC_DQUO):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DQUO);
                return false;
            }
            break;
    }
    return true;
}

bool rgb_matrix_indicators_user(void) {
    uint8_t highest_layer = get_highest_layer(default_layer_state);

    switch (highest_layer) {
        case L_NIGHT:
            rgb_matrix_set_color(4, 255, 255, 255);
            break;
        case L_NUM:
            rgb_matrix_set_color(3, 255, 255, 255);
            break;
        default:
            break;
    }

    return false;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    if (QK_MOD_TAP | keycode || QK_LAYER_TAP | keycode) {
        return 0;
    }

    return QUICK_TAP_TERM;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(L_NAV, KC_UNDS):
        case LSFT_T(KC_COLN):
        case LT(L_SYM, KC_MINS):
            // Make sure we always prefer the hold actions for these keys.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    if (get_highest_layer(default_layer_state) == L_NIGHT) {
        switch (keycode) {
            case LSFT_T(KC_R):
            case LSFT_T(KC_SPC):
            case LT(L_ACCENTS, KC_D):
            case LT(L_NUM, KC_L):
                return true;
        }
    }
    return false;
}
