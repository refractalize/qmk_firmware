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
    L_GRAP2, // graphite with BLD / QXM swap
    L_GALL,  // gallium with left hand inverted
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
    SHIFT_ALT_TAB
};

uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_QWER] = LAYOUT(
        KC_GRV       , KC_1         , KC_2         , KC_3         , KC_4         , KC_5         ,                               KC_6         , KC_7         , KC_8         , KC_9         , KC_0         , KC_BSPC      ,
        KC_TAB       , KC_Q         , KC_W         , KC_E         , KC_R         , KC_T         ,                               KC_Y         , KC_U         , KC_I         , KC_O         , KC_P         , KC_BSPC      ,
        KC_ESC       , KC_A         , LTNUM(KC_S)  , LTSYM(KC_D)  , LTBRC(KC_F)  , KC_G         ,                               KC_H         , KC_J         , KC_K         , KC_L         , KC_SCLN      , KC_QUOT      ,
        XXXXXXX      , KC_Z         , KC_X         , KC_C         , KC_V         , KC_B         , KC_MUTE      , KC_MPLY      , KC_N         , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH      , KC_MINS      ,
                                      KC_LGUI      , KC_LCTL      , KC_LALT      , OSM(MOD_LSFT), KC_ENT       , KC_SPC       , MO(L_NAV)    , KC_RALT      , KC_RCTL      , KC_RGUI
    ),

    [L_GRAP] = LAYOUT(
        KC_GRV       , KC_1         , KC_2         , KC_3         , KC_4         , KC_5         ,                               KC_6         , KC_7         , KC_8         , KC_9         , KC_0         , KC_BSPC      ,
        KC_TAB       , KC_B         , KC_L         , KC_D         , KC_W         , KC_Z         ,                               KC_QUOT      , KC_F         , KC_O         , KC_U         , KC_J         , KC_COMM      ,
        KC_ESC       , KC_N         , LTNUM(KC_R)  , LTSYM(KC_T)  , LTBRC(KC_S)  , KC_G         ,                               KC_Y         , KC_H         , KC_A         , KC_E         , KC_I         , KC_SCLN      ,
        XXXXXXX      , KC_Q         , KC_X         , KC_M         , KC_C         , KC_V         , _______      , _______      , KC_K         , KC_P         , KC_DOT       , KC_MINS      , KC_SLSH      , KC_COMM      ,
                                      _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______
    ),

    [L_GRAP2] = LAYOUT(
        KC_GRV       , KC_1         , KC_2         , KC_3         , KC_4         , KC_5         ,                               KC_6         , KC_7         , KC_8         , KC_9         , KC_0         , KC_BSPC      ,
        KC_TAB       , KC_Q         , KC_X         , KC_M         , KC_W         , KC_Z         ,                               KC_QUOT      , KC_F         , KC_O         , KC_U         , KC_J         , KC_COMM      ,
        KC_ESC       , KC_N         , LTNUM(KC_R)  , LTSYM(KC_T)  , LTBRC(KC_S)  , KC_G         ,                               KC_Y         , KC_H         , KC_A         , KC_E         , KC_I         , KC_SCLN      ,
        XXXXXXX      , KC_B         , KC_L         , KC_D         , KC_C         , KC_V         , _______      , _______      , KC_K         , KC_P         , KC_DOT       , KC_MINS      , KC_SLSH      , KC_COMM      ,
                                      _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______
    ),

    [L_GALL] = LAYOUT(
        KC_GRV       , KC_1         , KC_2         , KC_3         , KC_4         , KC_5         ,                               KC_6         , KC_7         , KC_8         , KC_9         , KC_0         , KC_BSPC      ,
        KC_TAB       , KC_Q         , KC_X         , KC_M         , KC_W         , KC_Z         ,                               KC_J         , KC_F         , KC_O         , KC_U         , KC_QUOT      , KC_BSLS      ,
        KC_ESC       , KC_N         , LTNUM(KC_R)  , LTSYM(KC_T)  , LTBRC(KC_S)  , KC_G         ,                               KC_Y         , KC_H         , KC_A         , KC_E         , KC_I         , KC_SCLN      ,
        XXXXXXX      , KC_B         , KC_L         , KC_D         , KC_C         , KC_V         , _______      , _______      , KC_K         , KC_P         , KC_COMM      , KC_DOT       , KC_SLSH      , KC_MINS      ,
                                      _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______
    ),

    [L_SYM] = LAYOUT(
        _______      , _______      , _______      , _______      , _______      , _______      ,                               _______      , _______      , _______      , _______      , _______      , _______      ,
        _______      , _______      , KC_PIPE      , KC_DLR       , KC_AMPR      , KC_CIRC      ,                               KC_CIRC      , KC_AMPR      , KC_DLR       , KC_PIPE      , _______      , _______      ,
        _______      , KC_EXLM      , KC_GRV       , KC_HASH      , KC_EQL       , KC_PERC      ,                               KC_PERC      , KC_EQL       , KC_HASH      , KC_GRV       , KC_EXLM      , _______      ,
        _______      , _______      , KC_AT        , KC_PLUS      , KC_ASTR      , KC_BSLS      , _______      , _______      , KC_BSLS      , KC_ASTR      , KC_PLUS      , KC_AT        , _______      , _______      ,
                                      _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______
    ),

    [L_BRC] = LAYOUT(
        _______      , _______      , _______      , _______      , _______      , _______      ,                               _______      , _______      , _______      , _______      , _______      , _______      ,
        _______      , _______      , _______      , _______      , _______      , _______      ,                               _______      , KC_LABK      , KC_RABK      , _______      , _______      , _______      ,
        _______      , KC_LCBR      , KC_RCBR      , KC_LPRN      , KC_RPRN      , _______      ,                               _______      , KC_LPRN      , KC_RPRN      , KC_LCBR      , KC_RCBR      , _______      ,
        _______      , _______      , _______      , KC_LBRC      , KC_RBRC      , _______      , _______      , _______      , _______      , KC_LBRC      , KC_RBRC      , _______      , _______      , _______      ,
                                      _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______
    ),

    [L_NUM] = LAYOUT(
        _______      , _______      , _______      , _______      , _______      , _______      ,                               _______      , _______      , _______      , _______      , _______      , _______      ,
        _______      , _______      , KC_7         , KC_8         , KC_9         , _______      ,                               _______      , KC_7         , KC_8         , KC_9         , _______      , _______      ,
        _______      , KC_0         , KC_4         , KC_5         , KC_6         , KC_0         ,                               KC_0         , KC_4         , KC_5         , KC_6         , KC_0         , _______      ,
        _______      , _______      , KC_1         , KC_2         , KC_3         , _______      , _______      , _______      , _______      , KC_1         , KC_2         , KC_3         , _______      , _______      ,
                                      _______      , _______      , _______      , _______      , QK_LLCK      , KC_0         , _______      , _______      , _______      , _______
    ),

    [L_NAV] = LAYOUT(
        _______      , PDF(L_QWER)  , PDF(L_GRAP)  , PDF(L_GRAP2) , PDF(L_GALL)  , _______      ,                               _______      , _______      , _______      , _______      , _______      , _______      ,
        _______      , _______      , KC_0         , KC_CIRC      , KC_DLR       , _______      ,                               KC_PGUP      , KC_HOME      , KC_UP        , KC_END       , _______      , _______      ,
        _______      , _______      , KC_B         , KC_W         , KC_E         , C(KC_6)      ,                               KC_PGDN      , KC_LEFT      , KC_DOWN      , KC_RGHT      , _______      , _______      ,
        _______      , _______      , _______      , S(KC_N)      , KC_N         , _______      , _______      , _______      , _______      , SHIFT_ALT_TAB, ALT_TAB      , _______      , _______      , _______      ,
                                      _______      , _______      , _______      , _______      , QK_LLCK      , _______      , _______      , _______      , _______      , _______
    ),

    [L_UTIL] = LAYOUT(
        XXXXXXX      , _______      , _______      , _______      , _______      , XXXXXXX      ,                               XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      ,
        XXXXXXX      , KC_INS       , _______      , _______      , _______      , XXXXXXX      ,                               XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      ,
        XXXXXXX      , _______      , _______      , S(C(KC_C))   , S(C(KC_V))   , XXXXXXX      ,                               XXXXXXX      , KC_VOLD      , KC_MUTE      , KC_VOLU      , XXXXXXX      , XXXXXXX      ,
        XXXXXXX      , C(KC_Z)      , C(KC_X)      , C(KC_C)      , C(KC_V)      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , KC_MPRV      , KC_MPLY      , KC_MNXT      , XXXXXXX      , XXXXXXX      ,
                                      _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______
    )
};

const key_override_t dot_gt_override           = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_GT, L_GRAP | L_GRAP2);
const key_override_t dash_quote_override       = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, KC_DQT, L_GRAP | L_GRAP2);
const key_override_t slash_lt_override         = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, KC_LT, L_GRAP | L_GRAP2);
const key_override_t comma_question_override   = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_QUES, L_GRAP | L_GRAP2);
const key_override_t qoute_underscore_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOT, KC_UNDS, L_GRAP | L_GRAP2);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &dot_gt_override, &dash_quote_override, &slash_lt_override, &comma_question_override, &qoute_underscore_override,
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [L_QWER] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK)},
    [L_GRAP] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK)},
    [L_GRAP2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK)},
    [L_GALL] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK)},
    [L_SYM] = {ENCODER_CCW_CW(UG_HUED, UG_HUEU), ENCODER_CCW_CW(UG_SATD, UG_SATU)},
    [L_BRC] = {ENCODER_CCW_CW(UG_HUED, UG_HUEU), ENCODER_CCW_CW(UG_SATD, UG_SATU)},
    [L_NUM] = {ENCODER_CCW_CW(UG_VALD, UG_VALU), ENCODER_CCW_CW(UG_SPDD, UG_SPDU)},
    [L_NAV] = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(C(KC_PGUP), C(KC_PGDN))},
    [L_UTIL] = {ENCODER_CCW_CW(RM_SPDU, RM_SPDD), ENCODER_CCW_CW(RM_PREV, RM_NEXT)}
};
#endif

const uint16_t PROGMEM left_brace_combo[] = {KC_F, KC_O, COMBO_END};
const uint16_t PROGMEM right_brace_combo[] = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM left_paren_combo[] = {KC_H, KC_A, COMBO_END};
const uint16_t PROGMEM right_paren_combo[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM left_bracket_combo[] = {KC_P, KC_COMM, COMBO_END};
const uint16_t PROGMEM right_bracket_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM left_angle_bracket_combo[] = {KC_F, KC_H, COMBO_END};
const uint16_t PROGMEM equals_combo[] = {KC_O, KC_A, COMBO_END};
const uint16_t PROGMEM right_angle_bracket_combo[] = {KC_U, KC_E, COMBO_END};

combo_t key_combos[]   = {
    // COMBO(left_brace_combo, KC_LCBR),
    // COMBO(right_brace_combo, KC_RCBR),
    // COMBO(left_paren_combo, KC_LPRN),
    // COMBO(right_paren_combo, KC_RPRN),
    // COMBO(left_bracket_combo, KC_LBRC),
    // COMBO(right_bracket_combo, KC_RBRC),
    // COMBO(left_angle_bracket_combo, KC_LABK),
    // COMBO(equals_combo, KC_EQL),
    // COMBO(right_angle_bracket_combo, KC_RABK),
};

bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(default_layer_state)) {
        case L_QWER:
            rgb_matrix_set_color(4, 0, 0, 255);
            break;
        case L_GRAP:
            rgb_matrix_set_color(3, 0, 0, 255);
            break;
        case L_GRAP2:
            rgb_matrix_set_color(2, 0, 0, 255);
            break;
        case L_GALL:
            rgb_matrix_set_color(1, 0, 0, 255);
            break;
        default:
            break;
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
