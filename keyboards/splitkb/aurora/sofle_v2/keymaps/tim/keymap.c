#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

void keyboard_pre_init_user(void) {
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}

enum layer_names {
    L_QWER,  // qwerty
    L_GRAP,  // graphite
    L_GRAP_SIMPLE,  // graphite with simplified punctuation
    L_SYM,
    L_BRC,
    L_NUM,
    L_NAV,
    L_UTIL,
};

#define LTSYM(k) LT(L_SYM, k)
#define LTBRC(k) LT(L_BRC, k)
#define LTNUM(k) LT(L_NUM, k)
#define LTNAV(k) LT(L_NAV, k)

enum custom_keycodes { // Make sure have the awesome keycode ready
    ALT_TAB = SAFE_RANGE,
    SHIFT_ALT_TAB,
};

enum tap_dance_keycodes {
    TD_SHIFT_LAYER,
};

uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_QWER] = LAYOUT(
        KC_GRV            , KC_1              , KC_2              , KC_3              , KC_4              , KC_5              ,                                         KC_6              , KC_7              , KC_8              , KC_9              , KC_0              , KC_BSPC           ,
        KC_TAB            , KC_Q              , KC_W              , KC_E              , KC_R              , KC_T              ,                                         KC_Y              , KC_U              , KC_I              , KC_O              , KC_P              , KC_BSPC           ,
        KC_ESC            , KC_A              , LTNUM(KC_S)       , LTSYM(KC_D)       , LTBRC(KC_F)       , KC_G              ,                                         KC_H              , KC_J              , KC_K              , KC_L              , KC_SCLN           , KC_QUOT           ,
        KC_LSFT           , KC_Z              , KC_X              , KC_C              , KC_V              , KC_B              , KC_MUTE           , KC_MPLY           , KC_N              , KC_M              , KC_COMM           , KC_DOT            , KC_SLSH           , KC_MINS           ,
                                                KC_LGUI           , KC_LCTL           , KC_LALT           , MO(L_NAV)         , LT(L_SYM, KC_ENT) , LT(L_BRC, KC_SPC) , KC_RSFT           , KC_RALT           , KC_RCTL           , KC_RGUI
    ),

    [L_GRAP] = LAYOUT(
        KC_GRV            , KC_0              , KC_1              , KC_2              , KC_4              , KC_5              ,                                         KC_6              , KC_7              , KC_8              , KC_LABK           , KC_RABK           , KC_BSPC           ,
        KC_TAB            , KC_B              , KC_L              , KC_D              , KC_W              , KC_Z              ,                                         KC_QUOT           , KC_F              , KC_O              , KC_U              , KC_J              , KC_COMM           ,
        KC_ESC            , KC_N              , LTNUM(KC_R)       , LTSYM(KC_T)       , LTBRC(KC_S)       , KC_G              ,                                         KC_Y              , KC_H              , KC_A              , KC_E              , KC_I              , KC_SCLN           ,
        _______           , KC_Q              , KC_X              , KC_M              , KC_C              , KC_V              , _______           , _______           , KC_K              , KC_P              , KC_DOT            , KC_MINS           , KC_SLSH           , KC_COMM           ,
                                                _______           , _______           , _______           , _______           , _______           , _______           , _______           , _______           , _______           , _______
    ),

    [L_GRAP_SIMPLE] = LAYOUT(
        KC_GRV            , KC_0              , KC_1              , KC_2              , KC_4              , KC_5              ,                                         KC_6              , KC_7              , KC_8              , KC_LBRC           , KC_RBRC           , KC_BSPC           ,
        KC_TAB            , KC_B              , KC_L              , KC_D              , KC_W              , KC_Z              ,                                         KC_QUOT           , KC_F              , KC_O              , KC_U              , KC_J              , KC_BSLS           ,
        KC_ESC            , MT(MOD_LGUI, KC_N), MT(MOD_LCTL, KC_R), MT(MOD_LALT, KC_T), LT(L_BRC, KC_S)   , KC_G              ,                                         KC_Y              , LT(L_SYM, KC_H)   , MT(MOD_RALT, KC_A), MT(MOD_RCTL, KC_E), MT(MOD_RGUI, KC_I), KC_SCLN           ,
        _______           , KC_Q              , KC_X              , KC_M              , LT(L_NUM, KC_C)   , KC_V              , _______           , _______           , KC_K              , LT(L_UTIL, KC_P)  , KC_COMM           , KC_DOT            , KC_SLSH           , KC_MINS           ,
                                                _______           , _______           , KC_COLN           , _______           , _______           , _______           , _______           , KC_UNDS           , _______           , _______
    ),

    [L_SYM] = LAYOUT(
        _______           , _______           , _______           , _______           , _______           , _______           ,                                         _______           , _______           , _______           , _______           , _______           , _______           ,
        _______           , KC_BSLS           , KC_PIPE           , KC_DLR            , KC_AMPR           , KC_CIRC           ,                                         _______           , KC_LCBR           , KC_RCBR           , _______           , _______           , _______           ,
        _______           , KC_LABK           , KC_EXLM           , KC_EQL            , KC_RABK           , KC_PERC           ,                                         _______           , KC_LPRN           , KC_RPRN           , KC_SCLN           , KC_COLN           , _______           ,
        _______           , _______           , KC_AT             , KC_PLUS           , KC_ASTR           , KC_HASH           , _______           , _______           , _______           , KC_LBRC           , KC_RBRC           , _______           , _______           , _______           ,
                                                _______           , _______           , _______           , _______           , _______           , _______           , _______           , _______           , _______           , _______
    ),

    [L_BRC] = LAYOUT(
        _______           , _______           , _______           , _______           , _______           , _______           ,                                         _______           , _______           , _______           , _______           , _______           , _______           ,
        _______           , _______           , KC_7              , KC_8              , KC_9              , _______           ,                                         _______           , KC_LCBR           , KC_RCBR           , _______           , _______           , _______           ,
        _______           , KC_ASTR           , KC_4              , KC_5              , KC_6              , KC_PLUS           ,                                         _______           , KC_LPRN           , KC_RPRN           , KC_SCLN           , KC_COLN           , _______           ,
        _______           , KC_SLSH           , KC_1              , KC_2              , KC_3              , KC_MINS           , _______           , _______           , _______           , KC_LBRC           , KC_RBRC           , _______           , _______           , _______           ,
                                                _______           , _______           , _______           , KC_0              , _______           , _______           , _______           , _______           , _______           , _______
    ),

    [L_NUM] = LAYOUT(
        _______           , _______           , _______           , _______           , _______           , _______           ,                                         _______           , _______           , _______           , _______           , _______           , _______           ,
        _______           , _______           , _______           , _______           , _______           , _______           ,                                         _______           , KC_7              , KC_8              , KC_9              , _______           , _______           ,
        _______           , _______           , _______           , _______           , _______           , _______           ,                                         KC_PLUS           , KC_4              , KC_5              , KC_6              , KC_ASTR           , _______           ,
        _______           , _______           , _______           , _______           , _______           , _______           , _______           , _______           , KC_MINS           , KC_1              , KC_2              , KC_3              , KC_SLSH           , _______           ,
                                                _______           , _______           , _______           , _______           , QK_LLCK           , _______           , KC_0              , _______           , _______           , _______
    ),

    [L_NAV] = LAYOUT(
        _______           , PDF(L_QWER)       , PDF(L_GRAP)       , PDF(L_GRAP_SIMPLE), _______           , _______           ,                                         _______           , _______           , _______           , _______           , _______           , KC_DEL            ,
        _______           , _______           , KC_HOME           , KC_UP             , KC_END            , KC_PGUP           ,                                         KC_PGUP           , KC_0              , KC_CIRC           , KC_DLR            , _______           , _______           ,
        QK_LLCK           , _______           , KC_LEFT           , KC_DOWN           , KC_RGHT           , KC_PGDN           ,                                         KC_PGDN           , KC_B              , MT(MOD_LALT, KC_W), MT(MOD_LCTL, KC_E), KC_RGUI           , _______           ,
        _______           , _______           , SHIFT_ALT_TAB     , ALT_TAB           , S(KC_INS)         , C(KC_INS)         , _______           , _______           , _______           , _______           , S(KC_N)           , KC_N              , _______           , _______           ,
                                                _______           , _______           , _______           , _______           , _______           , QK_LLCK           , _______           , _______           , _______           , _______
    ),

    [L_UTIL] = LAYOUT(
        XXXXXXX           , _______           , _______           , _______           , _______           , XXXXXXX           ,                                         XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
        XXXXXXX           , KC_INS            , _______           , _______           , _______           , XXXXXXX           ,                                         XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
        XXXXXXX           , _______           , _______           , KC_PSCR           , S(C(KC_V))        , XXXXXXX           ,                                         XXXXXXX           , KC_VOLD           , KC_MUTE           , KC_VOLU           , XXXXXXX           , XXXXXXX           ,
        XXXXXXX           , C(KC_Z)           , C(KC_X)           , C(KC_C)           , C(KC_V)           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , KC_MPRV           , KC_MPLY           , KC_MNXT           , XXXXXXX           , XXXXXXX           ,
                                                _______           , _______           , _______           , _______           , _______           , _______           , _______           , _______           , _______           , _______
    )
};

const key_override_t dot_gt_override           = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_GT, L_GRAP);
const key_override_t dash_quote_override       = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, KC_DQT, L_GRAP);
const key_override_t slash_lt_override         = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, KC_LT, L_GRAP);
const key_override_t comma_question_override   = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_QUES, L_GRAP);
const key_override_t qoute_underscore_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOT, KC_UNDS, L_GRAP);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &dot_gt_override, &dash_quote_override, &slash_lt_override, &comma_question_override, &qoute_underscore_override,
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [L_QWER] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK)},
    [L_GRAP] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK)},
    [L_GRAP_SIMPLE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MRWD, KC_MFFD)},
    [L_SYM] = {ENCODER_CCW_CW(UG_HUED, UG_HUEU), ENCODER_CCW_CW(UG_SATD, UG_SATU)},
    [L_BRC] = {ENCODER_CCW_CW(UG_HUED, UG_HUEU), ENCODER_CCW_CW(UG_SATD, UG_SATU)},
    [L_NUM] = {ENCODER_CCW_CW(UG_VALD, UG_VALU), ENCODER_CCW_CW(UG_SPDD, UG_SPDU)},
    [L_NAV] = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [L_UTIL] = {ENCODER_CCW_CW(RM_SPDU, RM_SPDD), ENCODER_CCW_CW(RM_PREV, RM_NEXT)}
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
        case L_QWER:
            rgb_matrix_set_color(4, 0, 0, 255);
            break;
        case L_GRAP:
            rgb_matrix_set_color(3, 0, 0, 255);
            break;
        case L_GRAP_SIMPLE:
            rgb_matrix_set_color(2, 0, 0, 255);
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

// from https://www.reddit.com/r/MechanicalKeyboards/comments/mrnxrj/better_super_alttab/
layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_alt_tab_active) {
        unregister_code(KC_LALT);
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
                    register_code(KC_LALT);
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
                    register_code(KC_LALT);
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

// Tap dance action
void td_shift_layer_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        clear_oneshot_mods();
        layer_on(L_NAV); // Activate layer when held
    } else if (state->count == 1) {
        set_oneshot_mods(MOD_LSFT); // One-shot shift when tapped
    }
}

void td_shift_layer_reset(tap_dance_state_t *state, void *user_data) {
    layer_off(L_NAV); // Deactivate layer when key is released
}

// Tap dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_SHIFT_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_shift_layer_finished, td_shift_layer_reset)
};
