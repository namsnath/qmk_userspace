#pragma once
#define TAPPING_TERM 200
#define RGBLIGHT_SLEEP true

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PREONIC_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

#define MUSIC_MASK (keycode != KC_NO)

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


// Space Cadet Definitions

// // Left Shift on hold, ( on tap
#define LSPO_KEYS KC_LSFT, KC_LSFT, KC_9
// // Right Shift on hold, ) on tap
#define RSPC_KEYS KC_RSFT, KC_RSFT, KC_0
// // Left Ctrl on hold, { on tap
#define LCPO_KEYS KC_LCTL, KC_LSFT, KC_LBRC
// // Right Ctrl on hold, } on tap
#define RCPC_KEYS KC_RCTL, KC_LSFT, KC_RBRC
// // Left Alt on hold, [ on tap
#define LAPO_KEYS KC_LALT, KC_TRNS, KC_LBRC
// // Right Alt on hold, ] on tap
#define RAPC_KEYS KC_RALT, KC_TRNS, KC_RBRC

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0
// Enable Permissive Holds
// Allows for mod-tap modifiers to be used in tandem, where one is held and the other is tapped
#define PERMISSIVE_HOLD