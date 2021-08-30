#include QMK_KEYBOARD_H
#include "quantum.h"

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

enum cajal_layers {
  _QWERTY,
  _ONE,
  _TWO
};


// better spacebar
#define AA_SPC LT(_ONE, KC_SPC)

// My custom Mod-Tap constants
#define AA_Z MT(MOD_LCTL | MOD_LALT | MOD_LGUI | MOD_LSFT, KC_Z)
#define AA_X MT(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_X)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_stagger(
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, KC_BSPC, RGB_TOG,
      LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
      KC_LSFT, AA_Z, AA_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP,
      KC_LCTL, KC_LGUI, KC_LALT, AA_SPC, KC_SPC, KC_SPC, MO(_TWO), KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_ONE] = LAYOUT_stagger(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_RBRC, KC_BSLS, RGB_MOD,
      KC_TRNS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_QUOT, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_TRNS, KC_PGUP,
      RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END
  ),
  [_TWO] = LAYOUT_stagger(
      KC_TILD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SAD, RGB_SAI, KC_TRNS, RGB_VAI,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_HUD, RGB_VAD, RGB_HUI
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return true;
}


// leave my CTL_T(KC_ESC) alone {{{
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AA_Z:
        case AA_X:
            return true;
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AA_Z:
        case AA_X:
            return true;
        default:
            return false;
    }
}
// }}}
