/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define TAPPING_TERM 200
#define QUICK_TAP_TERM 0
#define QUICK_TAP_TERM_PER_KEY
#define PERMISSIVE_HOLD

#define UNICODE_KEY_LNX LCTL(LSFT(KC_U))
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
#define UNICODE_TYPE_DELAY 100
