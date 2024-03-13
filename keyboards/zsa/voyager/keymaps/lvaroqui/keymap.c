#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "sendstring_french.h"
#include "process_key_override.h"
#include "process_tap_dance.h"

#include "features/achordion.h"

#include "print.h"

// TODO
// - special key on all layers
// - symbol layers
// - top row

enum {
    HOME_PLUS,
    CT_DOT,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    QK_BOOTLOADER,      FR_1,           KC_2,         KC_3,            KC_4,              KC_5,      /* */        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_TAB,             FR_AGRV,        FR_J,         FR_O,            FR_EACU,           FR_B,      /* */        FR_F,           FR_D,           FR_L,           FR_QUOT,        FR_Q,           FR_X,
    CW_TOGG,            LGUI_T(FR_A),   LALT_T(FR_I), LSFT_T(FR_E),    LCTL_T(FR_U),      FR_COMM,   /* */        FR_P,           RCTL_T(FR_T),   RSFT_T(FR_S),   LALT_T(FR_R),   RGUI_T(FR_N),   FR_CIRC,
    C(FR_Z),            FR_K,           LT(0, FR_Y),  LT(0, FR_EGRV),  TD(CT_DOT),        FR_W,      /* */        FR_G,           FR_C,           FR_M,           FR_H,           FR_V,           FR_Z,
                                                                        LT(1, KC_ENTER), KC_ESC,     /* */        LT(2, KC_BACKSPACE), LT(2, KC_SPACE)
  ),
  [1] = LAYOUT(
    KC_F1,          KC_F2,           KC_F3,           KC_F4,            KC_F5,            KC_F6,     /* */        KC_F7,          KC_F8,          KC_F9,          KC_F10,          KC_F11,         KC_F12,
    KC_TRANSPARENT, FR_QUOT,         FR_LABK,         FR_RABK,          FR_DQUO,          FR_DOT,    /* */        FR_AMPR,        FR_SCLN,        FR_LBRC,        FR_RBRC,         FR_PERC,        KC_NO,
    KC_TRANSPARENT, LGUI_T(FR_EXLM), LALT_T(FR_MINS), TD(HOME_PLUS),    LCTL_T(FR_EQL),   FR_HASH,   /* */        FR_PIPE,        FR_COLN,        FR_LPRN,        FR_RPRN,         FR_QUES,        KC_BACKSPACE,
    KC_TRANSPARENT, FR_CIRC,         FR_SLSH,         FR_ASTR,          FR_BSLS,          KC_NO,     /* */        FR_TILD,        FR_DLR,         FR_LCBR,        FR_RCBR,         FR_AT,          KC_ENTER,
                                                                   KC_TRANSPARENT, KC_TRANSPARENT,   /* */        KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MOD,        KC_TRANSPARENT,        RGB_VAD,        RGB_VAI,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  KC_TRANSPARENT,                                 KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LGUI_T(KC_MEDIA_PREV_TRACK),LALT_T(KC_MEDIA_NEXT_TRACK),LSFT_T(KC_MEDIA_STOP),  LCTL_T(KC_MEDIA_PLAY_PAUSE),KC_TRANSPARENT,                                 KC_PAGE_DOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT,                                KC_TRANSPARENT, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};
// clang-format on

const key_override_t **key_overrides = (const key_override_t *[]){
    &ko_make_basic(MOD_MASK_SHIFT, FR_COMM, FR_SCLN),               //
    &ko_make_basic(MOD_MASK_SHIFT, FR_QUOT, FR_QUES),               //
    &ko_make_basic(MOD_MASK_SHIFT, FR_CIRC, FR_EXLM),               //
    &ko_make_basic(MOD_MASK_SHIFT, LT(2, KC_BACKSPACE), KC_DELETE), //
    NULL                                                            // Null terminate the array of overrides!
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2, KC_BACKSPACE):
        case LT(2, KC_SPACE):
            return 200;
        default:
            return QUICK_TAP_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case FR_EACU:
            if (record->event.pressed) {
                const uint8_t mods = get_mods() | get_weak_mods() | get_oneshot_mods();
                if (mods & MOD_MASK_SHIFT) {
                    tap_code16(C(S(FR_U)));
                    wait_ms(10);
                    tap_code16(FR_C);
                    wait_ms(10);
                    tap_code16(FR_9);
                    wait_ms(10);

                    del_weak_mods(MOD_MASK_SHIFT);
        #ifndef NO_ACTION_ONESHOT
                    del_oneshot_mods(MOD_MASK_SHIFT);
        #endif // NO_ACTION_ONESHOT
                    unregister_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_SPACE);
                    set_mods(mods);
                } else {
                    tap_code16(FR_EACU);
                }
            }
            return false;
        case FR_AGRV:
            if (record->event.pressed) {
                const uint8_t mods = get_mods() | get_weak_mods() | get_oneshot_mods();
                if (mods & MOD_MASK_SHIFT) {
                    tap_code16(C(S(FR_U)));
                    wait_ms(10);
                    tap_code16(FR_C);
                    wait_ms(10);
                    tap_code16(FR_0);
                    wait_ms(10);

                    del_weak_mods(MOD_MASK_SHIFT);
        #ifndef NO_ACTION_ONESHOT
                    del_oneshot_mods(MOD_MASK_SHIFT);
        #endif // NO_ACTION_ONESHOT
                    unregister_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_SPACE);
                    set_mods(mods);
                } else {
                    tap_code16(FR_AGRV);
                }
            }
            return false;
        case LT(0, FR_Y):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(FR_X)); // Intercept hold function to send Ctrl-X
                return false;
            }
            return true;
        case LT(0, FR_EGRV):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(FR_C)); // Intercept hold function to send Ctrl-C
                return false;
            }
            return true;
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
        case LT(2, KC_BACKSPACE):
            return 0; // Bypass Achordion for these keys.
    }

    return 800; // Otherwise use a timeout of 800 ms.
}

typedef struct {
    uint16_t tap;
    uint16_t tap_shifted;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed)
#ifndef PERMISSIVE_HOLD
        &&!state->interrupted
#endif
        {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        }
}

void tap_dance_tap_hold_released(tap_dance_state_t *state, void *user_data) {
    if (state->finished) {
        return;
    }

    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    const uint8_t saved_mods = get_mods();
#ifndef NO_ACTION_ONESHOT
    const uint8_t mods = saved_mods | get_weak_mods() | get_oneshot_mods();
#else
    const uint8_t mods = saved_mods | get_weak_mods();
#endif // NO_ACTION_ONESHOT

    if ((mods & MOD_MASK_SHIFT) != 0) // Shift is held
    {
        if ((QK_MODS_GET_MODS(tap_hold->tap_shifted) & MOD_LSFT) != 0) // Key requires Shift
        {
            tap_code16(tap_hold->tap_shifted); // If so, press directly.
        } else {
            // If not, cancel shift mods, press the key, and restore mods.
            del_weak_mods(MOD_MASK_SHIFT);
#ifndef NO_ACTION_ONESHOT
            del_oneshot_mods(MOD_MASK_SHIFT);
#endif // NO_ACTION_ONESHOT
            unregister_mods(MOD_MASK_SHIFT);
            tap_code16(tap_hold->tap_shifted);
            set_mods(mods);
        }
    } else {
        tap_code16(tap_hold->tap);
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, tap_shifted, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset, tap_dance_tap_hold_released}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, tap_shifted, hold, 0}), }

tap_dance_action_t tap_dance_actions[] = {
    [HOME_PLUS] = ACTION_TAP_DANCE_TAP_HOLD(FR_PLUS, KC_NO, KC_LSFT),
    [CT_DOT]    = ACTION_TAP_DANCE_TAP_HOLD(FR_DOT, FR_COLN, C(FR_V)),
};
