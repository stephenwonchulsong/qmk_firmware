/* Copyright 2022 Aidan Gauland
 * Copyright 2021 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2019 Hiroyuki Okada
 * Copyright 2025 Marco Trevisan <mail@3v1n0.net>
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

 #define INITIALIZATION_TIMEOUT 1000

 #define DELTA_X_THRESHOLD 60
 #define DELTA_Y_THRESHOLD 15

 /* Set this to one of the led_t values that you want to monitor.
  * It can be either num_lock, caps_lock or scroll_lock at the moment.
  */
 #define MONITORED_LED num_lock

 // State
 static bool   initialized        = false;
 static bool   scroll_enabled     = false;
 static bool   initial_led_state  = false;
 static int8_t delta_x            = 0;
 static int8_t delta_y            = 0;

 // Dummy
 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {{{KC_NO}}};

 report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
     if (scroll_enabled) {
         delta_x += mouse_report.x;
         delta_y += mouse_report.y;

         if (delta_x > DELTA_X_THRESHOLD) {
             mouse_report.h = 1;
             delta_x        = 0;
         } else if (delta_x < -DELTA_X_THRESHOLD) {
             mouse_report.h = -1;
             delta_x        = 0;
         }

         if (delta_y > DELTA_Y_THRESHOLD) {
             mouse_report.v = -1;
             delta_y        = 0;
         } else if (delta_y < -DELTA_Y_THRESHOLD) {
             mouse_report.v = 1;
             delta_y        = 0;
         }
         mouse_report.x = 0;
         mouse_report.y = 0;
     }
     return mouse_report;
 }

 /* We need to wait for the host to have fully communicated the LED state */
 uint32_t initialization_timeout(uint32_t trigger_time, void *cb_arg) {
     initial_led_state = host_keyboard_led_state().MONITORED_LED;
     initialized = true;
     return 0; // Don't repeat
 }

 void keyboard_post_init_user(void) {
     defer_exec(INITIALIZATION_TIMEOUT, initialization_timeout, NULL);
 }

 bool led_update_user(led_t led_state) {
     if (!initialized)
         return true;

     scroll_enabled = host_keyboard_led_state().MONITORED_LED != initial_led_state;
     return true;
 }

 void suspend_power_down_user(void) {
     // Switch off sensor + LED making trackball unable to wake host
     initialized = false;
     adns5050_power_down();
 }

 void suspend_wakeup_init_user(void) {
     adns5050_init();
     defer_exec(INITIALIZATION_TIMEOUT, initialization_timeout, NULL);
 }
