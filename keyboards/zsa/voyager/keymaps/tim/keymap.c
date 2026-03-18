// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_us_international.h"

#define MT_OSM_SHIFT LT(L_MINI_NAV, KC_0)
#define MT_R LT(L_SYM, KC_R)
#define MT_SPACE LSFT_T(KC_SPC)
#define MT_UNDS LT(L_NAV, KC_UNDS)

enum layer_names {
    L_NIGHT,
    L_NAV,
    L_SYM,
    L_MINI_NAV,
    L_ACCENTS,
};

enum custom_keycodes { // Make sure have the awesome keycode ready
    ALT_TAB = SAFE_RANGE,
    SHIFT_ALT_TAB,
    OS_COPY,
    OS_COPY_SHIFT,
    OS_PASTE,
    ACC_A_GRV,
    ACC_E_GRV,
    ACC_U_GRV,
    ACC_O_CIRC,
    ACC_O_UM,
    ACC_I_UM,

    SEND_DOTSLASH,
    SEND_DOTDOTSLASH,
    SEND_EQUALS_RABK,
    SEND_MINS_RABK,
};

enum tap_dance_codes {
    TD_OSS_BROWSER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_NIGHT] = LAYOUT(
        KC_PSCR               , LGUI(KC_1)            , LGUI(KC_2)            , LGUI(KC_3)            , KC_VOLD               , KC_VOLU               ,                         KC_MPLY               , KC_MRWD               , KC_MFFD               , KC_MPRV               , KC_MNXT               , KC_DEL                ,
        KC_TAB                , KC_B                  , KC_F                  , KC_L                  , KC_K                  , KC_Q                  ,                         KC_P                  , KC_G                  , KC_O                  , KC_U                  , KC_COLN               , KC_BSPC               ,
        LT(L_MINI_NAV, KC_ESC), LGUI_T(KC_N)          , LCTL_T(KC_S)          , LALT_T(KC_H)          , LGUI_T(KC_T)          , KC_M                  ,                         KC_Y                  , RGUI_T(KC_C)          , LALT_T(KC_A)          , RCTL_T(KC_E)          , RGUI_T(KC_I)          , RSFT_T(KC_ENT)        ,
        LSFT_T(KC_SLSH)       , KC_X                  , KC_V                  , KC_J                  , LT(L_ACCENTS, KC_D)   , KC_Z                  ,                         KC_QUOT               , KC_W                  , KC_DOT                , KC_MINS               , KC_COMM               , KC_SLSH               ,
                                                                                                        MT_OSM_SHIFT          , MT_R                  ,                         MT_SPACE              , MT_UNDS
    ),

    [L_NAV] = LAYOUT(
        _______               , LGUI(KC_1)            , LGUI(KC_2)            , LGUI(KC_3)            , LGUI(KC_4)            , LGUI(KC_5)            ,                         LGUI(KC_6)            , LGUI(KC_7)            , LGUI(KC_8)            , LGUI(KC_9)            , LGUI(KC_0)            , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                         KC_PGUP               , KC_HOME               , KC_UP                 , KC_END                , _______               , _______               ,
        _______               , KC_LGUI               , KC_LCTL               , KC_LALT               , KC_LGUI               , _______               ,                         KC_PGDN               , KC_LEFT               , KC_DOWN               , KC_RGHT               , _______               , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                         _______               , _______               , _______               , _______               , _______               , _______               ,
                                                                                                        KC_LSFT               , _______               ,                         _______               , _______
    ),

    [L_SYM] = LAYOUT(
        KC_F1                 , KC_F2                 , KC_F3                 , KC_F4                 , KC_F5                 , KC_F6                 ,                         KC_F7                 , KC_F8                 , KC_F9                 , KC_F10                , KC_F11                , KC_F12                ,
        _______               , KC_PERC               , KC_DLR                , KC_LCBR               , KC_RCBR               , KC_TILD               ,                         KC_CIRC               , KC_LABK               , KC_RABK               , KC_MINS               , KC_AMPR               , _______               ,
        _______               , LGUI_T(KC_AT)         , LCTL_T(KC_DQUO)       , LALT_T(KC_LPRN)       , LGUI_T(KC_RPRN)       , KC_PLUS               ,                         KC_EXLM               , RGUI_T(KC_LBRC)       , LALT_T(KC_RBRC)       , RCTL_T(KC_EQL)        , KC_SCLN               , _______               ,
        _______               , KC_BSLS               , KC_SLSH               , KC_LBRC               , KC_HASH               , KC_HASH               ,                         KC_QUES               , KC_ASTR               , KC_PIPE               , KC_GRV                , KC_QUOT               , _______               ,
                                                                                                        _______               , _______               ,                         _______               , _______
    ),

    [L_MINI_NAV] = LAYOUT(
        _______               , LGUI(KC_1)            , LGUI(KC_2)            , LGUI(KC_3)            , LGUI(KC_4)            , LGUI(KC_5)            ,                         LGUI(KC_6)            , LGUI(KC_7)            , LGUI(KC_8)            , LGUI(KC_9)            , LGUI(KC_0)            , _______               ,
        _______               , _______               , C(KC_W)               , SHIFT_ALT_TAB         , ALT_TAB               , KC_UP                 ,                         _______               , KC_7                  , KC_8                  , KC_9                  , KC_MINS               , _______               ,
        KC_ENT                , _______               , OS_COPY_SHIFT         , OS_COPY               , OS_PASTE              , KC_DOWN               ,                         KC_PLUS               , RGUI_T(KC_1)          , LALT_T(KC_2)          , RCTL_T(KC_3)          , KC_DOT                , _______               ,
        _______               , _______               , _______               , C(KC_PGUP)            , C(KC_PGDN)            , C(S(KC_A))            ,                         _______               , KC_4                  , KC_5                  , KC_6                  , KC_COMM               , _______               ,
                                                                                                        C(S(KC_A))            , KC_ENT                ,                         KC_0                  , KC_0
    ),

    [L_ACCENTS] = LAYOUT(
        _______               , _______               , _______               , _______               , _______               , _______               ,                         _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                         _______               , ACC_O_UM              , ACC_O_CIRC            , ACC_U_GRV             , RALT(KC_DQUO)         , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                         _______               , US_CCED               , ACC_A_GRV             , US_EACU               , ACC_I_UM              , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                         _______               , ACC_E_GRV             , _______               , _______               , _______               , _______               ,
                                                                                                        _______               , _______               ,                         _______               , _______
    ),
};

const uint16_t PROGMEM browser_forward_combo[] = {KC_DOWN, C(KC_T), COMBO_END};
const uint16_t PROGMEM browser_back_combo[] = {C(KC_PGDN), KC_DOWN, COMBO_END};
const uint16_t PROGMEM browser_refresh_combo[] = {C(KC_PGDN), C(KC_T), COMBO_END};
const uint16_t PROGMEM lk_combo[] = {KC_L, KC_K, COMBO_END};
const uint16_t PROGMEM dj_combo[] = {LT(L_ACCENTS, KC_D), KC_J, COMBO_END};
const uint16_t PROGMEM vj_combo[] = {KC_V, KC_J, COMBO_END};
const uint16_t PROGMEM go_combo[] = {KC_G, KC_O, COMBO_END};
const uint16_t PROGMEM w_dot_combo[] = {KC_W, KC_DOT, COMBO_END};
const uint16_t PROGMEM dot_mins_combo[] = {KC_DOT, KC_MINS, COMBO_END};
const uint16_t PROGMEM labk_rabk_combo[] = {KC_LABK, KC_RABK, COMBO_END};
const uint16_t PROGMEM rabk_mins_combo[] = {KC_RABK, KC_MINS, COMBO_END};

combo_t key_combos[]   = {
    COMBO(browser_forward_combo, KC_WFWD),
    COMBO(browser_back_combo, KC_WBAK),
    COMBO(browser_refresh_combo, KC_WREF),
    COMBO(lk_combo, KC_PERC),
    COMBO(dj_combo, KC_SLSH),
    // COMBO(vj_combo, KC_PERC),
    // COMBO(go_combo, KC_ASTR),
    COMBO(w_dot_combo, SEND_DOTDOTSLASH),
    COMBO(dot_mins_combo, SEND_DOTSLASH),
    COMBO(labk_rabk_combo, SEND_EQUALS_RABK),
    COMBO(rabk_mins_combo, SEND_MINS_RABK),
};

const key_override_t dot_exclaimation_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t comma_at_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_AT);
const key_override_t mins_question_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_QUES);
const key_override_t colon_slash_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SLSH);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &dot_exclaimation_override,
    &comma_at_override,
    &mins_question_override,
    &colon_slash_override,
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

        case MT_OSM_SHIFT:
            if (record->tap.count) {
                if (record->event.pressed) {
                    add_oneshot_mods(MOD_BIT(KC_LSFT));
                }
                return false;
            }
            break;
        case OS_COPY:
            if (record->event.pressed) {
                tap_code16(os_cmd_or_ctrl() | KC_C);
            }
            return false;
        case OS_COPY_SHIFT:
            if (record->event.pressed) {
                tap_code16(os_cmd_or_ctrl() | QK_LSFT | KC_C);
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
        case MT_UNDS:
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
        case MT_SPACE:
            if (record->tap.count && record->event.pressed) {
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    clear_oneshot_mods();
                    caps_word_on();
                    return false;
                }
            }
            break;
        case SEND_DOTSLASH:
            if (record->event.pressed) {
                SEND_STRING("./");
                return false;
            }
            break;
        case SEND_DOTDOTSLASH:
            if (record->event.pressed) {
                SEND_STRING("../");
                return false;
            }
            break;
        case SEND_EQUALS_RABK:
            if (record->event.pressed) {
                SEND_STRING("=>");
                return false;
            }
            break;
        case SEND_MINS_RABK:
            if (record->event.pressed) {
                SEND_STRING("->");
                return false;
            }
            break;
    }
    return true;
}

bool rgb_matrix_indicators_user(void) {
    uint8_t highest_default_layer = get_highest_layer(default_layer_state);

    switch (highest_default_layer) {
        case L_NIGHT:
            rgb_matrix_set_color(1, 255, 255, 255);
            break;
        case L_NAV:
            rgb_matrix_set_color(2, 255, 255, 255);
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
        case MT_UNDS:
            // Make sure we always prefer the hold actions for these keys.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    uint8_t highest_default_layer = get_highest_layer(default_layer_state);

    if (highest_default_layer == L_NIGHT) {
        switch (keycode) {
            case MT_SPACE:
            case LT(L_ACCENTS, KC_D):
            case MT_R:
                return true;
        }
    }
    return false;
}
