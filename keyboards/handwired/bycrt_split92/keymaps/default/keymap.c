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
    J_10LU,
    J_10LD,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LCK_DSP:
        if (record->event.pressed) {
            register_code(KC_LCTL); register_code(KC_LCMD); register_code(KC_Q);
            unregister_code(KC_LCTL); unregister_code(KC_LCMD); unregister_code(KC_Q);
        }
        break;
    case J_10LU:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP));
        }
        break;
    case J_10LD:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN));
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 
     * Default layer
     * ┌───┬─────┬───┬───┬───┬───┬───┬───┐      ┌───┬───┬───┬───┬───┬───┬─────┬───┐
     * │   │ Esc │BDn│BUp│   │   │BLD│BLI│      │PTr│P/P│NTr│Mut│VDn│VUp│ Del │LCK│
     * ├───┼───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘    ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─────┼───┤
     * │   │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │      │ 7 │ 8 │ 9 │ 0 │ - │ = │Backspc│Hme│
     * ├───┼───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘    ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │   │ Tab │ Q │ W │ E │ R │ T │      │ Y │ U │ I │ O │ P │ [ │ ] │  \  │End│
     * ├───┼─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐     └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │   │ Caps │ A │ S │ D │ F_│ G │      │ H │_J │ K │ L │ ; │ ' │  Enter │PUp│
     * ├───┼──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐    └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │   │ Shift  │ Z │ X │ C │ V │ B │      │ N │ M │ , │ . │ / │Shift │ ↑ │PDn│
     * ├───┼───┬───┬┴──┬┴───┼───┴───┴──┬┘     ┌┴───┴──┬┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │   │Fn │Ctr│Alt│Cmd │   Spc    │      │  TT1  │Cmd│Alt│Ctr│Fn │ ← │ ↓ │ → │
     * └───┴───┴───┴───┴────┴──────────┘      └───────┴───┴───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_92(
        KC_TRNS, KC_ESC, KC_BRMD, KC_BRMU, KC_NO, KC_NO, BL_DEC, BL_INC,                     KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL, LCK_DSP,
        KC_TRNS, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,                                             KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_HOME, 
        KC_TRNS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                             KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_END, 
        KC_TRNS, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,                                                  KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP, 
        KC_TRNS, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                              KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN, 
        KC_TRNS, MO(1), KC_LCTL, KC_LALT, KC_LCMD, KC_SPC,                                      TT(1), KC_RCMD, KC_RALT, KC_RCTL, MO(1), KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /*
     * Function/arrow/mouse keys layer
     * ┌───┬─────┬───┬───┬───┬───┬───┬───┐      ┌───┬───┬───┬───┬───┬───┬─────┬───┐
     * │   │ LCK │F1 │F2 │F3 │F4 │F5 │F6 │      │F7 │F8 │F9 │F10│F11│F12│     │   │
     * ├───┼───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘    ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─────┼───┤
     * │   │TG2│   │   │   │   │   │   │      │   │   │   │   │   │   │  Del  │   │
     * ├───┼───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘    ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │   │     │   │MW←│M↑ │MW→│   │      │JUp│MW↓│ ↑ │MB1│MB2│   │   │     │   │
     * ├───┼─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐     └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │   │      │   │M← │M↓ │M→_│   │      │JDn│_← │ ↓ │ → │   │   │Np Enter│   │
     * ├───┼──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐    └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │   │        │   │   │   │   │   │      │   │MW↑│MS1│MS2│MS3│      │PUp│   │
     * ├───┼───┬───┬┴──┬┴───┼───┴───┴──┬┘     ┌┴───┴──┬┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │   │   │   │   │    │          │      │  TO0  │   │   │   │   │Hme│PDn│End│
     * └───┴───┴───┴───┴────┴──────────┘      └───────┴───┴───┴───┴───┴───┴───┴───┘
     */
    [1] = LAYOUT_92(
        KC_TRNS, LCK_DSP, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                   KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS,
        KC_TRNS, TG(2), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_MS_U, KC_WH_R, KC_TRNS,           J_10LU, KC_WH_D, KC_UP, KC_MS_BTN1, KC_MS_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                        J_10LD, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_PENT, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_WH_U, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_PGUP, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                   TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END
    ),
    /*
     * Main arrow keys layer
     * ┌───┬─────┬───┬───┬───┬───┬───┬───┐      ┌───┬───┬───┬───┬───┬───┬─────┬───┐
     * │   │     │   │   │   │   │   │   │      │   │   │   │   │   │   │     │   │
     * ├───┼───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘    ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─────┼───┤
     * │   │   │   │   │   │   │   │   │      │   │   │   │   │   │   │       │   │
     * ├───┼───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘    ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │   │     │   │   │   │   │   │      │   │   │   │   │   │   │   │     │   │
     * ├───┼─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐     └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │   │      │   │   │   │ _ │   │      │   │ _ │   │   │   │   │        │   │
     * ├───┼──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐    └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │   │        │   │   │   │   │   │      │   │   │   │   │   │    ↑ │   │   │
     * ├───┼───┬───┬┴──┬┴───┼───┴───┴──┬┘     ┌┴───┴──┬┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │   │   │   │   │    │          │      │       │   │   │   │ ← │ ↓ │ → │   │
     * └───┴───┴───┴───┴────┴──────────┘      └───────┴───┴───┴───┴───┴───┴───┴───┘
     */
    [2] = LAYOUT_92(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS
    )
};
