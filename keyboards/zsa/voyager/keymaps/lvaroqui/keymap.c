#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "sendstring_french.h" // IWYU pragma: keep
#include "process_key_override.h"
#include "process_tap_dance.h"

#include "features/achordion.h"

#include "print.h" // IWYU pragma: keep

enum {
    HOME_SLSH,
    HOME_LBRC,
    HOME_LCBR,
    HOME_SHORT_GUI,
    HOME_SHORT_ALT,
    HOME_SHORT_SHFT,
    HOME_SHORT_CTRL,
    CT_DOT,
    CT_EGRV,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    DB_TOGG,            FR_1,           FR_2,         FR_3,            FR_4,              FR_5,      /* */     FR_6,           FR_7,           FR_8,           FR_9,           FR_0,           KC_PRINT_SCREEN,
    KC_TAB,             FR_AGRV,        FR_J,         FR_O,            FR_EACU,           FR_B,      /* */     FR_F,           FR_D,           FR_L,           FR_QUOT,        FR_X,           FR_UGRV,
    CW_TOGG,            LGUI_T(FR_A),   LALT_T(FR_I), LSFT_T(FR_E),    LCTL_T(FR_U),      FR_COMM,   /* */     FR_P,           RCTL_T(FR_T),   RSFT_T(FR_S),   LALT_T(FR_R),   RGUI_T(FR_N),   FR_CIRC,
    C(FR_Z),            FR_K,           LT(0, FR_Y),  TD(CT_EGRV),     TD(CT_DOT),        FR_W,      /* */     FR_G,           FR_C,           FR_M,           FR_H,           FR_V,           KC_APP,
                                                                 LT(1, KC_ENTER), LT(3, KC_ESC),     /* */     LT(4, KC_BACKSPACE), LT(2, KC_SPACE)
  ),
  [1] = LAYOUT(
    QK_BOOTLOADER,  KC_F1,           KC_F2,             KC_F3,            KC_F4,             KC_F5,   /* */     KC_F6,        KC_F7,           KC_F8,         KC_F9,          KC_F10,          KC_F11,
    KC_TRANSPARENT, FR_HASH,         FR_PLUS,           FR_AMPR,          FR_DQUO,           KC_NO,   /* */     FR_QUES,      FR_PIPE,         FR_TILD,       FR_PERC,        FR_GRV,          KC_F12,
    KC_TRANSPARENT, LGUI_T(FR_EQL),  TD(HOME_SLSH),     LSFT_T(FR_MINS),  LCTL_T(FR_UNDS),   FR_DLR,  /* */     FR_EXLM,      RCTL_T(FR_LPRN), TD(HOME_LBRC), TD(HOME_LCBR),  RGUI_T(FR_LABK), FR_DIAE,
    KC_TRANSPARENT, FR_AT,           FR_BSLS,           LT(0,FR_ASTR),    LT(0,FR_DOT),      KC_NO,   /* */     KC_NO,        FR_RPRN,         FR_RBRC,       FR_RCBR,        FR_RABK,         KC_NO,
                                                                    KC_TRANSPARENT, KC_TRANSPARENT,   /* */     KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT(
    KC_TRANSPARENT,     KC_NO,              KC_NO,              KC_NO,                S(C(FR_A)),          KC_NO,        /* */      KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,     C(A(FR_UNDS)),      KC_NO,              KC_NO,                S(C(FR_COLN)),       KC_DELETE,    /* */      KC_PGUP,        KC_HOME,          KC_UP,          KC_END,         KC_TRANSPARENT, KC_TRANSPARENT,
    G(FR_Q),            TD(HOME_SHORT_GUI), TD(HOME_SHORT_ALT), TD(HOME_SHORT_SHFT),  TD(HOME_SHORT_CTRL), KC_BACKSPACE, /* */      KC_PAGE_DOWN,   KC_LEFT,          KC_DOWN,        KC_RIGHT,       KC_TAB,         FR_DIAE,
    KC_TRANSPARENT,     S(C(FR_F)),         C(FR_F),            S(KC_F3),             KC_F3,               KC_F4,        /* */      KC_DELETE,      KC_BTN4,          KC_F12,         KC_BTN5,        KC_TRANSPARENT, S(C(FR_DOT)),
                                                                                  KC_TRANSPARENT, KC_TRANSPARENT,        /* */      KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT(
    KC_TRANSPARENT,     KC_NO,              KC_NO,              KC_NO,                S(C(FR_A)),          KC_NO,        /* */      FR_SLSH,     KC_NO,     KC_NO,     KC_NO,  KC_NO,     KC_NO,
    KC_TRANSPARENT,     C(A(FR_UNDS)),      KC_NO,              KC_NO,                S(C(FR_COLN)),       KC_DELETE,    /* */      FR_ASTR,     FR_7,      FR_8,      FR_9,   FR_COMM,   KC_NO,
    G(FR_Q),            TD(HOME_SHORT_GUI), TD(HOME_SHORT_ALT), TD(HOME_SHORT_SHFT),  TD(HOME_SHORT_CTRL), KC_BACKSPACE, /* */      FR_PLUS,     FR_4,      FR_5,      FR_6,   FR_0,      KC_NO,
    KC_TRANSPARENT,     S(C(FR_F)),         C(FR_F),            S(KC_F3),             KC_F3,               KC_F4,        /* */      FR_MINS,     FR_1,      FR_2,      FR_3,   FR_DOT,    KC_NO,
                                                                                  KC_TRANSPARENT, KC_TRANSPARENT,        /* */      KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT(
    KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,     /* */     KC_NO,    KC_NO,                 KC_NO,                  KC_NO,                 KC_NO,      KC_NO,
    KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,     /* */     KC_NO,    KC_MEDIA_PREV_TRACK,   KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_NEXT_TRACK,   KC_NO,      KC_NO,
    KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,     /* */     KC_NO,    KC_VOLD,               KC_MUTE,                KC_VOLU,               KC_NO,      KC_NO,
    KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,     /* */     KC_NO,    KC_NO,                 A(FR_A),                KC_NO,                 KC_NO,      KC_NO,
                                        KC_TRANSPARENT, KC_TRANSPARENT,     /* */     KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT(
    TO(0),            KC_5,  KC_1,    KC_2,   KC_3,   KC_4,   /* */    KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_TRANSPARENT,   FR_T,  FR_A,    FR_Z,   FR_E,   FR_R,   /* */    KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_LEFT_SHIFT,    FR_G,  FR_Q,    FR_S,   FR_D,   FR_F,   /* */    KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_LEFT_CTRL,     FR_V,  FR_W,    FR_X,   FR_C,   FR_B,   /* */    KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                            KC_TRANSPARENT, KC_TRANSPARENT,   /* */    KC_TRANSPARENT, KC_TRANSPARENT
  ),
};
// clang-format on

const uint16_t PROGMEM combo_ctrl_enter[]  = {LCTL_T(FR_U), LT(1, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo_shift_enter[] = {LSFT_T(FR_E), LT(1, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo_d_l[]         = {FR_D, FR_L, COMBO_END};
const uint16_t PROGMEM combo_c_m[]         = {FR_C, FR_M, COMBO_END};
const uint16_t PROGMEM combo_m_h[]         = {FR_M, FR_H, COMBO_END};
const uint16_t PROGMEM combo_d_f[]         = {FR_F, FR_D, COMBO_END};
combo_t                key_combos[]        = {
    COMBO(combo_ctrl_enter, FR_UNDS),  //
    COMBO(combo_shift_enter, FR_MINS), //
    COMBO(combo_d_l, FR_Q),            //
    COMBO(combo_c_m, FR_CCED),         //
    COMBO(combo_m_h, FR_Z),            //
    COMBO(combo_d_f, FR_UGRV),         //
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(FR_A):
            return TAPPING_TERM + 200;
        default:
            return TAPPING_TERM;
    }
}

#define PPCAT_NX(A, B) A##B
#define GUI_NUM(num, key) &ko_make_basic(MOD_MASK_GUI | MOD_MASK_SHIFT, PPCAT_NX(FR_, num), G(S(key))), &ko_make_basic(MOD_MASK_GUI, PPCAT_NX(FR_, num), G(key))

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard=true;
    // debug_mouse=true;
}

const key_override_t **key_overrides = (const key_override_t *[]){
    &ko_make_basic(MOD_MASK_SHIFT, FR_COMM, FR_SCLN),             //
    &ko_make_basic(MOD_MASK_SHIFT, FR_QUOT, FR_QUES),             //
    &ko_make_basic(MOD_MASK_SHIFT, FR_CIRC, FR_EXLM),             //
    GUI_NUM(0, FR_AGRV),                                          //
    GUI_NUM(1, FR_AMPR),                                          //
    GUI_NUM(2, FR_EACU),                                          //
    GUI_NUM(3, FR_DQUO),                                          //
    GUI_NUM(4, FR_QUOT),                                          //
    GUI_NUM(5, FR_LPRN),                                          //
    GUI_NUM(6, FR_MINS),                                          //
    GUI_NUM(7, FR_EGRV),                                          //
    GUI_NUM(8, FR_UNDS),                                          //
    GUI_NUM(9, FR_CCED),                                          //
    &ko_make_basic(MOD_MASK_GUI, LT(4, KC_BACKSPACE), KC_DELETE), //
    &ko_make_basic(MOD_MASK_GUI, KC_BACKSPACE, KC_DELETE),        //
    NULL                                                          // Null terminate the array of overrides!
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(4, KC_BACKSPACE):
        case LT(2, KC_SPACE):
            return 200;
        default:
            return QUICK_TAP_TERM;
    }
}

bool is_accented_key(uint16_t keycode) {
    switch (keycode) {
        case FR_EACU:
        case FR_AGRV:
        case FR_CCED:
        case FR_EGRV:
            return true;
        default:
            return false;
    }
}

bool tap_accented_key(uint16_t keycode) {
    const uint8_t mods = get_mods() | get_weak_mods() | get_oneshot_mods();
    if (mods & MOD_MASK_SHIFT || is_caps_word_on()) {
        dprintf("tap it\n");
        del_weak_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);
        unregister_mods(MOD_MASK_SHIFT);

        register_code(KC_LOCKING_CAPS_LOCK);
        tap_code16(keycode);
        unregister_code(KC_LOCKING_CAPS_LOCK);

        set_mods(mods);
        return false;
    } else {
        return true;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    if (record->event.pressed && is_accented_key(keycode)) {
        return tap_accented_key(keycode & 0xFF);
    }

    if (record->event.pressed) {
        switch (keycode) {
            case LT(0, FR_ASTR):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(C(S(FR_C)));
                    return false;
                }
                return true;
            case LT(0, FR_Y):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(C(FR_X));
                    return false;
                }
                return true;
            case LT(0, FR_DOT):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(C(S(FR_V)));
                    return false;
                }
                return true;
        }
    }
    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case LT(1, KC_ENTER):
        case LT(2, KC_SPACE):
        case LT(4, KC_BACKSPACE):
        case LT(3, KC_ESC):
            return 0; // Bypass Achordion for these keys.
    }

    return TAPPING_TERM; // Otherwise use a timeout of 800 ms.
}

typedef struct {
    uint16_t tap;
    uint16_t tap_shifted;
    uint16_t double_tap;
    uint16_t hold;
    uint16_t double_hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_while_shifted(uint16_t key) {
    if (QK_MODS_GET_MODS(key) & MOD_LSFT) {
        // Key requires Shift
        tap_code16(key); // If so, press directly.
    } else {
        // If not, cancel shift mods, press the key, and restore mods.
        const uint8_t mods = get_mods() | get_weak_mods() | get_oneshot_mods();
        del_weak_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);
        unregister_mods(MOD_MASK_SHIFT);
        tap_code16(key);
        set_mods(mods);
    }
}

bool tap_dance_has_double_tap(tap_dance_state_t *state, const tap_dance_tap_hold_t *tap_hold) {
    return tap_hold->double_tap != KC_NO || tap_hold->double_hold != KC_NO;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    // HOLD
    if (state->pressed) {
        if (state->count == 1) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else if (state->count == 2) {
            register_code16(tap_hold->double_hold);
            tap_hold->held = tap_hold->double_hold;
        }
    }
    // TAP
    else {
        for (uint8_t i = 0; i < state->count; i++) {
            tap_code16(tap_hold->tap);
        }
    }
}

void tap_dance_tap_hold_on_each_released(tap_dance_state_t *state, void *user_data) {
    if (state->finished) {
        return;
    }

    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;
    if (is_accented_key(tap_hold->tap) && !tap_accented_key(tap_hold->tap)) {
        return;
    }

    // eagerly press key to avoid delay with shift key
    const uint8_t mods = get_mods() | get_weak_mods() | get_oneshot_mods();
    if (tap_hold->tap_shifted && mods & MOD_MASK_SHIFT) // Shift is held
    {
        tap_while_shifted(tap_hold->tap_shifted);
        reset_tap_dance(state);
    }
    // When no double tap are bound, eagerly press key to avoid delay
    else if (!tap_dance_has_double_tap(state, tap_hold)) {
        tap_code16(tap_hold->tap);
        reset_tap_dance(state);
    }
    // If key was released two times, eagerly send double tap to avoid delay
    else if (tap_hold->double_tap && state->count == 2) {
        tap_code16(tap_hold->double_tap);
        reset_tap_dance(state);
    }
    // If key was released two times, eagerly send key twice to avoid delay
    else if (state->count == 2) {
        for (int i = 0; i < 2; i++) {
            tap_code16(tap_hold->tap);
        }
        reset_tap_dance(state);
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, tap_shifted, hold, double_tap, double_hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset, tap_dance_tap_hold_on_each_released}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, tap_shifted, double_tap, hold, double_hold, 0}), }

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
    [HOME_SLSH] = ACTION_TAP_DANCE_TAP_HOLD(FR_SLSH, KC_NO, KC_LALT, KC_NO, KC_NO),
    [HOME_LBRC] = ACTION_TAP_DANCE_TAP_HOLD(FR_LBRC, KC_NO, KC_RSFT, KC_NO, KC_NO),
    [HOME_LCBR] = ACTION_TAP_DANCE_TAP_HOLD(FR_LCBR, KC_NO, KC_LALT, KC_NO, KC_NO),
    [CT_DOT]    = ACTION_TAP_DANCE_TAP_HOLD(FR_DOT, FR_COLN, C(FR_V), KC_NO, S(C(FR_V))),
    [CT_EGRV]   = ACTION_TAP_DANCE_TAP_HOLD(FR_EGRV, FR_EGRV, C(FR_C), KC_NO, S(C(FR_C))),
    [HOME_SHORT_GUI]  = ACTION_TAP_DANCE_TAP_HOLD(KC_NO, KC_NO, KC_LGUI, KC_NO, KC_NO),
    [HOME_SHORT_ALT]  = ACTION_TAP_DANCE_TAP_HOLD(KC_NO, KC_NO, KC_LALT, G(FR_Q), KC_NO),
    [HOME_SHORT_SHFT] = ACTION_TAP_DANCE_TAP_HOLD(C(FR_S), KC_NO, KC_LSFT, KC_NO, KC_NO),
    [HOME_SHORT_CTRL] = ACTION_TAP_DANCE_TAP_HOLD(C(S(FR_D)), KC_NO, KC_LCTL, KC_NO, KC_NO),
};
// clang-format on

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case FR_A:
        case FR_B:
        case FR_C:
        case FR_D:
        case FR_E:
        case FR_F:
        case FR_G:
        case FR_H:
        case FR_I:
        case FR_J:
        case FR_K:
        case FR_L:
        case FR_M:
        case FR_N:
        case FR_O:
        case FR_P:
        case FR_Q:
        case FR_R:
        case FR_S:
        case FR_T:
        case FR_U:
        case FR_V:
        case FR_W:
        case FR_X:
        case FR_Y:
        case FR_Z:
        case FR_AGRV:
        case FR_EGRV:
        case FR_EACU:
        case FR_QUOT:
        case FR_CIRC:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case FR_1:
        case FR_2:
        case FR_3:
        case FR_4:
        case FR_5:
        case FR_6:
        case FR_7:
        case FR_8:
        case FR_9:
        case KC_BSPC:
        case KC_DEL:
        case FR_UNDS:
        case TD(CT_EGRV):
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case 5:
                rgb_matrix_set_color(i, RGB_ORANGE);
                break;
            case 4:
                if (i == 39 || i == 40 || i == 41) {
                    rgb_matrix_set_color(i, RGB_ORANGE);
                } else if (i == 33 || i == 34 || i == 35) {
                    rgb_matrix_set_color(i, RGB_BLUE);
                } else {
                    rgb_matrix_set_color(i, RGB_BLACK);
                }
                break;
            case 3:
                rgb_matrix_set_color(i, RGB_RED);
                break;
            case 2:
                if (i == 34 || i == 39 || i == 40 || i == 41) {
                    rgb_matrix_set_color(i, RGB_GREEN);
                } else {
                    rgb_matrix_set_color(i, RGB_BLUE);
                }
                break;
            case 1:
                rgb_matrix_set_color(i, RGB_GOLD);
                break;
            case 0:
                rgb_matrix_set_color(i, RGB_ORANGE);
                break;
            default:
                break;
        }
    }
    return false;
}