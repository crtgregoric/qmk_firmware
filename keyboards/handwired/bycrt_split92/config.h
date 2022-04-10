// Copyright 2022 Crt Gregoric (@crtgregoric)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    Crt Gregoric
#define PRODUCT         bycrt_split92

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 9

#define DIODE_DIRECTION COL2ROW

// wiring of each half
#define MATRIX_ROW_PINS { B1, B2, C7, B4, D7, B0 }
#define MATRIX_COL_PINS { F4, F1, F0, B7, B3, D2, D3, D5, D4 }
#define MATRIX_ROW_PINS_RIGHT { B3, B2, B6, B4, D7, B0 }
#define MATRIX_COL_PINS_RIGHT { F1, F0, F4, F5, F6, D5, C7, D3, B7 }

#define CAPS_LOCK_LED_PIN B6

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

// Split keyboard specific info
#define SPLIT_HAND_PIN F7
#define MASTER_LEFT
#define SOFT_SERIAL_PIN D0

/*
This is COL2ROW:

 │o               │o
┌┴┐         o    ┌┴┐         o
│ │    O         │ │    O
├─┤              ├─┤      
└┬┘              └┬┘
 └────────────────┴─────────────

*/