// for flashing:
// bin/fp_build.sh -k ffkb_byomcu/v3 -m 1tegsvenson2 -i -c stemcell -r
// make fingerpunch/ffkb_byomcu/v3:1tegsvenson2 CIRQUE_ENABLE=no FP_TRACKBALL_ENABLE=yes RGB_MATRIX_ENABLE=no FP_EC11=yes CONVERT_TO=stemcell
// qmk flash fingerpunch/ffkb_byomcu/v3:1tegsvenson2 CIRQUE_ENABLE=no FP_TRACKBALL_ENABLE=yes RGB_MATRIX_ENABLE=no FP_EC11=yes CONVERT_TO=stemcell
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _NMIRYOKU,
    _LOWER,
    _RAISE,
    _ADJUST,
    // _MOUSE,
    _COLEMAK,
    _CRKBD2,
    _EXTRA,
    _SHIFT
};

enum custom_keycodes {
    W1R = SAFE_RANGE,
    PHONE_1,
    TEMP1,
    TEMP2,
    TEMP3
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define EXTRA MO(_EXTRA)
#define SHIFTL MO(_SHIFT)
#define ALTDEL MT(MOD_LALT, KC_DEL)
#define GUIDEL MT(MOD_LGUI, KC_DEL)
#define MLANGCTL MT(MOD_LCTL, KC_CAPS)
#define SFTSLSH MT(MOD_LSFT, KC_SLSH)
#define ESCXTRA LT(_EXTRA, KC_ESC)
#define RAISESPC LT(_RAISE, KC_SPC)
#define LOWERDEL LT(_LOWER, KC_DEL)
#define RAISEZERO LT(_RAISE, KC_0)
#define RAISECAPS LT(_RAISE, KC_CAPS)
#define CTLCAPS MT(MOD_LCTL, KC_CAPS)
#define RAISESPC LT(_RAISE, KC_SPC)
#define CAPTURE LGUI(LSFT(KC_5))
#define GUIGRV LGUI(KC_GRV)
#define MACCLOSE LGUI(KC_W)
#define MACBACK LGUI(KC_LEFT)
#define MACFW LGUI(KC_RIGHT)
#define MACPTAB LCTL(KC_TAB)            // Previous tab for MAC
#define MACNTAB LCTL(LSFT(KC_TAB))      // Next tab for MAC
#define M_TAB_RVS LGUI(LSFT(KC_T))      // Reopen tab for MAC
#define MACCOPY LGUI(KC_C)
#define MACCUT LGUI(KC_X)
#define MACPASTE LALT(LSFT(LGUI(KC_V))) // Paste without formatting: Option+Shift+Command+V
#define MACUNDO LGUI(KC_Z)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  ESC |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |  TAB |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |  SFT |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | SFT  |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_QWERTY] = LAYOUT_ffkb(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     ESCXTRA,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,   KC_J,    KC_K,     KC_L,  KC_SCLN, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SFTSLSH,   LSFT_T(KC_Z), LCTL_T(KC_X), LALT_T(KC_C), LGUI_T(KC_V), LGUI_T(KC_B), RGUI_T(KC_N), KC_M, LALT_T(KC_COMM),  LCTL_T(KC_DOT),  RSFT_T(KC_SLSH), SHIFTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                KC_LALT, LOWERDEL, KC_LGUI,  KC_BTN1,   KC_BTN2, KC_SPC, RAISE,  KC_CAPS
                            //`|--------+--------+--------+--------|'`|--------+--------+--------+--------|'
),
// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift

[_COLEMAK] = LAYOUT_ffkb(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     ESCXTRA,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,   KC_N,    KC_E,     KC_I,  KC_O, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SFTSLSH,   LSFT_T(KC_Z), LCTL_T(KC_X), LALT_T(KC_C), KC_V, LGUI_T(KC_B), RGUI_T(KC_N), KC_M, LALT_T(KC_COMM),  LCTL_T(KC_DOT),  RSFT_T(KC_SLSH), SHIFTL,
  ////|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                KC_LALT, KC_LALT, LOWER,  KC_LGUI,      KC_SPC, RAISE,  KC_CAPS, KC_LCTL
                            //`|--------+--------+--------+--------|'`|--------+--------+--------+--------|'
),

/* Colemak-dh
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  ESC |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |  TAB |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |  SFT |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | SFT  |
 * `-----------------------------------------'         ////    `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_NMIRYOKU] = LAYOUT_ffkb(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     ESCXTRA,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,     KC_L,  KC_SCLN, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SFTSLSH,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,  KC_COMM,  KC_DOT,  KC_SLSH, SHIFTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                KC_LALT, LT(_LOWER, KC_DEL), KC_LGUI,  KC_BTN1,   KC_BTN2, KC_SPC, RAISECAPS,  KC_CAPS
                            //`|--------+--------+--------+--------|'`|--------+--------+--------+--------|
),

[_CRKBD2] = LAYOUT_ffkb(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     ESCXTRA,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,     KC_L,  KC_SCLN, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SFTSLSH,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,  KC_COMM,  KC_DOT,  KC_SLSH, SHIFTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                KC_LALT,  LOWER, KC_LGUI, KC_SPC,      KC_SPC, RAISE,  KC_CAPS, KC_LCTL
                            //`|--------+--------+--------+--------|'`|--------+--------+--------+--------|'
),


/* Lower
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |  Caps|      |      |      |      |             |      |      |      |   |  |   "  |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_LOWER] = LAYOUT_ffkb(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                          KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS, KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     GUIGRV,   _______, TEMP3, TEMP2, TEMP1,     W1R,                              KC_4, KC_5, KC_6, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,  KC_VOLD, KC_VOLU, KC_MUTE, CAPTURE, _______,                      KC_1, KC_2, KC_3, KC_LRC, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                _______, _______, _______, _______,     _______, RAISEZERO, KC_CAPS, _______
                            //`|--------+--------+--------+--------|'`|--------+--------+--------+--------|'
),

/* Raise
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Home | Left | Down |  Up  | Right| End  |             |      |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      | PgDn | PgUp |      |      |             |      |      |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

[_RAISE] = LAYOUT_ffkb(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_F1, KC_F2,   KC_F3,    KC_F4,    KC_F5,   KC_F6,                         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, KC_PGUP, KC_HOME,                      _______, KC_LEFT,  KC_UP,  KC_DOWN, KC_RIGHT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, KC_PGDN,  KC_END,                      _______, _______, KC_LCBR, KC_RCBR, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                _______, _______, _______, _______,     _______, _______, _______, _______
                            //`|--------+--------+--------+--------|'`|--------+--------+--------+--------|'
),


/* Adjust (Lower + Raise)

 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      | RGB_T| RGB_R| RGB_F|      |QWERTY|             |   F1 |  F2  |  F3  |  F4  |  F5  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      | SPD_I| HUE_I| SAT_I| VAL_I|COLEMK|             |   F6 |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      | SPD_D| HUE_D| SAT_D| VAL_D|      |             |  F11 |  F12 |      |      | Reset|      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_ADJUST] =  LAYOUT_ffkb(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_EXLM,  KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC,                       KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, TO(_QWERTY),                  TO(_COLEMAK), LALT(KC_LEFT), LALT(KC_UP), LALT(KC_DOWN), LALT(KC_RIGHT), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, TO(_NMIRYOKU),                 TO(_CRKBD2), _______, KC_LABK, KC_RABK, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                QK_BOOTLOADER, _______, _______, _______,     _______, _______, _______, _______
                            //`|--------+--------+--------+--------|'`|--------+--------+--------+--------|'
),

/* Mouse layer

 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |KC_WHU|      |KC_WHD|      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |KC_WHL|MSBTN3|MSBTN2|MSBTN1|KC_WHR|             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
// [_MOUSE] =  LAYOUT_ffkb(
//   _______, _______, KC_WH_U, _______, KC_WH_D, _______,          _______, _______, _______, _______, _______, _______,
//   _______, KC_WH_L, KC_BTN3, KC_BTN2, KC_BTN1, KC_WH_R,          _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
//                     _______, _______, _______, _______,          _______, _______, _______, _______
// ),
[_SHIFT] = LAYOUT_ffkb(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    RSFT(KC_TAB), RSFT(KC_Q), RSFT(KC_W), RSFT(KC_E), RSFT(KC_R), RSFT(KC_T), RSFT(KC_Y), RSFT(KC_U), RSFT(KC_I), RSFT(KC_O), RSFT(KC_P), RSFT(KC_BSPC),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RSFT(KC_LCTL), RSFT(KC_A), RSFT(KC_S), RSFT(KC_D), RSFT(KC_F), RSFT(KC_G), RSFT(KC_H), RSFT(KC_J), RSFT(KC_K), RSFT(KC_L), RSFT(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RSFT(KC_DQT), RSFT(KC_Z), RSFT(KC_X), RSFT(KC_C), RSFT(KC_V), RSFT(KC_B), RSFT(KC_N), RSFT(KC_M), RSFT(KC_LPRN), RSFT(KC_RPRN), RSFT(KC_SLSH), SHIFTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            RSFT(KC_LALT), _______, _______,  RSFT(KC_BTN1),   RSFT(KC_BTN2), RSFT(KC_SPC), _______, _______
                            //`|--------+--------+--------+--------|'`|--------+--------+--------+--------|'
),

  [_EXTRA] = LAYOUT_ffkb(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, MACNTAB, MACCLOSE, MACPTAB, M_TAB_RVS, KC_HOME,                   KC_7,    KC_8,    KC_9,   KC_KP_PLUS, KC_KP_ASTERISK, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, MACBACK, M_TAB_RVS, MACFW, KC_BTN3, KC_WH_U,                      KC_4,    KC_5,    KC_6,   KC_KP_MINUS, KC_KP_SLASH, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, MACUNDO, MACCUT,  MACCOPY, MACPASTE, KC_WH_D,                     KC_1,    KC_2,    KC_3,   _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                _______, _______, _______, RGUI(KC_BTN1),     KC_BTN2, _______, KC_0, _______
                            //`|--------+--------+--------+--------|'`|--------+--------+--------+--------|'
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Encoder
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN),  ENCODER_CCW_CW(KC_WH_L, KC_WH_R)  },
    [_NMIRYOKU] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_WH_L, KC_WH_R)  },
    [_COLEMAK] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_WH_L, KC_WH_R)  },
    [_CRKBD2] =  { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_WH_L, KC_WH_R)  },
    [_LOWER] =  { ENCODER_CCW_CW(KC_WH_L, KC_WH_R),              ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [_RAISE] =  { ENCODER_CCW_CW(KC_WH_L, KC_WH_R),              ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [_ADJUST] = { ENCODER_CCW_CW(KC_WH_L, KC_WH_R),            ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [_SHIFT] =  { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_EXTRA] =  { ENCODER_CCW_CW(KC_WH_L, KC_WH_R),            ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    // [_MOUSE] =  { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
};
#endif

//Encoder, but simpler config
// #ifdef ENCODER_ENABLE
// bool encoder_update_user(uint8_t index, bool clockwise) {
//     // default behavior if undefined
//     if (index == 0) {
//         // Conditional to reverse the direction of encoder number 1
//         // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
//         #ifdef ENCODERS_A_REVERSE
//         if (!clockwise) {
//         #else
//         if (clockwise) {
//         #endif
//             tap_code(KC_VOLU);
//         } else {
//             tap_code(KC_VOLD);
//         }
//     }
//     else if (index == 1) {
//       // Conditional to reverse the direction of encoder number 1
//       // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
//       #ifdef ENCODERS_B_REVERSE
//       if (!clockwise) {
//       #else
//       if (clockwise) {
//       #endif
//         press_super_tab(true);
//       }
//       else{
//         press_super_tab(false);
//       }
//     }

//     return true;
// }
// #endif



// Macro definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case TEMP1: //copy-pasting to another app
        if (record->event.pressed)
        {
            SEND_STRING(SS_LGUI("a")SS_LGUI("c")SS_DELAY(100));
            SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_TAB)SS_UP(X_LGUI)SS_DELAY(100));
            SEND_STRING(SS_LGUI("a"));
            SEND_STRING(SS_TAP(X_DELETE));
            SEND_STRING(SS_LGUI("v"));
            return false;
        }
        break;
    case  TEMP2: // 2-2-1 score on canvas
        if (record->event.pressed)
        {
            SEND_STRING("This was a great conclusion to this series of assignments, ");
            return false;
        }
        break;
    case  TEMP3: // 1-2-1 score on canvas
        if (record->event.pressed)
        {
            SEND_STRING("You did a great job analyzing ");
            return false;
        }
        break;
    // case TEMP2: //Assignment#1, VIC3001
    //     if (record -> event.pressed)
    //     {
    //         SEND_STRING("s"SS_DELAY(200));
    //         SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_UP(X_LSFT));
    //         SEND_STRING("20"SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)"15");
    //         SEND_STRING(SS_TAP(X_TAB)SS_TAP(X_SPC));
    //         return false;
    //     }
    //     break;
    case W1R:
        if (record->event.pressed)
        {
            SEND_STRING("Shawuajydsn");
            return false;
        }
        break;
    case PHONE_1:
        if (record->event.pressed)
        {
            SEND_STRING("3154163646");
            return false;
        }
    }
    return true;
}

// #ifdef ENCODER_ENABLE
// bool encoder_update_user(uint8_t index, bool clockwise) {
//     // default behavior if undefined
//     if (index == 0) {
//         // Conditional to reverse the direction of encoder number 1
//         // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
//         #ifdef ENCODERS_A_REVERSE
//         if (!clockwise) {
//         #else
//         if (clockwise) {
//         #endif
//             tap_code(KC_VOLU);
//         } else {
//             tap_code(KC_VOLD);
//         }
//     }
//     else if (index == 1) {
//       // Conditional to reverse the direction of encoder number 1
//       // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
//       #ifdef ENCODERS_B_REVERSE
//       if (!clockwise) {
//       #else
//       if (clockwise) {
//       #endif
//         press_super_tab(true);
//       }
//       else{
//         press_super_tab(false);
//       }
//     }

//     return true;
// }
// #endif


//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                 _______, _______, _______, _______,     _______, _______, _______, _______
//                             //`|--------+--------+--------+--------|'`|--------+--------+--------+--------|'

//improved hold tap for lower and raise
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
     case RAISECAPS:
     case RAISESPC:
     case LOWERDEL:
     case ESCXTRA:
     case SFTSLSH:
        return true;
     default:
        return false;
    }
}

//permissive hold for miryoku
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_BSPC):
        case LSFT_T(KC_Z):
        case LCTL_T(KC_X):
        case LALT_T(KC_C):
        case LGUI_T(KC_V):
        case LGUI_T(KC_B):
        case RGUI_T(KC_N):
        case LALT_T(KC_COMM):
        case LCTL_T(KC_DOT):
        case RSFT_T(KC_SLSH):
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
