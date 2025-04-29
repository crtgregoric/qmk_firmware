#include QMK_KEYBOARD_H

// Left-hand home row mods
#define SFT_A       LSFT_T(KC_A)
#define CTL_S       LCTL_T(KC_S)
#define ALT_D       LALT_T(KC_D)
#define GUI_F       LGUI_T(KC_F)

// Right-hand home row mods
#define GUI_J       RGUI_T(KC_J)
#define ALT_K       LALT_T(KC_K)
#define CTL_L       RCTL_T(KC_L)
#define SFT_SCLN    RSFT_T(KC_SCLN)

// Mac/Windows dynamic mode
bool mac_mode = true;  // Start in Mac mode

void update_mac_mode(bool new_mac_mode) {
    if (new_mac_mode == mac_mode) return;
    mac_mode = new_mac_mode;
    tap_code16(new_mac_mode ? QK_MAGIC_UNSWAP_CTL_GUI : QK_MAGIC_SWAP_CTL_GUI);
}

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }

    switch (detected_os) {
        case OS_UNSURE:
        case OS_MACOS:
        case OS_IOS:
            update_mac_mode(true);
            break;
        case OS_WINDOWS:
        case OS_LINUX:
            update_mac_mode(false);
            break;
    }
    
    return true;
}

// --- Keymaps ---
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base Layer
    [0] = LAYOUT(
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSLS,
        KC_CAPS,    SFT_A,      CTL_S,      ALT_D,      GUI_F,      KC_G,                                   KC_H,       GUI_J,      ALT_K,      CTL_L,      SFT_SCLN,   KC_QUOT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       XXXXXXX,        XXXXXXX,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                KC_LCTL,    KC_LALT,    KC_LGUI,    KC_SPC,     MO(2),          KC_ENT,     KC_RGUI,    MO(1),      KC_RALT,    KC_RCTL
    ),
    // Raise Layer
    [1] = LAYOUT(
        KC_GRV,     _______,    _______,    _______,    _______,    _______,                                _______,    _______,    _______,    KC_MINS,    KC_EQL,     KC_DEL,
        _______,    _______,    _______,    _______,    _______,    _______,                                _______,    _______,    KC_UP,      KC_LBRC,    KC_RBRC,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,                                _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    _______,
        _______,    KC_BRMD,    KC_BRMU,    KC_NO,      RM_VALD,    RM_VALU,    _______,        _______,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,
                                _______,    _______,    _______,    _______,    MO(3),          _______,    _______,    _______,    _______,    _______
    ),
    // Lower Layer
    [2] = LAYOUT(
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                                  KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
        _______,    _______,    _______,    _______,    _______,    _______,                                _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,                                _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                _______,    _______,    _______,    _______,    _______,        _______,    _______,    MO(3),      _______,    _______
    ),
    // Adjust Layer
    [3] = LAYOUT(
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    RM_TOGG,    RM_HUEU,    RM_SATU,    RM_VALU,    XXXXXXX,                                XXXXXXX,    KC_VOLD,    KC_MUTE,    KC_VOLU,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    RM_NEXT,    RM_HUED,    RM_SATD,    RM_VALD,    XXXXXXX,   XXXXXXX,         XXXXXXX,    XXXXXXX,    KC_MPRV,    KC_MPLY,    KC_MNXT,    XXXXXXX,    XXXXXXX,
                                _______,    _______,    _______,    _______,   _______,         _______,    _______,    _______,    _______,    _______
    )
};
