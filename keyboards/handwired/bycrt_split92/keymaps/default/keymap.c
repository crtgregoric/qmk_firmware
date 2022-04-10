/* Copyright 2021 QMK
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

enum custom_keycodes {
    LCK_DSP = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LCK_DSP:
        if (record->event.pressed) {
            SEND_STRING("control + command + q");
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 
     * Default layer
     * ┌───┬─────┬───┬───┬───┬───┬───┬───┐      ┌───┬───┬───┬───┬───┬───┬─────┬───┐
     * │   │ Esc │BDn│BUp│   │   │BLD│BLI│      │PTr│P/P│NTr│Mut│VDn│Vup│ Del │   │
     * ├───┼───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘    ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─────┼───┤
     * │   │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │      │ 7 │ 8 │ 9 │ 0 │ - │ = │Backspc│   │
     * ├───┼───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘    ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │   │ Tab │ Q │ W │ E │ R │ T │      │ Y │ U │ I │ O │ P │ [ │ ] │  \  │   │
     * ├───┼─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐     └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │   │ Caps │ A │ S │ D │ F_│ G │      │ H │_J │ K │ L │ ; │ ' │  Enter │   │
     * ├───┼──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐    └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │   │ Shift  │ Z │ X │ C │ V │ B │      │ N │ M │ , │ . │ / │Shift │ ↑ │   │
     * ├───┼───┬───┬┴──┬┴───┼───┴───┴──┬┘     ┌┴───┴──┬┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │   │Fn │Ctr│Alt│Cmd │   Spc    │      │  TT1  │Cmd│Alt│Ctr│Fn │ ← │ ↓ │ → │
     * └───┴───┴───┴───┴────┴──────────┘      └───────┴───┴───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_92_default(
        KC_NO, KC_ESC, KC_BRMD, KC_BRMU, KC_NO, KC_NO, BL_DEC, BL_INC,        KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL, KC_NO,
        KC_NO, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,                                KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_NO, 
        KC_NO, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                               KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO, 
        KC_NO, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,                                     KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_NO, 
        KC_NO, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                 KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_NO, 
        KC_NO, MO(1), KC_LCTL, KC_LALT, KC_LCMD, KC_SPC,                       TT(1), KC_RCMD, KC_RALT, KC_RCTL, MO(1), KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /*
     * Function/arrow/mouse keys layer
     * ┌───┬─────┬───┬───┬───┬───┬───┬───┐      ┌───┬───┬───┬───┬───┬───┬─────┬───┐
     * │   │ LCK │F1 │F2 │F3 │F4 │F5 │F6 │      │F7 │F8 │F9 │F10│F11│F12│     │   │
     * ├───┼───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘    ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─────┼───┤
     * │   │   │   │   │   │   │   │   │      │   │   │   │   │   │   │  Del  │   │
     * ├───┼───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘    ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │   │     │   │MW←│M↑ │MW→│   │      │   │MW↑│ ↑ │MB1│MB2│   │   │     │   │
     * ├───┼─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐     └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │   │      │   │M← │M↓ │M→_│   │      │   │_← │ ↓ │ → │   │   │Np Enter│   │
     * ├───┼──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐    └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │   │        │   │   │   │   │   │      │   │MW↓│MS1│MS2│MS3│      │PUp│   │
     * ├───┼───┬───┬┴──┬┴───┼───┴───┴──┬┘     ┌┴───┴──┬┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │   │   │   │   │    │          │      │   DF  │   │   │   │   │Hme│PDn│End│
     * └───┴───┴───┴───┴────┴──────────┘      └───────┴───┴───┴───┴───┴───┴───┴───┘
     */
    [1] = LAYOUT_92_default(
        KC_TRNS, LCK_DSP, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_MS_U, KC_WH_R, KC_TRNS,       KC_TRNS, KC_WH_U, KC_UP, KC_MS_BTN1, KC_MS_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_PENT, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_WH_D, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_PGUP, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                DF(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END
    )
};
