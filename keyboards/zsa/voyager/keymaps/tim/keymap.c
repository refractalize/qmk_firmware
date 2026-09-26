// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_us_international.h"

#define MT_OSM_SHIFT LT(L_NUM, KC_0)
#define MT_R LT(L_SYM, KC_R)
#define MT_SPACE LSFT_T(KC_SPC)

enum layer_names {
    L_LATENIGHT,
    L_NAV,
    L_SYM,
    L_NUM,
    L_ACCENTS,
    L_DUP,
    L_WM_NAV,
};

#define LT_DBL LT(L_NAV, KC_NO)

enum custom_keycodes { // Make sure have the awesome keycode ready
    ALT_TAB = SAFE_RANGE,
    SHIFT_ALT_TAB,
    ACC_A_GRV,
    ACC_E_GRV,
    ACC_E_CIRC,
    ACC_E_UM,
    ACC_U_GRV,
    ACC_O_CIRC,
    ACC_O_UM,
    ACC_I_UM,
    PREV_TAB,
    NEXT_TAB,
    PASTE_HISTORY,

    SEND_DOTSLASH,
    SEND_DOTDOTSLASH,
    SEND_DOLLAR_CAPS_WORD,
    SEND_EQUALS_RABK,
    SEND_MINS_RABK,
    MG_UE,
    MG_GHT,
    DUP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_LATENIGHT] = LAYOUT(
        KC_PSCR            , LGUI(LALT(KC_1))   , LGUI(LALT(KC_2))   , LGUI(LALT(KC_3))   , KC_VOLD            , KC_VOLU            ,                      KC_MPLY            , KC_MRWD            , KC_MFFD            , KC_MPRV            , KC_MNXT            , KC_DEL             ,
        KC_TAB             , KC_B               , KC_F               , LT(L_WM_NAV, KC_L) , KC_D               , KC_J               ,                      KC_QUOT            , KC_P               , KC_O               , KC_U               , KC_COLN            , KC_BSPC            ,
        LSFT_T(KC_ESC)     , LSFT_T(KC_N)       , LALT_T(KC_S)       , LCTL_T(KC_H)       , LGUI_T(KC_T)       , KC_K               ,                      KC_Y               , LGUI_T(KC_C)       , LCTL_T(KC_A)       , LALT_T(KC_E)       , LSFT_T(KC_I)       , RSFT_T(KC_ENT)     ,
        KC_BSLS            , KC_X               , KC_V               , KC_M               , LT(L_ACCENTS, KC_G), KC_Q               ,                      KC_Z               , KC_W               , KC_DOT             , KC_MINS            , KC_COMM            , KC_SLSH            ,
                                                                                            MT_OSM_SHIFT       , MT_R               ,                      MT_SPACE           , LT_DBL
    ),

    [L_NAV] = LAYOUT(
        S(KC_PSCR)         , PDF(L_LATENIGHT)   , _______            , _______            , _______            , _______            ,                      _______            , _______            , _______            , _______            , _______            , _______            ,
        _______            , _______            , _______            , _______            , _______            , _______            ,                      KC_PGUP            , KC_HOME            , KC_UP              , KC_END             , _______            , _______            ,
        _______            , KC_LSFT            , KC_LALT            , KC_LCTL            , KC_LGUI            , _______            ,                      KC_PGDN            , KC_LEFT            , KC_DOWN            , KC_RGHT            , _______            , _______            ,
        _______            , _______            , _______            , _______            , _______            , _______            ,                      _______            , _______            , _______            , _______            , _______            , _______            ,
                                                                                            _______            , KC_SPC             ,                      _______            , _______
    ),

    [L_SYM] = LAYOUT(
        KC_F1              , KC_F2              , KC_F3              , KC_F4              , KC_F5              , KC_F6              ,                      KC_F7              , KC_F8              , KC_F9              , KC_F10             , KC_F11             , KC_F12             ,
        _______            , KC_PERC            , KC_DLR             , KC_LCBR            , KC_RCBR            , KC_TILD            ,                      KC_CIRC            , KC_LABK            , KC_RABK            , KC_MINS            , KC_AMPR            , _______            ,
        _______            , LSFT_T(KC_AT)      , LALT_T(KC_DQUO)    , LCTL_T(KC_LPRN)    , LGUI_T(KC_RPRN)    , KC_PLUS            ,                      KC_EXLM            , LGUI_T(KC_LBRC)    , LCTL_T(KC_RBRC)    , LALT_T(KC_EQL)     , KC_SCLN            , _______            ,
        _______            , KC_BSLS            , KC_SLSH            , KC_LBRC            , KC_HASH            , KC_HASH            ,                      KC_QUES            , KC_ASTR            , KC_PIPE            , KC_GRV             , KC_QUOT            , _______            ,
                                                                                            _______            , _______            ,                      _______            , _______
    ),

    [L_NUM] = LAYOUT(
        LALT(LCTL(KC_F1))  , LALT(LCTL(KC_F2))  , LALT(LCTL(KC_F3))  , LALT(LCTL(KC_F4))  , LALT(LCTL(KC_F5))  , LALT(LCTL(KC_F6))  ,                      LALT(LCTL(KC_F7))  , LALT(LCTL(KC_F8))  , LALT(LCTL(KC_F9))  , LALT(LCTL(KC_F10)) , LALT(LCTL(KC_F11)) , LALT(LCTL(KC_F12)) ,
        _______            , KC_GRV             , RCTL(KC_W)         , SHIFT_ALT_TAB      , ALT_TAB            , KC_UP              ,                      KC_ASTR            , KC_7               , KC_8               , KC_9               , KC_MINS            , _______            ,
        KC_ENT             , PASTE_HISTORY      , RCTL(S(KC_C))      , RCTL(KC_C)         , RCTL(KC_V)         , KC_DOWN            ,                      KC_PLUS            , LGUI_T(KC_1)       , LCTL_T(KC_2)       , LALT_T(KC_3)       , KC_DOT             , _______            ,
        _______            , KC_DQUO            , KC_QUOT            , PREV_TAB           , NEXT_TAB           , RCTL(S(KC_A))      ,                      KC_SLSH            , KC_4               , KC_5               , KC_6               , KC_COMM            , _______            ,
                                                                                            _______            , KC_ENT             ,                      _______            , KC_0
    ),

    [L_ACCENTS] = LAYOUT(
        _______            , _______            , _______            , _______            , _______            , _______            ,                      _______            , _______            , _______            , _______            , _______            , _______            ,
        _______            , _______            , _______            , _______            , _______            , _______            ,                      _______            , ACC_O_UM           , ACC_O_CIRC         , ACC_U_GRV          , RALT(KC_DQUO)      , _______            ,
        _______            , _______            , _______            , _______            , _______            , _______            ,                      _______            , US_CCED            , ACC_A_GRV          , US_EACU            , ACC_I_UM           , _______            ,
        _______            , _______            , _______            , _______            , _______            , _______            ,                      _______            , ACC_E_GRV          , ACC_E_CIRC         , ACC_E_UM           , _______            , _______            ,
                                                                                            _______            , _______            ,                      _______            , _______
    ),

    [L_DUP] = LAYOUT(
        _______            , _______            , _______            , _______            , _______            , _______            ,                      _______            , _______            , _______            , _______            , _______            , _______            ,
        _______            , DUP                , DUP                , DUP                , DUP                , DUP                ,                      DUP                , DUP                , DUP                , MG_UE              , DUP                , _______            ,
        _______            , DUP                , DUP                , MG_GHT             , DUP                , DUP                ,                      DUP                , DUP                , KC_PERC            , DUP                , DUP                , _______            ,
        _______            , DUP                , KC_UNDS            , DUP                , DUP                , DUP                ,                      DUP                , KC_TILD            , KC_GRV             , KC_HASH            , DUP                , _______            ,
                                                                                            _______            , DUP                ,                      _______            , DUP
    ),

    [L_WM_NAV] = LAYOUT(
        _______            , _______            , _______            , _______            , _______            , _______            ,                      _______            , _______            , _______            , _______            , _______            , _______            ,
        _______            , _______            , _______            , _______            , _______            , _______            ,                      _______            , LGUI(LALT(KC_7))   , LGUI(LALT(KC_8))   , LGUI(LALT(KC_9))   , _______            , _______            ,
        _______            , _______            , _______            , _______            , _______            , _______            ,                      _______            , LGUI(LALT(KC_1))   , LGUI(LALT(KC_2))   , LGUI(LALT(KC_3))   , _______            , _______            ,
        _______            , _______            , _______            , _______            , _______            , _______            ,                      _______            , LGUI(LALT(KC_4))   , LGUI(LALT(KC_5))   , LGUI(LALT(KC_6))   , _______            , _______            ,
                                                                                            _______            , _______            ,                      _______            , LGUI(LALT(KC_0))
    ),
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM dollar_caps_word_combo[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM slash_combo[] = {KC_P, LGUI_T(KC_C), COMBO_END};
const uint16_t PROGMEM back_slash_combo[] = {KC_O, LCTL_T(KC_A), COMBO_END};
const uint16_t PROGMEM w_dot_combo[] = {KC_W, KC_DOT, COMBO_END};
const uint16_t PROGMEM dot_mins_combo[] = {KC_DOT, KC_MINS, COMBO_END};
const uint16_t PROGMEM labk_rabk_combo[] = {KC_LABK, KC_RABK, COMBO_END};
const uint16_t PROGMEM rabk_mins_combo[] = {KC_RABK, KC_MINS, COMBO_END};
const uint16_t PROGMEM underscore_combo[] = {LALT_T(KC_S), KC_F, COMBO_END};
const uint16_t PROGMEM num_12_combo[] = {LGUI_T(KC_1), LCTL_T(KC_2), COMBO_END};
const uint16_t PROGMEM num_23_combo[] = {LCTL_T(KC_2), LALT_T(KC_3), COMBO_END};
const uint16_t PROGMEM num_78_combo[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM num_89_combo[] = {KC_8, KC_9, COMBO_END};

combo_t key_combos[]   = {
    COMBO(jk_combo, S(KC_V)),
    COMBO(dollar_caps_word_combo, SEND_DOLLAR_CAPS_WORD),
    COMBO(slash_combo, KC_SLSH),
    COMBO(back_slash_combo, KC_BSLS),
    COMBO(w_dot_combo, SEND_DOTDOTSLASH),
    COMBO(dot_mins_combo, SEND_DOTSLASH),
    COMBO(labk_rabk_combo, SEND_EQUALS_RABK),
    COMBO(rabk_mins_combo, SEND_MINS_RABK),
    COMBO(underscore_combo, KC_UNDS),
    COMBO(num_12_combo, KC_LBRC),
    COMBO(num_23_combo, KC_RBRC),
    COMBO(num_78_combo, KC_LPRN),
    COMBO(num_89_combo, KC_RPRN),
};

const key_override_t dot_exclaimation_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t comma_at_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_AT);
const key_override_t mins_question_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_QUES);
const key_override_t colon_slash_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);

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

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_NO:
        case DUP:
            return true;

        default:
            return false;
    }
}

static uint16_t double_tap_keycode(uint16_t keycode) {
    if (IS_QK_MOD_TAP(keycode)) {
        return QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    }
    if (IS_QK_LAYER_TAP(keycode)) {
        return QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    }
    return keycode;
}

static bool double_key_has_allowed_mods(uint16_t keycode) {
    uint8_t mods = get_mods() | get_oneshot_mods() | get_weak_mods();
    if (mods & ~MOD_MASK_SHIFT) {
        return false;
    }

    if (IS_QK_MODS(keycode)) {
        uint8_t keycode_mods = QK_MODS_GET_MODS(keycode) & 0x0F;
        return !(keycode_mods & ~MOD_LSFT);
    }

    return true;
}

static void tap_doubled_key(uint16_t keycode) {
    uint16_t tap_keycode = double_tap_keycode(keycode);
    uint16_t basic_keycode = IS_QK_MODS(tap_keycode) ? QK_MODS_GET_BASIC_KEYCODE(tap_keycode) : tap_keycode;

    if (is_caps_word_on() && KC_A <= basic_keycode && basic_keycode <= KC_Z && !IS_QK_MODS(tap_keycode)) {
        uint8_t weak_mods = get_weak_mods();
        add_weak_mods(MOD_BIT(KC_LSFT));
        send_keyboard_report();
        tap_code16(tap_keycode);
        set_weak_mods(weak_mods);
        send_keyboard_report();
        return;
    }

    tap_code16(tap_keycode);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DUP:
            if (record->event.pressed) {
                uint8_t  base_layer  = get_highest_layer(default_layer_state);
                uint16_t base_keycode = keymap_key_to_keycode(base_layer, record->event.key);

                tap_doubled_key(base_keycode);
                if (double_key_has_allowed_mods(base_keycode)) {
                    tap_doubled_key(base_keycode);
                }
            }
            return false;
        case LT_DBL:
            if (!record->event.pressed && record->tap.count) {
                set_oneshot_layer(L_DUP, ONESHOT_START);
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
            break;
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
        case PREV_TAB:
            if (record->event.pressed) {
                switch (detected_host_os()) {
                    case OS_MACOS:
                    case OS_IOS:
                        tap_code16(S(G(KC_LBRC)));
                        break;
                    default:
                        tap_code16(C(KC_PGUP));
                        break;
                }
            }
            return false;
        case NEXT_TAB:
            if (record->event.pressed) {
                switch (detected_host_os()) {
                    case OS_MACOS:
                    case OS_IOS:
                        tap_code16(S(G(KC_RBRC)));
                        break;
                    default:
                        tap_code16(C(KC_PGDN));
                        break;
                }
            }
            return false;
        case PASTE_HISTORY:
            if (record->event.pressed) {
                switch (detected_host_os()) {
                    case OS_MACOS:
                    case OS_IOS:
                        tap_code16(S(G(KC_V)));
                        break;
                    default:
                        tap_code16(G(A(KC_V)));
                        break;
                }
            }
            return false;
        case ACC_A_GRV:
            if (record->event.pressed) {
                if (is_caps_word_on()) {
                    SEND_STRING(SS_RALT("`") "A");
                } else {
                    SEND_STRING(SS_RALT("`") "a");
                }
            }
            return false;
        case ACC_E_GRV:
            if (record->event.pressed) {
                if (is_caps_word_on()) {
                    SEND_STRING(SS_RALT("`") "E");
                } else {
                    SEND_STRING(SS_RALT("`") "e");
                }
            }
            return false;
        case ACC_E_CIRC:
            if (record->event.pressed) {
                if (is_caps_word_on()) {
                    SEND_STRING(SS_RALT("6") "E");
                } else {
                    SEND_STRING(SS_RALT("6") "e");
                }
            }
            return false;
        case ACC_E_UM:
            if (record->event.pressed) {
                if (is_caps_word_on()) {
                    SEND_STRING(SS_RALT("\"") "E");
                } else {
                    SEND_STRING(SS_RALT("\"") "e");
                }
            }
            return false;
        case ACC_U_GRV:
            if (record->event.pressed) {
                if (is_caps_word_on()) {
                    SEND_STRING(SS_RALT("`") "U");
                } else {
                    SEND_STRING(SS_RALT("`") "u");
                }
            }
            return false;
        case ACC_O_CIRC:
            if (record->event.pressed) {
                if (is_caps_word_on()) {
                    SEND_STRING(SS_RALT("6") "O");
                } else {
                    SEND_STRING(SS_RALT("6") "o");
                }
            }
            return false;
        case ACC_O_UM:
            if (record->event.pressed) {
                if (is_caps_word_on()) {
                    SEND_STRING(SS_RALT("\"") "O");
                } else {
                    SEND_STRING(SS_RALT("\"") "o");
                }
            }
            return false;
        case ACC_I_UM:
            if (record->event.pressed) {
                if (is_caps_word_on()) {
                    SEND_STRING(SS_RALT("\"") "I");
                } else {
                    SEND_STRING(SS_RALT("\"") "i");
                }
            }
            return false;
        case LGUI_T(KC_AT):
            if (record->tap.count && record->event.pressed) {
                caps_word_off();
                tap_code16(KC_AT);
                return false;
            }
            break;
        case LCTL_T(KC_LPRN):
            if (record->tap.count && record->event.pressed) {
                caps_word_off();
                tap_code16(KC_LPRN);
                return false;
            }
            break;
        case LGUI_T(KC_RPRN):
            if (record->tap.count && record->event.pressed) {
                caps_word_off();
                tap_code16(KC_RPRN);
                return false;
            }
            break;
        case RCTL_T(KC_DQUO):
            if (record->tap.count && record->event.pressed) {
                caps_word_off();
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
        case SEND_DOLLAR_CAPS_WORD:
            if (record->event.pressed) {
                tap_code16(KC_DLR);
                caps_word_on();
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
        case MG_UE:
            if (record->event.pressed) {
                if (is_caps_word_on()) {
                    SEND_STRING("UE");
                } else {
                    SEND_STRING("ue");
                }
            }
            return false;
        case MG_GHT:
            if (record->event.pressed) {
                if (is_caps_word_on()) {
                    SEND_STRING("GHT");
                } else {
                    SEND_STRING("ght");
                }
            }
            return false;
    }
    return true;
}

bool is_macos;

bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_IOS:
        case OS_MACOS:
            keymap_config.swap_rctl_rgui = true;
            is_macos = true;
            break;
        default:
            is_macos = false;
            break;
    }

    return true;
}

bool rgb_matrix_indicators_user(void) {
    uint8_t highest_default_layer = get_highest_layer(default_layer_state);
    uint8_t red = 0, green = 0, blue = 0;

    if (is_macos) {
        red = 0;
        green = 0;
        blue = 255;
    } else {
        red = 0;
        green = 255;
        blue = 0;
    }

    switch (highest_default_layer) {
        case L_LATENIGHT:
            rgb_matrix_set_color(1, red, green, blue);
            break;
        default:
            break;
    }

    return false;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_OSM_SHIFT:
        case MT_R:
        case MT_SPACE:
        case LT_DBL:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // Do not select the hold action when another key is pressed.
    return false;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return keycode == LT_DBL;
}
