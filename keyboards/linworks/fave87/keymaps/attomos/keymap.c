/* Copyright 2021 Moritz Plattner
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "quantum.h"

enum fave87_layers {
  _QWERTY,
  _NAV
};

enum fave87_keycodes {
  ATOM_M1 = SAFE_RANGE,
  ATOM_M2,
  ATOM_S1,
  ATOM_S2
};

// My custom Mod-Tap constants
#define AA_Z MT(MOD_LCTL | MOD_LALT | MOD_LSFT, KC_Z)
#define AA_X MT(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_X)
#define AA_SLSH LT(_NAV, KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_all(
    KC_ESC,          KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,                           KC_PSCR, KC_F13,  KC_MPLY,
    KC_GRV,          KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_BSLS,      KC_INS,  KC_HOME, KC_PGUP,
    KC_TAB,          KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,                KC_DEL,  KC_END,  KC_PGDN,
    LCTL_T(KC_ESC),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,
    KC_LSFT,         KC_NUBS,  AA_Z,     AA_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   AA_SLSH,  KC_RSFT,  KC_TRNS,                         KC_UP,
    KC_LGUI,         XXXXXXX,  KC_LALT,                      KC_SPC,                                           KC_RGUI,  XXXXXXX,  XXXXXXX,  MO(_NAV),               KC_LEFT, KC_DOWN, KC_RGHT),

  [_NAV] = LAYOUT_all(
    RGB_TOG,         RGB_VAD,  RGB_VAI,  BL_DEC,   BL_INC,   RGB_HUD,  RGB_HUI,  RGB_SAD,  RGB_SAI,  RGB_RMOD, RGB_MOD,  RGB_SPI,  RGB_SPI,                          KC_TRNS, RESET, KC_TRNS,
    KC_GRV,          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS, LCG_NRM, KC_BRIU,
    KC_TRNS,         ATOM_M1,  KC_UP,    ATOM_M2,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                KC_MUTE, LCG_SWP, KC_BRID,
    KC_TRNS,         KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_PIPE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,         KC_NUBS,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                         KC_VOLU,
    KC_TRNS,         KC_TRNS,  KC_TRNS,                      KC_TRNS,                                          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                KC_MPRV, KC_VOLD, KC_MNXT),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ATOM_M1:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_PGUP);
      } else {
        unregister_code(KC_LCTL);
        unregister_code(KC_PGUP);
      }
      return false;
      break;
    case ATOM_M2:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_PGDN);
      } else {
        unregister_code(KC_LCTL);
        unregister_code(KC_PGDN);
      }
      return false;
      break;
    case ATOM_S1:
      if (record->event.pressed) {
        tap_code(KC_SCROLLLOCK);
        tap_code(KC_SCROLLLOCK);
        tap_code(KC_1);
      }
      return false;
      break;
    case ATOM_S2:
      if (record->event.pressed) {
        tap_code(KC_SCROLLLOCK);
        tap_code(KC_SCROLLLOCK);
        tap_code(KC_2);
      }
      return false;
      break;
  }
  return true;
}


// functions for those PER_KEY configs {{{
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AA_Z:
        case AA_X:
        case AA_SLSH:
            return 900;
        default:
            return TAPPING_TERM;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AA_Z:
        case AA_X:
        case AA_SLSH:
            return true;
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AA_Z:
        case AA_X:
        case AA_SLSH:
            return true;
        default:
            return false;
    }
}
// }}}
