// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_us_international.h"

enum layer_names {
    L_NIGHT,
    L_MAGIC,
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
    MAGIC_OULD,
    MAGIC_TION,
    MAGIC_SENT,
    MAGIC_GHT,
    MAGIC_TENT,
    MAGIC_MENT,
    MAGIC_DENT,
    MAGIC_VE,
    MAGIC_ING,
    MAGIC_ERE,
    MAGIC_THE,
    MAGIC_PRO,
    MAGIC_YOU,
    MAGIC_JECT,
    MAGIC_DOTSLASH,
    MAGIC_AGE,
};

enum tap_dance_codes {
    TD_OSS_BROWSER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_NIGHT] = LAYOUT(
        KC_PSCR               , _______               , _______               , _______               , KC_VOLD               , KC_VOLU               ,                         KC_MPLY               , KC_MRWD               , KC_MFFD               , KC_MPRV               , KC_MNXT               , _______               ,
        KC_TAB                , KC_B                  , KC_F                  , KC_L                  , KC_K                  , KC_Q                  ,                         KC_P                  , KC_G                  , KC_O                  , KC_U                  , KC_COLN               , KC_BSPC               ,
        LT(L_MINI_NAV, KC_ESC), LGUI_T(KC_N)          , LCTL_T(KC_S)          , LALT_T(KC_H)          , LGUI_T(KC_T)          , KC_M                  ,                         KC_Y                  , RGUI_T(KC_C)          , LALT_T(KC_A)          , RCTL_T(KC_E)          , RGUI_T(KC_I)          , RSFT_T(KC_ENT)        ,
        LSFT_T(KC_SLSH)       , KC_X                  , KC_V                  , KC_J                  , LT(L_ACCENTS, KC_D)   , KC_Z                  ,                         KC_QUOT               , KC_W                  , KC_DOT                , OSL(L_MAGIC)          , KC_COMM               , KC_MINS               ,
                                                                                                        TD(TD_OSS_BROWSER)    , LT(L_SYM, KC_R)       ,                         LSFT_T(KC_SPC)        , LT(L_NAV, KC_UNDS)
    ),

    [L_MAGIC] = LAYOUT(
        _______               , _______               , _______               , _______               , _______               , _______               ,                         _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , _______               , MAGIC_OULD            , _______               , _______               ,                         MAGIC_PRO             , _______               , _______               , _______               , _______               , _______               ,
        _______               , MAGIC_TION            , MAGIC_SENT            , MAGIC_GHT             , MAGIC_TENT            , MAGIC_MENT            ,                         MAGIC_YOU             , _______               , MAGIC_AGE             , _______               , _______               , _______               ,
        _______               , _______               , _______               , MAGIC_JECT            , MAGIC_DENT            , _______               ,                         MAGIC_VE              , MAGIC_ING             , MAGIC_DOTSLASH        , KC_SLSH               , _______               , _______               ,
                                                                                                        _______               , MAGIC_ERE             ,                         MAGIC_THE             , _______
    ),

    [L_NAV] = LAYOUT(
        _______               , PDF(L_NIGHT)          , PDF(L_BROWSER)        , _______               , _______               , _______               ,                         _______               , _______               , _______               , _______               , _______               , _______               ,
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

    [L_NUM] = LAYOUT(
        _______               , _______               , _______               , _______               , _______               , _______               ,                         _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                         _______               , KC_7                  , KC_8                  , KC_9                  , KC_MINS               , KC_DEL                ,
        _______               , KC_LEFT_GUI           , KC_LEFT_CTRL          , KC_LEFT_ALT           , KC_LEFT_GUI           , _______               ,                         _______               , RGUI_T(KC_1)          , LALT_T(KC_2)          , RCTL_T(KC_3)          , KC_DOT                , S(KC_ENT)             ,
        _______               , _______               , _______               , _______               , _______               , _______               ,                         _______               , KC_4                  , KC_5                  , KC_6                  , KC_COMM               , _______               ,
                                                                                                        _______               , _______               ,                         _______               , LT(L_NAV, KC_0)
    ),

    [L_MINI_NAV] = LAYOUT(
        _______               , _______               , _______               , _______               , _______               , _______               ,                         _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , C(KC_W)               , SHIFT_ALT_TAB         , ALT_TAB               , _______               ,                         _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , OS_COPY_SHIFT         , OS_COPY               , OS_PASTE              , _______               ,                         _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , _______               , C(KC_PGUP)            , C(KC_PGDN)            , _______               ,                         _______               , _______               , _______               , _______               , _______               , _______               ,
                                                                                                        C(S(KC_A))            , KC_ENT                ,                         _______               , _______
    ),

    [L_BROWSER] = LAYOUT(
        _______               , _______               , _______               , _______               , _______               , _______               ,                         _______               , _______               , _______               , _______               , _______               , _______               ,
        _______               , _______               , C(KC_PGUP)            , KC_UP                 , C(KC_W)               , _______               ,                         _______               , KC_7                  , KC_8                  , KC_9                  , KC_MINS               , _______               ,
        KC_ENT                , _______               , C(KC_PGDN)            , KC_DOWN               , C(KC_T)               , _______               ,                         KC_PLUS               , RGUI_T(KC_1)          , LALT_T(KC_2)          , RCTL_T(KC_3)          , KC_DOT                , _______               ,
        _______               , _______               , _______               , _______               , C(S(KC_A))            , _______               ,                         _______               , KC_4                  , KC_5                  , KC_6                  , KC_COMM               , _______               ,
                                                                                                        _______               , _______               ,                         _______               , KC_0
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
const uint16_t PROGMEM dj_exclamaition[] = {LT(L_ACCENTS, KC_D), KC_J, COMBO_END};
const uint16_t PROGMEM vj_at[] = {KC_V, KC_J, COMBO_END};

combo_t key_combos[]   = {
    COMBO(browser_forward_combo, KC_WFWD),
    COMBO(browser_back_combo, KC_WBAK),
    COMBO(browser_refresh_combo, KC_WREF),
    COMBO(dj_exclamaition, KC_EXLM),
    COMBO(vj_at, KC_AT),
};

const key_override_t dot_exclaimation_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t comma_at_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_AT);
const key_override_t shift_magic_question = ko_make_basic(MOD_MASK_SHIFT, OSL(L_MAGIC), KC_QUES);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &dot_exclaimation_override,
    &comma_at_override,
    &shift_magic_question,
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
    OSS_BROWSER_STATE_HOLD,
} oss_browser_state_t;

static oss_browser_state_t oss_browser_state;

oss_browser_state_t oss_browser_cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->finished) return OSS_BROWSER_STATE_NONE;
        if (state->interrupted || !state->pressed) return OSS_BROWSER_STATE_TAP;
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
        case LSFT_T(KC_SPC):
            if (record->tap.count && record->event.pressed) {
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    clear_oneshot_mods();
                    caps_word_on();
                    return false;
                }
            }
            break;
        case MAGIC_OULD:
            if (record->event.pressed) {
                SEND_STRING("ould");
                return false;
            }
            break;
        case MAGIC_TION:
            if (record->event.pressed) {
                SEND_STRING("tion");
                return false;
            }
            break;
        case MAGIC_SENT:
            if (record->event.pressed) {
                SEND_STRING("sent");
                return false;
            }
            break;
        case MAGIC_GHT:
            if (record->event.pressed) {
                SEND_STRING("ght");
                return false;
            }
            break;
        case MAGIC_TENT:
            if (record->event.pressed) {
                SEND_STRING("tent");
                return false;
            }
            break;
        case MAGIC_MENT:
            if (record->event.pressed) {
                SEND_STRING("ment");
                return false;
            }
            break;
        case MAGIC_DENT:
            if (record->event.pressed) {
                SEND_STRING("dent");
                return false;
            }
            break;
        case MAGIC_VE:
            if (record->event.pressed) {
                SEND_STRING("'ve");
                return false;
            }
            break;
        case MAGIC_ING:
            if (record->event.pressed) {
                SEND_STRING("ing");
                return false;
            }
            break;
        case MAGIC_ERE:
            if (record->event.pressed) {
                SEND_STRING("ere");
                return false;
            }
            break;
        case MAGIC_THE:
            if (record->event.pressed) {
                SEND_STRING("the ");
                return false;
            }
            break;
        case MAGIC_PRO:
            if (record->event.pressed) {
                SEND_STRING("pro");
                return false;
            }
            break;
        case MAGIC_YOU:
            if (record->event.pressed) {
                SEND_STRING("you");
                return false;
            }
            break;
        case MAGIC_JECT:
            if (record->event.pressed) {
                SEND_STRING("ject");
                return false;
            }
            break;
        case MAGIC_DOTSLASH:
            if (record->event.pressed) {
                SEND_STRING("../");
                return false;
            }
            break;
        case MAGIC_AGE:
            if (record->event.pressed) {
                SEND_STRING("age");
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
        case L_NUM:
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
        case LT(L_NAV, KC_UNDS):
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
            case LSFT_T(KC_SPC):
            case LT(L_ACCENTS, KC_D):
                return true;
        }
    }
    return false;
}
