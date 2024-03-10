/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

/*
qmk compile -c -kb bastardkb/charybdis/3x5/v2/splinky_2 -km 1tegsvenson -e VIA_ENABLE=yes
qmk compile -c -kb bastardkb/charybdis/3x5/v2/splinky_2 -km 1tegsvenson
qmk compile -c -kb bastardkb/charybdis/3x5/v2/splinky_3 -km 1tegsvenson
qmk flash -c -kb bastardkb/charybdis/3x5/v2/splinky_2 -km 1tegsvenson
qmk flash -c -kb bastardkb/charybdis/3x5/v2/splinky_3 -km 1tegsvenson
*/

#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_ADJST,
    LAYER_EXTRA,
    LAYER_MOUSE
};

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define ADJST MO(LAYER_ADJST)
#define EXTRA MO(LAYER_EXTRA)
#define MOUSE MO(LAYER_MOUSE)

#define LOWER_ESC LT(LAYER_LOWER, KC_ESC)
#define ADJST_ESC LT(LAYER_ADJST, KC_ESC)
#define RAISE_TAB LT(LAYER_RAISE, KC_TAB)
#define ADJST_TAB LT(LAYER_ADJST, KC_TAB)
#define EXTRA_SLSH LT(LAYER_EXTRA, KC_SLSH)
#define MOUSE_FFF LT(LAYER_MOUSE, KC_F)

enum custom_keycodes {
    KC_DTRP = SAFE_RANGE,
    KC_CMLP,
    KC_QTAB,
    LOWER_GESC,
    ADJST_GESC,
    W1R
};


// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LOWER_ESC:
//             return 250;

//         default:
//             return TAPPING_TERM;
//     }
// }



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_QTAB,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_D,  MOUSE_FFF, KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      LSFT_T(KC_Z), LCTL_T(KC_X), LALT_T(KC_C), LGUI_T(KC_V), LGUI_T(KC_B), RGUI_T(KC_N), RGUI_T(KC_M), KC_CMLP, KC_DTRP, RSFT_T(KC_SLSH),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_BSPC, LOWER_ESC, RGUI_T(KC_ENT), KC_SPC, RAISE_TAB
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_QTAB, LSFT(LCTL(KC_TAB)),    KC_E,    LCTL(KC_TAB),    LGUI(LSFT(KC_5)),       KC_7,    KC_8,    KC_9,    KC_PLUS,    KC_EQL,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_VOLU,    LGUI(KC_LEFT),    KC_D,  LGUI(KC_RIGHT), W1R,       KC_4,    KC_5,    KC_6,    KC_MINUS, KC_ENT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      KC_VOLD, LCTL_T(KC_X), LALT_T(KC_C), LGUI_T(KC_V), LGUI_T(KC_B), KC_1, KC_2, KC_3, KC_DOT, RSFT_T(KC_SLSH),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_BSPC, LOWER_ESC, RGUI_T(KC_ENT), KC_0, ADJST_TAB
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),


  [LAYER_RAISE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_D,  KC_F, KC_G,       KC_H,    KC_LEFT,    KC_UP,    KC_DOWN, KC_RIGHT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      LSFT_T(KC_Z), LCTL_T(KC_X), LALT_T(KC_C), LGUI_T(KC_V), KC_LBRC, KC_RBRC, RGUI_T(KC_M), KC_QUOT, LSFT(KC_QUOT), RSFT_T(KC_SLSH),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_BSPC, ADJST_ESC, RGUI_T(KC_ENT), KC_SPC, RAISE_TAB
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_ADJST] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_QTAB, KC_W,    KC_E,    KC_R,    KC_T,       KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_TILD,    KC_BSLS,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_D,  KC_F,      KC_G,       KC_DLR,    KC_PERC,    KC_CIRC,    KC_UNDS, KC_PIPE,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      LSFT_T(KC_Z), LCTL_T(KC_X), LALT_T(KC_C), LGUI_T(KC_V), LGUI_T(KC_B), KC_EXLM, KC_AT, KC_HASH, KC_DOT, RSFT_T(KC_SLSH),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_BSPC, LOWER_ESC, RGUI_T(KC_ENT), KC_RPRN, RAISE_TAB
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_EXTRA] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_QTAB,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_D,  KC_F, KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      LSFT_T(KC_Z), LCTL_T(KC_X), LALT_T(KC_C), LGUI_T(KC_V), LGUI_T(KC_B), RGUI_T(KC_N), RGUI_T(KC_M), KC_COMM, KC_DOT, RSFT_T(KC_SLSH),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_BSPC, LOWER_ESC, RGUI_T(KC_ENT), KC_SPC, RAISE_TAB
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_MOUSE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_QTAB, LGUI(KC_W),    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          LGUI(KC_A),    KC_F3,    KC_D,  MOUSE_FFF, KC_G,       KC_H,    KC_CAPS,    KC_K,    KC_L, KC_SCLN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LSFT, LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LGUI_T(KC_B), RGUI_T(KC_N), RGUI_T(KC_M), KC_COMM, KC_DOT, RSFT_T(KC_SLSH),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_BTN2, LGUI(KC_BTN1), KC_BTN1, KC_SPC, RAISE_TAB
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

};
// clang-format on

//changing behavior for RSFT and RGUI
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case W1R:
      if (record->event.pressed)
        {
            SEND_STRING("Shawuajydsn");
            return false;
        }
    case KC_DTRP:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_RSFT)){
          register_code(KC_0);
        } else {
          register_code(KC_DOT);
        }
      } else {
        unregister_code(KC_0);
        unregister_code(KC_DOT);
      }
      return false;
    case KC_CMLP:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_RSFT)){
          register_code(KC_9);
        } else {
          register_code(KC_COMM);
        }
      } else {
        unregister_code(KC_9);
        unregister_code(KC_COMM);
      }
      return false;
    case KC_QTAB:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_RGUI)){
          register_code(KC_TAB);
        } else {
          register_code(KC_Q);
        }
      } else {
        unregister_code(KC_TAB);
        unregister_code(KC_Q);
      }
      return false;
    default:
      return true;
  }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_SLSH):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

// //Tap Dance for tap and hold
// typedef struct {
//     uint16_t tap;
//     uint16_t hold;
//     uint16_t held;
// } tap_dance_tap_hold_t;

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     tap_dance_action_t *action;
//     switch (keycode) {
//         case TD(LOWER_GESC):  // list all tap dance keycodes with tap-hold configurations
//             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
//             if (!record->event.pressed && action->state.count && !action->state.finished) {
//                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
//                 tap_code16(tap_hold->tap);
//             }
//         case TD(ADJST_GESC):  // list all tap dance keycodes with tap-hold configurations
//             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
//             if (!record->event.pressed && action->state.count && !action->state.finished) {
//                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
//                 tap_code16(tap_hold->tap);
//             }
//     }
//     return true;
// }

// void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
//     tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

//     if (state->pressed) {
//         if (state->count == 1
// #ifndef PERMISSIVE_HOLD
//             && !state->interrupted
// #endif
//         ) {
//             register_code16(tap_hold->hold);
//             tap_hold->held = tap_hold->hold;
//         } else {
//             register_code16(tap_hold->tap);
//             tap_hold->held = tap_hold->tap;
//         }
//     }
// }

// void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
//     tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

//     if (tap_hold->held) {
//         unregister_code16(tap_hold->held);
//         tap_hold->held = 0;
//     }
// }

// #define ACTION_TAP_DANCE_TAP_HOLD(tap, hold)
//     { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

// tap_dance_action_t tap_dance_actions[] = {
//     [LOWER_GESC] = ACTION_TAP_DANCE_TAP_HOLD(QK_GESC, LOWER),
//     [ADJST_GESC] = ACTION_TAP_DANCE_TAP_HOLD(QK_GESC, ADJST),
// };

// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case RAISE_TAB:
//             // Immediately select the hold action when another key is tapped.
//             return true;
//         default:
//             // Do not select the hold action when another key is tapped.
//             return false;
//     }
// }

// // Macro definitions
// bool process_record_user(uint16_t keycode, keyrecord_t *record)
// {
//     switch (keycode)
//     {
//     // case TEMP1: //copy-pasting to another app
//     //     if (record->event.pressed)
//     //     {
//     //         SEND_STRING(SS_LGUI("a")SS_LGUI("c")SS_DELAY(100));
//     //         SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_TAB)SS_UP(X_LGUI)SS_DELAY(100));
//     //         SEND_STRING(SS_LGUI("a"));
//     //         SEND_STRING(SS_TAP(X_DELETE));
//     //         SEND_STRING(SS_LGUI("v"));
//     //         return false;
//     //     }
//     //     break;
//     // case  TEMP2: // 2-2-1 score on canvas
//     //     if (record->event.pressed)
//     //     {
//     //         SEND_STRING("This was a great conclusion to this series of assignments, ");
//     //         return false;
//     //     }
//     //     break;
//     // case  TEMP3: // 1-2-1 score on canvas
//     //     if (record->event.pressed)
//     //     {
//     //         SEND_STRING("You did a great job analyzing ");
//     //         return false;
//     //     }
//     //     break;
//     // case DRAG_SCROLL: //scrolling with trackball
//     //         is_drag_scroll ^= 1;
//     //         if (record->event.pressed)
//     //             fp_set_cpi(100);
//     //         else
//     //             fp_set_cpi(spi_read[keymap_config.dpi_config]);
//     //         break;
//     // case TEMP2: //Assignment#1, VIC3001
//     //     if (record -> event.pressed)
//     //     {
//     //         SEND_STRING("s"SS_DELAY(200));
//     //         SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_UP(X_LSFT));
//     //         SEND_STRING("20"SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)"15");
//     //         SEND_STRING(SS_TAP(X_TAB)SS_TAP(X_SPC));
//     //         return false;
//     //     }
//     //     break;
//     case W1R:
//         if (record->event.pressed)
//         {
//             SEND_STRING("Shawuajydsn");
//             return false;
//         }
//     //     break;
//     // case PHONE_1:
//     //     if (record->event.pressed)
//     //     {
//     //         SEND_STRING("3154163646");
//     //         return false;
//     //     }
//     }
//     return true;
// }


