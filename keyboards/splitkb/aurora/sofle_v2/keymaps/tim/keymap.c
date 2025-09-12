#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

void keyboard_pre_init_user(void) {
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}

enum layer_names {
    L_QWERTY,  // qwerty
    L_GRAPHITE,  // graphite with simplified punctuation
    L_NAV,
    L_SYM,
    L_NUM,
    L_FNUM,
};

enum custom_keycodes { // Make sure have the awesome keycode ready
    ALT_TAB = SAFE_RANGE,
    SHIFT_ALT_TAB,
};

uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_QWERTY] = LAYOUT(
        KC_GRV         , KC_1           , KC_2           , KC_3           , KC_4           , KC_5           ,                                   KC_6           , KC_7           , KC_8           , KC_9           , KC_0           , KC_BSPC        ,
        KC_TAB         , KC_Q           , KC_W           , KC_E           , KC_R           , KC_T           ,                                   KC_Y           , KC_U           , KC_I           , KC_O           , KC_P           , KC_BSPC        ,
        KC_ESC         , KC_A           , LCTL_T(KC_S)   , LALT_T(KC_D)   , LGUI_T(KC_F)   , KC_G           ,                                   KC_H           , KC_J           , KC_K           , KC_L           , KC_SCLN        , KC_QUOT        ,
        KC_LSFT        , KC_Z           , KC_X           , KC_C           , KC_V           , KC_B           , KC_MUTE        , KC_MPLY        , KC_N           , KC_M           , KC_COMM        , KC_DOT         , KC_SLSH        , KC_MINS        ,
                                          KC_LGUI        , KC_LALT        , KC_LCTL        , TL_LOWR        , KC_SPC         , KC_LSFT        , TL_UPPR        , KC_RCTL        , KC_RALT        , KC_RGUI
    ),

    [L_GRAPHITE] = LAYOUT(
        CW_TOGG        , KC_0           , KC_1           , KC_2           , KC_4           , KC_5           ,                                   KC_6           , KC_7           , KC_8           , KC_LBRC        , KC_RBRC        , KC_BSPC        ,
        KC_TAB         , KC_B           , KC_L           , KC_D           , KC_W           , KC_Z           ,                                   KC_QUOT        , KC_F           , KC_O           , KC_U           , KC_J           , C(KC_S)        ,
        KC_ESC         , LGUI_T(KC_N)   , LCTL_T(KC_R)   , LALT_T(KC_T)   , LGUI_T(KC_S)   , KC_G           ,                                   KC_Y           , RGUI_T(KC_H)   , RALT_T(KC_A)   , RCTL_T(KC_E)   , RGUI_T(KC_I)   , KC_ENT         ,
        _______        , KC_Q           , KC_X           , KC_M           , KC_C           , KC_V           , _______        , _______        , KC_K           , KC_P           , KC_COMM        , KC_DOT         , KC_SLSH        , XXXXXXX        ,
                                          _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______
    ),

    [L_NAV] = LAYOUT(
        _______        , PDF(L_QWERTY)  , PDF(L_GRAPHITE), PDF(L_NAV)     , PDF(L_SYM)     , PDF(L_NUM)     ,                                   _______        , _______        , _______        , _______        , _______        , _______        ,
        _______        , _______        , KC_HOME        , KC_UP          , KC_END         , KC_PGUP        ,                                   _______        , KC_0           , KC_CIRC        , KC_DLR         , _______        , _______        ,
        KC_ENT         , _______        , KC_LEFT        , KC_DOWN        , KC_RGHT        , KC_PGDN        ,                                   _______        , RGUI_T(KC_B)   , RALT_T(KC_W)   , RCTL_T(KC_E)   , _______        , _______        ,
        _______        , _______        , _______        , SHIFT_ALT_TAB  , ALT_TAB        , _______        , _______        , _______        , _______        , KC_PSCR        , _______        , _______        , _______        , _______        ,
                                          _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______
    ),

    [L_SYM] = LAYOUT(
        _______        , KC_F1          , KC_F2          , KC_F3          , KC_F4          , KC_F5          ,                                   KC_F6          , KC_F7          , KC_F8          , KC_F9          , KC_F10         , _______        ,
        _______        , KC_PERC        , KC_DLR         , KC_LCBR        , KC_RCBR        , KC_TILD        ,                                   KC_CIRC        , KC_LABK        , KC_RABK        , KC_EQL         , KC_AMPR        , KC_DEL         ,
        _______        , LGUI_T(KC_AT)  , LCTL_T(KC_MINS), LALT_T(KC_LPRN), LGUI_T(KC_RPRN), KC_PLUS        ,                                   KC_EXLM        , RGUI_T(KC_COLN), RALT_T(KC_UNDS), RCTL_T(KC_DQUO), RGUI_T(KC_SCLN), _______        ,
        _______        , KC_BSLS        , KC_SLSH        , KC_LBRC        , KC_RBRC        , KC_HASH        , _______        , _______        , KC_QUES        , KC_ASTR        , KC_PIPE        , KC_GRV         , KC_QUOT        , _______        ,
                                          _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______
    ),

    [L_NUM] = LAYOUT(
        _______        , _______        , _______        , _______        , _______        , _______        ,                                   _______        , _______        , _______        , _______        , _______        , _______        ,
        _______        , _______        , KC_LPRN        , KC_LBRC        , KC_LCBR        , _______        ,                                   _______        , KC_RCBR        , KC_RBRC        , KC_RPRN        , _______        , _______        ,
        _______        , KC_8           , LCTL_T(KC_7)   , LALT_T(KC_6)   , LGUI_T(KC_5)   , _______        ,                                   _______        , RGUI_T(KC_0)   , RALT_T(KC_1)   , RCTL_T(KC_2)   , KC_3           , _______        ,
        _______        , KC_ASTR        , KC_MINS        , KC_PLUS        , KC_9           , _______        , _______        , _______        , _______        , KC_4           , KC_COMM        , KC_DOT         , KC_SLSH        , _______        ,
                                          _______        , _______        , _______        , _______        , _______        , MO(L_FNUM)     , _______        , _______        , _______        , _______
    ),

    [L_FNUM] = LAYOUT(
        _______        , _______        , _______        , _______        , _______        , _______        ,                                   _______        , _______        , _______        , _______        , _______        , _______        ,
        _______        , _______        , _______        , _______        , _______        , _______        ,                                   _______        , _______        , _______        , _______        , _______        , _______        ,
        _______        , KC_F8          , LCTL_T(KC_F7)  , LALT_T(KC_F6)  , LGUI_T(KC_F5)  , _______        ,                                   _______        , RGUI_T(KC_0)   , RALT_T(KC_F1)  , RCTL_T(KC_F2)  , KC_F3          , _______        ,
        _______        , KC_F12         , KC_F11         , KC_F10         , KC_F9          , _______        , _______        , _______        , _______        , KC_F4          , _______        , _______        , _______        , _______        ,
                                          _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [L_QWERTY] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK)},
    [L_GRAPHITE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MRWD, KC_MFFD)},
    [L_NAV] = {ENCODER_CCW_CW(UG_HUED, UG_HUEU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [L_SYM] = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(UG_SATD, UG_SATU)},
    [L_NUM] = {ENCODER_CCW_CW(UG_VALD, UG_VALU), ENCODER_CCW_CW(UG_SPDD, UG_SPDU)},
    [L_FNUM] = {ENCODER_CCW_CW(UG_VALD, UG_VALU), ENCODER_CCW_CW(UG_SPDD, UG_SPDU)},
};
#endif

const uint16_t PROGMEM left_brace_combo[] = {KC_F, KC_O, COMBO_END};
const uint16_t PROGMEM right_brace_combo[] = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM left_paren_combo[] = {KC_H, KC_A, COMBO_END};
const uint16_t PROGMEM right_paren_combo[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM left_bracket_combo[] = {KC_F, KC_H, COMBO_END};
const uint16_t PROGMEM right_bracket_combo[] = {KC_O, KC_A, COMBO_END};
const uint16_t PROGMEM left_angle_bracket_combo[] = {KC_F, KC_H, COMBO_END};
const uint16_t PROGMEM equals_combo[] = {KC_O, KC_A, COMBO_END};
const uint16_t PROGMEM right_angle_bracket_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM browser_forward_combo[] = {KC_DOWN, KC_RGHT, COMBO_END};
const uint16_t PROGMEM browser_back_combo[] = {KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM browser_refresh_combo[] = {KC_LEFT, KC_RGHT, COMBO_END};

combo_t key_combos[]   = {
    COMBO(browser_forward_combo, KC_WFWD),
    COMBO(browser_back_combo, KC_WBAK),
    COMBO(browser_refresh_combo, KC_WREF),
};

bool rgb_matrix_indicators_user(void) {
    uint8_t  highest_layer = get_highest_layer(layer_state | default_layer_state);

    switch (highest_layer) {
        case L_QWERTY:
            rgb_matrix_set_color(4, 0, 0, 255);
            break;
        case L_GRAPHITE:
            rgb_matrix_set_color(3, 0, 0, 255);
            break;
        case L_NAV:
            rgb_matrix_set_color(2, 0, 0, 255);
            break;
        case L_SYM:
            rgb_matrix_set_color(1, 0, 0, 255);
            break;
        case L_NUM:
            rgb_matrix_set_color(0, 0, 0, 255);
            break;
        default:
            break;
    }

    return false;
}

bool is_alt_tab_active = false;
uint8_t alt_tab_key = KC_LALT;

// from https://www.reddit.com/r/MechanicalKeyboards/comments/mrnxrj/better_super_alttab/
layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_alt_tab_active) {
        unregister_code(alt_tab_key);
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
