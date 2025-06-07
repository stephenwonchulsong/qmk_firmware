// #define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// #define AUTO_MOUSE_DEFAULT_LAYER 5

// Define only one of the two below, but not both.
// Read here for details: https://github.com/sadekbaroudi/qmk_firmware/tree/master/keyboards/fingerpunch#layer-lighting

//#define FP_LAYER_LIGHTING_AUTO_MOUSE_ENABLE

// #define TAPPING_TERM 350
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
// #define IGNORE_MOD_TAP_INTERRUPT
/*
Copyright 2021 Sadek Baroudi <sadekbaroudi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// #pragma once
// #include "config_common.h"


/* USB Device descriptor parameter */
// #define DEVICE_VER      0x0003

/* key matrix size */
/* Rows are doubled up */
// #define MATRIX_ROWS 6
// #define MATRIX_COLS 8

// SHIFT REGISTER
// Only needed for matrix_74hc595_spi.c
// #define SHIFTREG_MATRIX_COL_CS B6
// #define SHIFTREG_DIVISOR 8 // needs to be the same as the PMW33XX_CS_DIVISOR below
// #define MATRIX_ROW_PINS_SR { D2, F4, F5, F6, F7, D4 }

// // SPI config for shift register (and trackball if enabled)
// #define SPI_DRIVER SPID1
// #define SPI_SCK_PIN B1
// #define SPI_SCK_PAL_MODE 5
// #define SPI_MOSI_PIN B2
// #define SPI_MOSI_PAL_MODE 5
// #define SPI_MISO_PIN B3
// #define SPI_MISO_PAL_MODE 5

// /* COL2ROW, ROW2COL*/
// #define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A {C6, E6}
#define ENCODERS_PAD_B {D7, B4}

#define TAPPING_TERM_PER_KEY

// #ifdef FP_EVQ
// #define ENCODERS_A_REVERSE
// #define ENCODERS_B_REVERSE
// #endif

#ifdef FP_EC11
#define ENCODERS_C_REVERSE
#endif
