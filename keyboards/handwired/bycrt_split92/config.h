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
#define MATRIX_ROW_PINS { D3, D2, D1, D4, C6, D7 }
#define MATRIX_COL_PINS { E6, B4, B5, F4, F5, F6, F7, B1 }
#define MATRIX_ROW_PINS_RIGHT { D3, D2, D1, D4, C6, D7 }
#define MATRIX_COL_PINS_RIGHT { E6, B4, B5, F4, F5, F6, F7, B1, B3 }

#define LED_CAPS_LOCK_PIN B6

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define NO_ACTION_ONESHOT

#define LAYER_STATE_8BIT

#define TAPPING_TOGGLE 2

// Split keyboard specific info
// #define SPLIT_HAND_PIN F7
#define MASTER_LEFT
#define SOFT_SERIAL_PIN D0
#define NO_MUSIC_MODE
