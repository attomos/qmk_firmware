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
  _TWO,
  _NAV,
  _THREE
};

enum cajal_keycodes {
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
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
  CTL_ESC
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the ctl_esc tap dance. Put it here so it can be used in any keymap
void ctl_esc_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_esc_reset(qk_tap_dance_state_t *state, void *user_data);

#define AA_COMM LT(_THREE, KC_COMM)
#define AA_SLSH LT(_NAV, KC_SLSH)

// My custom Mod-Tap constants
#define AA_Z MT(MOD_LCTL | MOD_LALT | MOD_LSFT, KC_Z)
#define AA_X MT(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_X)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_stagger(
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, KC_BSPC, RGB_TOG,
      LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
      KC_LSFT, AA_Z, AA_X, KC_C, KC_V, KC_B, KC_N, KC_M, AA_COMM, KC_DOT, AA_SLSH, KC_UP,
      KC_LCTL, KC_LGUI, KC_LALT, MO(_ONE), KC_SPC, MO(_TWO), KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_ONE] = LAYOUT_stagger(
      KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MUTE, KC_TRNS, RGB_MOD,
      KC_DEL, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_QUOT, KC_TRNS,
      KC_TRNS, ATOM_M7, KC_TRNS, ATOM_M1, ATOM_M2, KC_TRNS, ATOM_M6, ATOM_M3, KC_TRNS, KC_PSCR, KC_TRNS, KC_PGUP,
      RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END
  ),
  [_TWO] = LAYOUT_stagger(
      KC_TILD, ATOM_S3, ATOM_S4, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, ATOM_N0, ATOM_N1, KC_TRNS, KC_TRNS, ATOM_M8,
      KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, RGB_SAD, RGB_SAI, KC_TRNS, RGB_VAI,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_HUD, RGB_VAD, RGB_HUI
  ),
  [_NAV] = LAYOUT_stagger(
      KC_TRNS, KC_TRNS, ATOM_S1, ATOM_S2, TMUX_M3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_F13,   KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,   KC_F7,  KC_F8,    KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_THREE] = LAYOUT_stagger(
      KC_TRNS, ATOM_T1, ATOM_T2, ATOM_T3, ATOM_T4, ATOM_T5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, ATOM_T6, ATOM_T7, ATOM_T8, ATOM_T9, ATOM_T0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 1:
        writePinHigh(B7);
        writePinLow(B6);
        break;
    case 2:
        writePinLow(B7);
        writePinHigh(B6);
        break;
    case 3:
        writePinHigh(B7);
        writePinHigh(B6);
        break;
    default:
        writePinLow(B7);
        writePinLow(B6);
        break;
    }
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

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (IS_LAYER_ON(_QWERTY)) {
      if (clockwise) {
        tap_code(KC_VOLD);
      } else {
        tap_code(KC_VOLU);
      }
    } else if (IS_LAYER_ON(_ONE)) {
      if (clockwise) {
        tap_code(KC_BRID);
      } else {
        tap_code(KC_BRIU);
      }
    } else if (IS_LAYER_ON(_NAV)) {
      if (clockwise) {
        tmux_previous_session();
      } else {
        tmux_next_session();
      }
    }
  }
  return true;
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

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }
    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is \'KC_W\', and you want to type "www." quickly - then you will need to add
    // an exception here to return a \'TD_TRIPLE_SINGLE_TAP\', and define that enum just like \'TD_DOUBLE_SINGLE_TAP\'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'ctl_esc' tap dance.
static td_tap_t ctl_esc_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void ctl_esc_finished(qk_tap_dance_state_t *state, void *user_data) {
    ctl_esc_tap_state.state = cur_dance(state);
    switch (ctl_esc_tap_state.state) {
        case TD_UNKNOWN: break;
        case TD_NONE: break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_SINGLE_TAP: register_code(KC_LCTRL); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTRL); break;
        case TD_DOUBLE_TAP: register_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        case TD_DOUBLE_SINGLE_TAP: register_code(KC_ESC); break;
    }
}

void ctl_esc_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ctl_esc_tap_state.state) {
        case TD_UNKNOWN: break;
        case TD_NONE: break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_SINGLE_TAP: unregister_code(KC_LCTRL); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTRL); break;
        case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LALT);
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_ESC);
    }
    ctl_esc_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [CTL_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctl_esc_finished, ctl_esc_reset)
};
