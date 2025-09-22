// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    L_GRAPHITE,  // graphite with simplified punctuation
    L_NAV,
    L_SYM,
    L_NUM,
    L_WNAV,
    L_FNUM,
};

enum custom_keycodes { // Make sure have the awesome keycode ready
    ALT_TAB = SAFE_RANGE,
    SHIFT_ALT_TAB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_GRAPHITE] = LAYOUT(
        CW_TOGG           , KC_BRID           , KC_BRIU           , KC_MUTE           , KC_VOLD           , KC_VOLU           ,                                         KC_MPRV           , KC_MRWD           , KC_MPLY           , KC_MFFD           , KC_MNXT           , KC_PSCR           ,
        KC_TAB            , KC_B              , KC_L              , KC_D              , KC_W              , KC_Z              ,                                         KC_QUOT           , KC_F              , KC_O              , KC_U              , KC_J              , KC_BSPC           ,
        LSFT_T(KC_ESC)    , LGUI_T(KC_N)      , LCTL_T(KC_R)      , LALT_T(KC_T)      , LGUI_T(KC_S)      , KC_G              ,                                         KC_Y              , RGUI_T(KC_H)      , RALT_T(KC_A)      , RCTL_T(KC_E)      , RGUI_T(KC_I)      , RSFT_T(KC_ENT)    ,
        _______           , KC_Q              , KC_X              , KC_M              , KC_C              , KC_V              ,                                         KC_K              , KC_P              , KC_COMM           , KC_DOT            , KC_SLSH           , _______           ,
                                                                                        LT(L_NAV, KC_COLN), LT(L_WNAV, KC_SPC),                                         LSFT_T(KC_MINS)   , MO(L_SYM)
    ),

    [L_NAV] = LAYOUT(
        _______           , PDF(L_GRAPHITE)   , PDF(L_NUM)        , _______           , RM_PREV           , RM_NEXT           ,                                         _______           , _______           , _______           , _______           , _______           , _______           ,
        _______           , _______           , KC_HOME           , KC_UP             , KC_END            , KC_PGUP           ,                                         _______           , KC_0              , KC_CIRC           , KC_DLR            , _______           , _______           ,
        KC_ENT            , _______           , KC_LEFT           , KC_DOWN           , KC_RGHT           , KC_PGDN           ,                                         _______           , RGUI_T(KC_B)      , RALT_T(KC_W)      , RCTL_T(KC_E)      , _______           , _______           ,
        _______           , _______           , _______           , SHIFT_ALT_TAB     , ALT_TAB           , _______           ,                                         _______           , KC_ASTR           , S(KC_N)           , KC_N              , _______           , _______           ,
                                                                                        _______           , _______           ,                                         _______           , _______
    ),

    [L_SYM] = LAYOUT(
        KC_F1             , KC_F2             , KC_F3             , KC_F4             , KC_F5             , KC_F6             ,                                         KC_F7             , KC_F8             , KC_F9             , KC_F10            , KC_F11            , KC_F12            ,
        _______           , KC_PERC           , KC_DLR            , KC_LCBR           , KC_RCBR           , KC_TILD           ,                                         KC_CIRC           , KC_LABK           , KC_RABK           , KC_EQL            , KC_AMPR           , _______           ,
        _______           , LGUI_T(KC_AT)     , LCTL_T(KC_MINS)   , LALT_T(KC_LPRN)   , LGUI_T(KC_RPRN)   , KC_PLUS           ,                                         KC_EXLM           , RGUI_T(KC_COLN)   , RALT_T(KC_UNDS)   , RCTL_T(KC_DQUO)   , KC_SCLN           , _______           ,
        _______           , KC_BSLS           , KC_SLSH           , KC_LBRC           , KC_RBRC           , KC_HASH           ,                                         KC_QUES           , KC_ASTR           , KC_PIPE           , KC_GRV            , KC_QUOT           , _______           ,
                                                                                        _______           , _______           ,                                         _______           , _______
    ),

    [L_NUM] = LAYOUT(
        _______           , _______           , _______           , _______           , _______           , _______           ,                                         _______           , _______           , _______           , _______           , _______           , _______           ,
        _______           , _______           , KC_LPRN           , KC_LBRC           , KC_LCBR           , _______           ,                                         _______           , KC_RCBR           , KC_RBRC           , KC_RPRN           , _______           , _______           ,
        _______           , KC_8              , LCTL_T(KC_7)      , LALT_T(KC_6)      , LGUI_T(KC_5)      , _______           ,                                         _______           , RGUI_T(KC_0)      , RALT_T(KC_1)      , RCTL_T(KC_2)      , KC_3              , _______           ,
        _______           , KC_ASTR           , KC_MINS           , KC_PLUS           , KC_9              , _______           ,                                         _______           , KC_4              , KC_COMM           , KC_DOT            , KC_SLSH           , _______           ,
                                                                                        _______           , _______           ,                                         _______           , _______
    ),

    [L_WNAV] = LAYOUT(
        _______           , _______           , _______           , _______           , _______           , _______           ,                                         _______           , _______           , _______           , _______           , _______           , _______           ,
        _______           , _______           , LGUI(KC_HOME)     , LGUI(KC_UP)       , LGUI(KC_END)      , LGUI(KC_PGUP)     ,                                         _______           , _______           , _______           , _______           , _______           , _______           ,
        _______           , _______           , LGUI(KC_LEFT)     , LGUI(KC_DOWN)     , LGUI(KC_RGHT)     , LGUI(KC_PGDN)     ,                                         _______           , _______           , KC_RALT           , KC_RCTL           , _______           , _______           ,
        _______           , _______           , _______           , SHIFT_ALT_TAB     , ALT_TAB           , _______           ,                                         _______           , _______           , _______           , _______           , _______           , _______           ,
                                                                                        _______           , _______           ,                                         _______           , _______
    ),

    [L_FNUM] = LAYOUT(
        _______           , _______           , _______           , _______           , _______           , _______           ,                                         _______           , _______           , _______           , _______           , _______           , _______           ,
        _______           , _______           , _______           , _______           , _______           , _______           ,                                         _______           , _______           , _______           , _______           , _______           , _______           ,
        _______           , KC_F8             , LCTL_T(KC_F7)     , LALT_T(KC_F6)     , LGUI_T(KC_F5)     , _______           ,                                         _______           , RGUI_T(KC_0)      , RALT_T(KC_F1)     , RCTL_T(KC_F2)     , KC_F3             , _______           ,
        _______           , KC_F12            , KC_F11            , KC_F10            , KC_F9             , _______           ,                                         _______           , KC_F4             , _______           , _______           , _______           , _______           ,
                                                                                        _______           , _______           ,                                         _______           , _______
    ),
};

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SLSH:
            return true;
    }
    return false;
}

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

bool is_alt_tab_active = false;
uint8_t alt_tab_key = KC_LALT;

layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_alt_tab_active) {
        unregister_code(alt_tab_key);
        is_alt_tab_active = false;
    }
    return update_tri_layer_state(state, L_NAV, L_SYM, L_NUM);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_TAB: // super alt tab macro
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(alt_tab_key);
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
                    register_code(alt_tab_key);
                }
                register_code16(S(KC_TAB));
            } else {
                unregister_code16(S(KC_TAB));
            }
            break;
            return false;
        case LT(L_NAV, KC_COLN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_COLN);
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
        case RGUI_T(KC_COLN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_COLN);
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

bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_WINDOWS:
            // Do something when Windows is detected
            break;
        case OS_MACOS:
            alt_tab_key = KC_LGUI;
            return false;
        case OS_LINUX:
            // Do something when Linux is detected
            break;
        default:
            // Handle unknown OS or do nothing
            break;
    }
    return true;
}

bool rgb_matrix_indicators_user(void) {
    uint8_t highest_layer = get_highest_layer(default_layer_state);

    switch (highest_layer) {
        case L_GRAPHITE:
            rgb_matrix_set_color(1, 0, 0, 0);
            break;
        case L_NUM:
            rgb_matrix_set_color(2, 0, 0, 0);
            break;
        default:
            break;
    }

    if (is_caps_word_on()) {
        rgb_matrix_set_color(0, 255, 255, 255);
    }

    return false;
}
