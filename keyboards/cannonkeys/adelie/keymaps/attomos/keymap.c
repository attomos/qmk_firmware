/* Copyright 2020 Andrew Kannan
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


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _LAYER1,
    _LAYER2,
    _LAYER3
};

enum adelie_keycodes {
  QWERTY = SAFE_RANGE,
  ATOM_M1,
  ATOM_M2,
  ATOM_M3,
  ATOM_M4,
  ATOM_M5,
  ATOM_M6,
  ATOM_M7,
  ATOM_M8,
  ATOM_M9,
  ATOM_N0,
  ATOM_N1,
  ATOM_S1,
  ATOM_S2,
  ATOM_S3,
  ATOM_S4,
  TMUX_M1,
  TMUX_M2,
  TMUX_M3,
  TMUX_M4,
  ATOM_T1,
  ATOM_T2,
  ATOM_T3,
  ATOM_T4,
  ATOM_T5,
  ATOM_T6,
  ATOM_T7,
  ATOM_T8,
  ATOM_T9,
  ATOM_T0,
  ATOM_A0,
  ATOM_A1,
  ATOM_A2,
};

#define AA_COMM LT(_LAYER3, KC_COMM)
#define AA_SLSH LT(_LAYER2, KC_SLSH)


// My custom Mod-Tap constants
#define AA_Z MT(MOD_LCTL | MOD_LALT | MOD_LSFT, KC_Z)
#define AA_X MT(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_X)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSPC, KC_PGUP,
    LCTL_T(KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN,
    KC_LSFT,  AA_Z,   AA_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    AA_COMM, KC_DOT,  AA_SLSH,  KC_RSFT, KC_UP, TT(_LAYER1),
    KC_LCTL,  KC_LGUI, KC_LALT, MO(_LAYER1), KC_SPC, KC_RALT, KC_RGUI, MO(_LAYER2), KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_LAYER1] = LAYOUT_all(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, _______, KC_HOME,
    KC_DEL, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______, KC_END,
    _______, ATOM_M7, _______, ATOM_M1, ATOM_M2, _______, ATOM_M6, ATOM_M3, _______, KC_HOME, KC_END, _______, _______, TG(_LAYER1),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_LAYER2] = LAYOUT_all(
    _______, _______, ATOM_S1, ATOM_S2, _______, _______, _______, _______, _______, _______, ATOM_M8, _______, _______, _______, KC_VOLU,
    KC_F13, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, _______, _______, _______, _______, _______, _______, KC_VOLD,
    KC_SLEP, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, KC_PSCR, KC_MUTE,
    RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_LAYER3] = LAYOUT_all(
    _______, ATOM_T1, ATOM_T2, ATOM_T3, ATOM_T4, ATOM_T5, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, ATOM_T6, ATOM_T7, ATOM_T8, ATOM_T9, ATOM_T0, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, ATOM_A0, ATOM_A1, ATOM_A2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_RED}
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0_layer,
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _LAYER1));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LAYER2));
    rgblight_set_layer_state(3, layer_state_cmp(state, _LAYER3));
    return state;
}


// helper/macro functions

void tmux_previous_session(void) {
  SEND_STRING(SS_LCTL("a"));
  SEND_STRING(SS_LSFT("9"));
}

void tmux_next_session(void) {
  SEND_STRING(SS_LCTL("a"));
  SEND_STRING(SS_LSFT("0"));
}


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
    case TMUX_M1:
      if (record->event.pressed) {
        tmux_previous_session();
      }
      return false;
      break;
    case TMUX_M2:
      if (record->event.pressed) {
        tmux_next_session();
      }
      return false;
      break;
    case TMUX_M3:
      // tmux: rename session
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a"));
        SEND_STRING(SS_LSFT("4"));
      }
      return false;
      break;
    case TMUX_M4:
      // tmux: start a new session
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a"));
        SEND_STRING(SS_LSFT(";"));
        SEND_STRING("new");
        register_code(KC_ENT);
      } else {
        unregister_code(KC_ENT);
      }
      return false;
      break;
    case ATOM_N0:
      if (record->event.pressed) {
        SEND_STRING("3j");
      }
      return false;
      break;
    case ATOM_N1:
      if (record->event.pressed) {
        SEND_STRING("3k");
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
    case ATOM_S3:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_LALT);
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        register_code(KC_1);
      } else {
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
        unregister_code(KC_1);
      }
      return false;
      break;
    case ATOM_S4:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_LALT);
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        register_code(KC_2);
      } else {
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
        unregister_code(KC_2);
      }
      return false;
      break;
    case ATOM_T1:
      SEND_STRING(SS_RGUI("1"));
      return false;
      break;
    case ATOM_T2:
      SEND_STRING(SS_RGUI("2"));
      return false;
      break;
    case ATOM_T3:
      SEND_STRING(SS_RGUI("3"));
      return false;
      break;
    case ATOM_T4:
      SEND_STRING(SS_RGUI("4"));
      return false;
      break;
    case ATOM_T5:
      SEND_STRING(SS_RGUI("5"));
      return false;
      break;
    case ATOM_T6:
      SEND_STRING(SS_RGUI("6"));
      return false;
      break;
    case ATOM_T7:
      SEND_STRING(SS_RGUI("7"));
      return false;
      break;
    case ATOM_T8:
      SEND_STRING(SS_RGUI("8"));
      return false;
      break;
    case ATOM_T9:
      SEND_STRING(SS_RGUI("9"));
      return false;
      break;
    case ATOM_T0:
      SEND_STRING(SS_RGUI("0"));
      return false;
      break;
    case ATOM_A0:
      if (record->event.pressed) {
        SEND_STRING(SS_RGUI("-"));
      }
      return false;
      break;
    case ATOM_A1:
      if (record->event.pressed) {
        SEND_STRING(SS_RGUI(SS_LSFT("=")));
      }
      return false;
      break;
    case ATOM_A2:
      if (record->event.pressed) {
        SEND_STRING(SS_RGUI("0"));
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
