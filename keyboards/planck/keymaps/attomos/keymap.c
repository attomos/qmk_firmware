/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _QWERTY_CSGO,
  _NUMPAD,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  QWERTY_CSGO,
  BACKLIT,
  ATOM_M1,
  ATOM_M2,
  ATOM_M3,
  ATOM_M4,
  ATOM_M5,
  ATOM_M6,
  ATOM_M7,
  ATOM_M8
};

// https://docs.qmk.fm/#/feature_tap_dance
// Tap Dance declarations
/* enum { */
/*     TD_TAB_ESC, */
/* }; */

/* void tab_esc_dance(qk_tap_dance_state_t *state, void *user_data) { */
/*   if (state->count <= 2) { */
/*     tap_code(KC_TAB); */
/*   } else if (state->count == 3) { */
/*     tap_code(KC_ESC); */
/*   } else { */
/*     reset_tap_dance(state); */
/*   } */
/* } */

// Tap Dance definitions
/* qk_tap_dance_action_t tap_dance_actions[] = { */
/*   // Tap once for Tab, thrice for Esc */
/*   [TD_TAB_ESC] = ACTION_TAP_DANCE_FN(tab_esc_dance), */
/* }; */

#define LOWER MO(_LOWER)
#define RAISE LT(_RAISE, KC_ENT)
#define NUMPAD TG(_NUMPAD)

// My custom Mod-Tap constants
#define AA_Z MT(MOD_LCTL | MOD_LALT | MOD_LSFT, KC_Z)
#define AA_X MT(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_X)

/* // https://precondition.github.io/home-row-mods */
/* // Left-hand home row mods */
/* #define AA_A LCTL_T(KC_A) */
/* #define AA_S LGUI_T(KC_S) */
/* #define AA_D LALT_T(KC_D) */
/* #define AA_F LSFT_T(KC_F) */

/* // Right-hand home row mods */
/* #define AA_J LSFT_T(KC_J) */
#define AA_K RGUI_T(KC_K)
/* #define AA_L LGUI_T(KC_L) */
#define AA_SCLN LGUI_T(KC_SCLN)

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
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    AA_K,    KC_L,    AA_SCLN, KC_QUOT,
    KC_LSFT,        AA_Z,    AA_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX ,
    KC_LCTL,        KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
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
[_QWERTY_CSGO] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX ,
    LCTL_T(KC_ESC), KC_LCTL, KC_LGUI, KC_LALT, RAISE,   KC_SPC,  KC_SPC,  LOWER,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
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
[_NUMPAD] = LAYOUT_planck_grid(
    KC_TAB,        XXXXXXX, XXXXXXX, KC_E,    XXXXXXX, XXXXXXX, XXXXXXX,  KC_7,  KC_8,    KC_9,    KC_MINS, KC_BSPC,
    CTL_T(KC_ESC), KC_A,    XXXXXXX, XXXXXXX, KC_F, XXXXXXX, KC_EQL,  KC_4,  KC_5,    KC_6,    KC_PLUS, KC_ASTR,
    KC_LSFT,       KC_Z   , KC_X,    KC_C,    XXXXXXX, XXXXXXX, KC_DOT,    KC_1,  KC_2,    KC_3,    KC_SLSH, XXXXXXX ,
    NUMPAD,        KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  KC_0, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  | F13  |      |  M1  |  M2  |  M4  |  M5  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  M7  |  M8  |      |      |      |  M6  |  M3  | Prev | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Nump  |      |      |      |      |             |      | Next | Bri- | Bri+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F13, _______, ATOM_M1, ATOM_M2, ATOM_M4, ATOM_M5, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, ATOM_M7, ATOM_M8, _______, _______, _______, ATOM_M6, ATOM_M3, KC_MPRV, KC_HOME, KC_END,  _______,
    NUMPAD,  _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_BRID, KC_BRIU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |QwerCS|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______,  QWERTY_CSGO,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
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
    case QWERTY_CSGO:
      if (record->event.pressed) {
        print("mode just switched to qwerty CSGO and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY_CSGO);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
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
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

// leave my CTL_T(KC_ESC) alone {{{
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AA_Z:
        case AA_X:
        case AA_SCLN:
            return true;
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AA_Z:
        case AA_X:
        case AA_SCLN:
            return true;
        default:
            return false;
    }
}
// }}}
