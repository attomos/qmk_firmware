#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

/*
 * Tap dance!
 */
// #define TAPPING_TERM 175

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-term
#define TAPPING_TERM 150

// I will use `zl` as an example to explain the reasoning behind the below settings

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#ignore-mod-tap-interrupt
// normal: AA_Z mods + l
// with this setting: a "quick tap" will produce zl
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#retro-tapping
// normal: AA_Z mods + l
// with this setting: "holding and releasing AA_Z" will produce z
#define RETRO_TAPPING_PER_KEY

// without _PER_KEY will result in undesired behavior for my CTL_T(KC_ESC) key
