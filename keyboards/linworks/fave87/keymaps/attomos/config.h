// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-term
#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY

// I will use `zl` as an example to explain the reasoning behind the below settings

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#ignore-mod-tap-interrupt
// normal: AA_Z mods + l
// with this setting: a "quick tap" will produce zl
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#retro-tapping
// normal: hold and release AA_Z longer than TAPPING_TERM will trigger AA_Z mods
// with this setting: "holding and releasing AA_Z" will produce z
#define RETRO_TAPPING_PER_KEY

// https://beta.docs.qmk.fm/using-qmk/software-features/feature_layers#switching-and-toggling-layers-id-switching-and-toggling-layers
#define TAPPING_TOGGLE 2
