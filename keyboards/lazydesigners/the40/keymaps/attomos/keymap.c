/* Copyright 2020 LAZYDESIGNERS
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


enum the40_layers {
  _QWERTY,
  _QWERTY_CSGO,
  _NUMPAD,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAV
};

enum the40_keycodes {
  QWERTY = SAFE_RANGE,
  QWERCSGO,
  ATOM_M1,
  ATOM_M2,
  ATOM_M3,
  ATOM_M4,
  ATOM_M5,
  ATOM_M6,
  ATOM_M7,
  ATOM_M8,
  NN_A,
  NN_S,
  NN_W,
  NN_D,
  NN_T,
  NN_Q,
  NN_E,
  NN_N,
  NN_SPC
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NUMPAD TG(_NUMPAD)
#define NAV TG(_NAV)

// My custom Mod-Tap constants
#define AA_Z MT(MOD_LCTL | MOD_LALT | MOD_LGUI | MOD_LSFT, KC_Z)
#define AA_X MT(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_X)

// Partial home-row mods
#define AA_K RGUI_T(KC_K)
#define AA_SCLN LGUI_T(KC_SCLN)

#define AA_SPC LT(_NAV, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down | Up   |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho(
    KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    AA_K,    KC_L,    AA_SCLN, KC_QUOT,
    KC_LSFT,        AA_Z,    AA_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL,        KC_LCTL, KC_LGUI, KC_LALT, LOWER,   AA_SPC,  AA_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Qwerty CSGO (QwerCS)
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Ctrl | Alt  | GUI  |Raise |    Space    |Lower | Left | Down | Up   |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY_CSGO] = LAYOUT_ortho(
    KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    LCTL_T(KC_ESC), KC_LCTL, KC_LGUI, KC_LALT, RAISE,   KC_SPC,  KC_SPC,  LOWER,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | F13  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |      |      |  M1  |  M2  |  M4  |  M5  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  M7  |  M8  |      |      |      |  M6  |  M3  | Prev | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Nump  |      |      |      |      |             |      | Next | Bri- | Bri+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F13,
    KC_DEL,  _______, _______, ATOM_M1, ATOM_M2, ATOM_M4, ATOM_M5, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
       NAV, ATOM_M7, ATOM_M8, _______, _______, _______, ATOM_M6, ATOM_M3, KC_MPRV, KC_HOME, KC_END,  _______,
    NUMPAD,  _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_BRID, KC_BRIU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CSGO |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |QWERTY|      |      |      |      |             |      | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Numpad + (Readline home/end, select all, undo, cut, and copy)
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      |      |   E  |      |      |      |   7  |   8  |   9  |   -  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |      |      |  F   |      |   =  |   4  |   5  |   6  |   +  |  *   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |      |      |   .  |   1  |   2  |   3  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Nump | Ctrl | Alt  | GUI  |Lower |    Space    |   0  | Left | Down | Up   |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho(
    KC_TAB,        XXXXXXX, XXXXXXX, KC_E,    XXXXXXX, XXXXXXX, XXXXXXX,  KC_7,  KC_8,    KC_9,    KC_MINS, KC_BSPC,
    CTL_T(KC_ESC), KC_A,    XXXXXXX, XXXXXXX, KC_F, XXXXXXX, KC_EQL,  KC_4,  KC_5,    KC_6,    KC_PLUS, KC_ASTR,
    KC_LSFT,       KC_Z   , KC_X,    KC_C,    XXXXXXX, XXXXXXX, KC_DOT,    KC_1,  KC_2,    KC_3,    KC_SLSH, KC_ENT ,
    NUMPAD,        KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  KC_0, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      | UP+  |      |      |      |      |      |      |      | Up   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | LEFT+| DOWN+|RIGHT+|      |      | Left | Down | Up   | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Down |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_ortho(
    _______,    NN_Q,    NN_W,     NN_E, _______,    NN_T, _______, _______, _______, _______, _______, _______,
    _______,    NN_A,    NN_S,     NN_D, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
        NAV, _______, _______,  _______, _______, _______,    NN_N, _______, _______, _______, _______, _______,
    _______, _______, _______,  _______, _______,  NN_SPC,  NN_SPC, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug |      |      |             |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Qwerty|      |      |      |QwerCS|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho(
    _______,   RESET,   DEBUG, _______, _______, _______, _______, _______, _______,  _______, _______, _______ ,
    _______, _______, _______, _______, _______, _______, _______,  QWERTY, _______,  _______, _______, QWERCSGO,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case QWERCSGO:
      if (record->event.pressed) {
        print("mode just switched to qwerty CSGO and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY_CSGO);
      }
      return false;
      break;
    case NN_Q:
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
    case NN_E:
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
    case ATOM_M3:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_F12);
      } else {
        unregister_code(KC_LGUI);
        unregister_code(KC_F12);
      }
      return false;
      break;
    case ATOM_M4:
      if (record->event.pressed) {
        SEND_STRING("[t");
      }
      return false;
      break;
    case ATOM_M5:
      if (record->event.pressed) {
        SEND_STRING("]t");
      }
      return false;
      break;
    case ATOM_M6:
      if (record->event.pressed) {
        SEND_STRING("]T");
      }
      return false;
      break;
    case ATOM_M7:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_LALT);
        register_code(KC_LSFT);
        register_code(KC_4);
      } else {
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LSFT);
        unregister_code(KC_4);
      }
      return false;
      break;
    case ATOM_M8:
      if (record->event.pressed) {
        register_code(KC_LALT);
        register_code(KC_LSFT);
        register_code(KC_3);
      } else {
        unregister_code(KC_LALT);
        unregister_code(KC_LSFT);
        unregister_code(KC_3);
      }
      return false;
      break;
    case NN_A:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        register_code(KC_LEFT);
      } else {
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
        unregister_code(KC_LEFT);
      }
      return false;
      break;
    case NN_S:
      if (record->event.pressed) {
        SEND_STRING(SS_RGUI("s"));
      }
      return false;
      break;
    case NN_W:
      if (record->event.pressed) {
        SEND_STRING(SS_RGUI("w"));
      }
      return false;
      break;
    case NN_D:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        register_code(KC_RGHT);
      } else {
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
        unregister_code(KC_RGHT);
      }
      return false;
      break;
    case NN_T:
      if (record->event.pressed) {
        SEND_STRING(SS_RGUI("t"));
      }
      return false;
      break;
    case NN_N:
      if (record->event.pressed) {
        register_code(KC_RGUI);
        register_code(KC_LSFT);
        register_code(KC_N);
      } else {
        unregister_code(KC_RGUI);
        unregister_code(KC_LSFT);
        unregister_code(KC_N);
      }
      return false;
      break;
    case NN_SPC:
      if (record->event.pressed) {
        register_code(KC_RGUI);
        register_code(KC_BSPC);
      } else {
        unregister_code(KC_RGUI);
        unregister_code(KC_BSPC);
      }
      return false;
      break;
  }
  return true;
}


// leave my CTL_T(KC_ESC) alone {{{
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AA_Z:
            return true;
        case AA_X:
            return true;
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AA_Z:
            return true;
        case AA_X:
            return true;
        default:
            return false;
    }
}
// }}}
