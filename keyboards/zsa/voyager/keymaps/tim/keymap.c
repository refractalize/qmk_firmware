// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_us_international.h"

enum layer_names {
    L_NIGHT,
    L_QWERTY,
    L_NAV,
    L_SYM,
    L_NUM,
    L_MINI_NAV,
    L_BROWSER,
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
};

enum tap_dance_codes {
    TD_OSS_BROWSER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_NIGHT] = LAYOUT(
        KC_PSCR               , KC_ENT                , OS_COPY               , OS_PASTE              , KC_VOLD               , KC_VOLU               ,                                                 KC_MPLY               , KC_MRWD               , KC_MFFD               , KC_MPRV               , KC_MNXT               , _______               ,
        KC_TAB                , KC_B                  , KC_F                  , KC_L                  , KC_K                  , KC_Q                  ,                                                 KC_P                  , KC_G                  , KC_O                  , KC_U                  , KC_COLN               , KC_BSPC               ,
        LT(L_MINI_NAV, KC_ESC), LGUI_T(KC_N)          , LCTL_T(KC_S)          , LALT_T(KC_H)          , LGUI_T(KC_T)          , KC_M                  ,                                                 KC_Y                  , RGUI_T(KC_C)          , LALT_T(KC_A)          , RCTL_T(KC_E)          , RGUI_T(KC_I)          , RSFT_T(KC_ENT)        ,
        MO(L_BROWSER)         , KC_X                  , KC_V                  , KC_J                  , LT(L_ACCENTS, KC_D)   , KC_Z                  ,                                                 KC_QUOT               , KC_W                  , KC_DOT                , KC_SLSH               , KC_COMM               , _______               ,
                                                                                                        TD(TD_OSS_BROWSER)    , LT(L_SYM, KC_R)       ,                                                 LSFT_T(KC_SPC)        , LT(L_NAV, KC_UNDS)
    ),

    [L_QWERTY] = LAYOUT(
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , KC_Q                  , KC_W                  , LT(L_NUM, KC_E)       , KC_R                  , KC_T                  ,                                                 KC_Y                  , KC_U                  , KC_I                  , KC_O                  , KC_P                  , _______               ,
        _______               , LGUI_T(KC_A)          , LCTL_T(KC_S)          , LALT_T(KC_D)          , LGUI_T(KC_F)          , KC_G                  ,                                                 KC_H                  , RGUI_T(KC_J)          , LALT_T(KC_K)          , RCTL_T(KC_L)          , RGUI_T(KC_SCLN)       , _______               ,
        _______               , KC_Z                  , KC_X                  , KC_C                  , LT(L_ACCENTS, KC_V)   , KC_B                  ,                                                 KC_N                  , KC_M                  , KC_COMM               , KC_DOT                , KC_SLSH               , _______               ,
                                                                                                        _______               , KC_LEFT_SHIFT         ,                                                 _______               , _______
    ),

    [L_NAV] = LAYOUT(
        _______               , PDF(L_NIGHT)          , PDF(L_QWERTY)         , PDF(L_NUM)            , _______               , _______               ,                                                 KC_MPLY               , KC_MRWD               , KC_MFFD               , KC_MPRV               , KC_MNXT               , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 KC_PGUP               , KC_HOME               , KC_UP                 , KC_END                , _______               , _______               ,
        _______               , OS_LGUI               , OS_LCTL               , OS_LALT               , OS_LGUI               , _______               ,                                                 KC_PGDN               , KC_LEFT               , KC_DOWN               , KC_RGHT               , _______               , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , _______               , _______               , _______               , _______               , _______               ,
                                                                                                        _______               , _______               ,                                                 _______               , _______
    ),

    [L_SYM] = LAYOUT(
        KC_F1                 , KC_F2                 , KC_F3                 , KC_F4                 , KC_F5                 , KC_F6                 ,                                                 KC_F7                 , KC_F8                 , KC_F9                 , KC_F10                , KC_F11                , KC_F12                ,
        _______               , KC_PERC               , KC_DLR                , KC_LCBR               , KC_RCBR               , KC_TILD               ,                                                 KC_CIRC               , KC_LABK               , KC_RABK               , KC_MINS               , KC_AMPR               , _______               ,
        _______               , LGUI_T(KC_AT)         , LCTL_T(KC_DQUO)       , LALT_T(KC_LPRN)       , LGUI_T(KC_RPRN)       , KC_PLUS               ,                                                 KC_EXLM               , RGUI_T(KC_LBRC)       , LALT_T(KC_RBRC)       , RCTL_T(KC_EQL)        , KC_SCLN               , _______               ,
        _______               , KC_BSLS               , KC_SLSH               , KC_LBRC               , KC_HASH               , KC_HASH               ,                                                 KC_QUES               , KC_ASTR               , KC_PIPE               , KC_GRV                , KC_QUOT               , _______               ,
                                                                                                        _______               , _______               ,                                                 _______               , _______
    ),

    [L_NUM] = LAYOUT(
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , KC_7                  , KC_8                  , KC_9                  , KC_MINS               , KC_DEL                ,
        _______               , KC_LEFT_GUI           , KC_LEFT_CTRL          , KC_LEFT_ALT           , KC_LEFT_GUI           , _______               ,                                                 _______               , RGUI_T(KC_1)          , LALT_T(KC_2)          , RCTL_T(KC_3)          , KC_DOT                , S(KC_ENT)             ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , KC_4                  , KC_5                  , KC_6                  , KC_COMM               , _______               ,
                                                                                                        _______               , _______               ,                                                 _______               , LT(L_NAV, KC_0)
    ),

    [L_MINI_NAV] = LAYOUT(
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , C(KC_W)               , SHIFT_ALT_TAB         , ALT_TAB               , _______               ,                                                 _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , OS_COPY_SHIFT         , OS_COPY               , OS_PASTE              , _______               ,                                                 _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , _______               , C(KC_PGUP)            , C(KC_PGDN)            , _______               ,                                                 _______               , _______               , _______               , _______               , _______               , _______               ,
                                                                                                        C(S(KC_A))            , KC_ENT                ,                                                 _______               , _______
    ),

    [L_BROWSER] = LAYOUT(
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , C(KC_PGUP)            , KC_UP                 , C(KC_W)               , _______               ,                                                 _______               , KC_7                  , KC_8                  , KC_9                  , KC_MINS               , KC_DEL                ,
        KC_ENT                , _______               , C(KC_PGDN)            , KC_DOWN               , C(KC_T)               , _______               ,                                                 _______               , RGUI_T(KC_1)          , LALT_T(KC_2)          , RCTL_T(KC_3)          , KC_DOT                , S(KC_ENT)             ,
        _______               , _______               , _______               , _______               , C(S(KC_A))            , _______               ,                                                 _______               , KC_4                  , KC_5                  , KC_6                  , KC_COMM               , _______               ,
                                                                                                        _______               , _______               ,                                                 _______               , KC_0
    ),

    [L_ACCENTS] = LAYOUT(
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , ACC_O_UM              , ACC_O_CIRC            , ACC_U_GRV             , RALT(KC_DQUO)         , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , US_CCED               , ACC_A_GRV             , US_EACU               , ACC_I_UM              , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                                                 _______               , ACC_E_GRV             , _______               , _______               , _______               , _______               ,
                                                                                                        _______               , _______               ,                                                 _______               , _______
    ),
};

const uint16_t PROGMEM browser_forward_combo[] = {KC_DOWN, C(KC_T), COMBO_END};
const uint16_t PROGMEM browser_back_combo[] = {C(KC_PGDN), KC_DOWN, COMBO_END};
const uint16_t PROGMEM browser_refresh_combo[] = {C(KC_PGDN), C(KC_T), COMBO_END};
const uint16_t PROGMEM dj_exclamaition[] = {LT(L_ACCENTS, KC_D), KC_J, COMBO_END};
const uint16_t PROGMEM vj_at[] = {KC_V, KC_J, COMBO_END};

combo_t key_combos[]   = {
    COMBO(browser_forward_combo, KC_WFWD),
    COMBO(browser_back_combo, KC_WBAK),
    COMBO(browser_refresh_combo, KC_WREF),
    COMBO(dj_exclamaition, KC_EXLM),
    COMBO(vj_at, KC_AT),
};

const key_override_t colon_mins_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_MINS);
const key_override_t dot_exclaimation_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t comma_at_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_AT);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &colon_mins_override,
    &dot_exclaimation_override,
    &comma_at_override,
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

typedef enum {
    OSS_BROWSER_STATE_NONE,
    OSS_BROWSER_STATE_UNKNOWN,
    OSS_BROWSER_STATE_TAP,
    OSS_BROWSER_STATE_DOUBLE_TAP,
    OSS_BROWSER_STATE_HOLD,
} oss_browser_state_t;

static oss_browser_state_t oss_browser_state;

oss_browser_state_t oss_browser_cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->finished) return OSS_BROWSER_STATE_NONE;
        if (state->interrupted || !state->pressed) return OSS_BROWSER_STATE_TAP;
        return OSS_BROWSER_STATE_HOLD;
    }
    if (state->count == 2) {
        if (state->interrupted || !state->pressed) return OSS_BROWSER_STATE_DOUBLE_TAP;
        return OSS_BROWSER_STATE_HOLD;
    }
    return OSS_BROWSER_STATE_UNKNOWN;
}

void oss_browser_finished(tap_dance_state_t *state, void *user_data) {
    oss_browser_state = oss_browser_cur_dance(state);
    switch (oss_browser_state) {
        case OSS_BROWSER_STATE_TAP:
            add_oneshot_mods(MOD_BIT(KC_LSFT));
            break;
        case OSS_BROWSER_STATE_DOUBLE_TAP:
            caps_word_on();
            break;
        case OSS_BROWSER_STATE_HOLD:
            layer_on(L_BROWSER);
            break;
        default:
            break;
    }
}

void oss_browser_reset(tap_dance_state_t *state, void *user_data) {
    if (oss_browser_state == OSS_BROWSER_STATE_HOLD) {
        layer_off(L_BROWSER);
    }
    oss_browser_state = OSS_BROWSER_STATE_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_OSS_BROWSER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, oss_browser_finished, oss_browser_reset),
};

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
    uint8_t highest_default_layer = get_highest_layer(default_layer_state);

    switch (highest_default_layer) {
        case L_NIGHT:
            rgb_matrix_set_color(1, 255, 255, 255);
            break;
        case L_QWERTY:
            rgb_matrix_set_color(2, 255, 255, 255);
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
            case LSFT_T(KC_SPC):
            case LT(L_ACCENTS, KC_D):
            case LT(L_NUM, KC_L):
                return true;
        }
    }
    return false;
}
