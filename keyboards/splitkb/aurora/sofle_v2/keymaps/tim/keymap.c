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
    L_SYM,
    L_NAV,
    L_NUM,
    L_FNUM,
};

enum custom_keycodes { // Make sure have the awesome keycode ready
    ALT_TAB = SAFE_RANGE,
    SHIFT_ALT_TAB,
    NAV_KEY,
    SYM_KEY,
};

enum tap_dance_keycodes {
    TD_SHIFT_LAYER,
};

uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_QWERTY] = LAYOUT(
        KC_GRV             , KC_1               , KC_2               , KC_3               , KC_4               , KC_5               ,                                           KC_6               , KC_7               , KC_8               , KC_9               , KC_0               , KC_BSPC            ,
        KC_TAB             , KC_Q               , KC_W               , KC_E               , KC_R               , KC_T               ,                                           KC_Y               , KC_U               , KC_I               , KC_O               , KC_P               , KC_BSPC            ,
        KC_ESC             , KC_A               , MT(MOD_LCTL, KC_S) , MT(MOD_LALT, KC_D) , MT(MOD_LGUI, KC_F) , KC_G               ,                                           KC_H               , KC_J               , KC_K               , KC_L               , KC_SCLN            , KC_QUOT            ,
        KC_LSFT            , KC_Z               , KC_X               , KC_C               , KC_V               , KC_B               , KC_MUTE            , KC_MPLY            , KC_N               , KC_M               , KC_COMM            , KC_DOT             , KC_SLSH            , KC_MINS            ,
                                                  KC_LGUI            , KC_LALT            , KC_LCTL            , TL_UPPR            , KC_SPC             , KC_LSFT            , TL_LOWR            , KC_RCTL            , KC_RALT            , KC_RGUI
    ),

    [L_GRAPHITE] = LAYOUT(
        CW_TOGG            , KC_0               , KC_1               , KC_2               , KC_4               , KC_5               ,                                           KC_6               , KC_7               , KC_8               , KC_LBRC            , KC_RBRC            , KC_BSPC            ,
        KC_TAB             , KC_B               , KC_L               , KC_D               , KC_W               , KC_Z               ,                                           KC_QUOT            , KC_F               , KC_O               , KC_U               , KC_J               , C(KC_S)            ,
        KC_ESC             , MT(MOD_LGUI, KC_N) , MT(MOD_LCTL, KC_R) , MT(MOD_LALT, KC_T) , MT(MOD_LGUI, KC_S) , KC_G               ,                                           KC_Y               , MT(MOD_RGUI, KC_H) , MT(MOD_RALT, KC_A) , MT(MOD_RCTL, KC_E) , MT(MOD_RGUI, KC_I) , KC_ENT             ,
        _______            , KC_Q               , KC_X               , KC_M               , KC_C               , KC_V               , _______            , _______            , KC_K               , KC_P               , KC_COMM            , KC_DOT             , KC_SLSH            , XXXXXXX            ,
                                                  _______            , _______            , _______            , _______            , _______            , _______            , _______            , _______            , _______            , _______
    ),

    [L_SYM] = LAYOUT(
        _______            , _______            , _______            , _______            , _______            , _______            ,                                           _______            , _______            , _______            , _______            , _______            , _______            ,
        _______            , KC_PERC            , KC_DLR             , KC_LCBR            , KC_RCBR            , KC_TILD            ,                                           KC_CIRC            , KC_LABK            , KC_RABK            , KC_EQL             , KC_AMPR            , KC_DEL             ,
        _______            , KC_AT              , KC_MINS            , KC_LPRN            , KC_RPRN            , KC_PLUS            ,                                           KC_EXLM            , KC_COLN            , KC_UNDS            , KC_DQUO            , KC_SCLN            , _______            ,
        _______            , KC_BSLS            , KC_SLSH            , KC_LBRC            , KC_RBRC            , KC_HASH            , _______            , _______            , KC_QUES            , KC_ASTR            , KC_PIPE            , KC_GRV             , KC_QUOT            , _______            ,
                                                  _______            , _______            , _______            , _______            , MT(L_FNUM, KC_SPC) , _______            , _______            , _______            , _______            , _______
    ),

    [L_NAV] = LAYOUT(
        _______            , PDF(L_QWERTY)      , PDF(L_GRAPHITE)    , PDF(L_NUM)         , _______            , _______            ,                                           _______            , _______            , _______            , _______            , _______            , _______            ,
        _______            , _______            , KC_HOME            , KC_UP              , KC_END             , KC_PGUP            ,                                           _______            , KC_0               , KC_CIRC            , KC_DLR             , _______            , _______            ,
        KC_ENT             , _______            , KC_LEFT            , KC_DOWN            , KC_RGHT            , KC_PGDN            ,                                           _______            , MT(MOD_LGUI, KC_B) , MT(MOD_LALT, KC_W) , MT(MOD_LCTL, KC_E) , _______            , _______            ,
        _______            , _______            , _______            , SHIFT_ALT_TAB      , ALT_TAB            , _______            , _______            , _______            , _______            , KC_PSCR            , _______            , _______            , _______            , _______            ,
                                                  _______            , _______            , _______            , _______            , _______            , _______            , _______            , _______            , _______            , _______
    ),

    [L_NUM] = LAYOUT(
        _______            , _______            , _______            , _______            , _______            , _______            ,                                           _______            , _______            , _______            , _______            , _______            , _______            ,
        _______            , _______            , KC_LPRN            , KC_LBRC            , KC_LCBR            , _______            ,                                           _______            , KC_RCBR            , KC_RBRC            , KC_RPRN            , _______            , _______            ,
        _______            , KC_8               , MT(MOD_LCTL, KC_7) , MT(MOD_LALT, KC_6) , MT(MOD_LGUI, KC_5) , _______            ,                                           _______            , MT(MOD_RGUI, KC_0) , MT(MOD_RALT, KC_1) , MT(MOD_RCTL, KC_2) , KC_3               , _______            ,
        _______            , KC_ASTR            , KC_MINS            , KC_PLUS            , KC_9               , _______            , _______            , _______            , _______            , KC_4               , KC_COMM            , KC_DOT             , KC_SLSH            , _______            ,
                                                  _______            , _______            , _______            , _______            , _______            , _______            , _______            , _______            , _______            , _______
    ),

    [L_FNUM] = LAYOUT(
        _______            , _______            , _______            , _______            , _______            , _______            ,                                           _______            , _______            , _______            , _______            , _______            , _______            ,
        _______            , _______            , _______            , _______            , _______            , _______            ,                                           _______            , _______            , _______            , _______            , _______            , _______            ,
        _______            , KC_F8              , MT(MOD_LCTL, KC_F7), MT(MOD_LALT, KC_F6), MT(MOD_LGUI, KC_F5), _______            ,                                           _______            , MT(MOD_RGUI, KC_0) , MT(MOD_RALT, KC_F1), MT(MOD_RCTL, KC_F2), KC_F3              , _______            ,
        _______            , KC_F12             , KC_F11             , KC_F10             , KC_F9              , _______            , _______            , _______            , _______            , KC_F4              , _______            , _______            , _______            , _______            ,
                                                  _______            , _______            , _______            , _______            , _______            , _______            , _______            , _______            , _______            , _______
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [L_QWERTY] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK)},
    [L_GRAPHITE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MRWD, KC_MFFD)},
    [L_SYM] = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(UG_SATD, UG_SATU)},
    [L_NAV] = {ENCODER_CCW_CW(UG_HUED, UG_HUEU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
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
    switch (get_highest_layer(default_layer_state)) {
        case L_QWERTY:
            rgb_matrix_set_color(4, 0, 0, 255);
            break;
        case L_GRAPHITE:
            rgb_matrix_set_color(3, 0, 0, 255);
            break;
        default:
            break;
    }

    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_GREEN);
                }
            }
        }
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
