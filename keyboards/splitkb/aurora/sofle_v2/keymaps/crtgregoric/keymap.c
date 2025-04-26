#include QMK_KEYBOARD_H

// Mac/Windows dynamic mode
bool mac_mode = true;  // Start in Mac mode

enum custom_keycodes {
    OS_TGL = SAFE_RANGE, // Platform mod toggle
    // Platform specific modifiers
    LGUI_K,
    RGUI_K,
    LALT_K,
    RALT_K
};

void handle_platform_modifier(bool is_mac, keyrecord_t *record, uint16_t mac_key, uint16_t win_key) {
    uint16_t key = is_mac ? mac_key : win_key;

    if (record->event.pressed) {
        register_code(key);
    } else {
        unregister_code(key);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_TGL:
            if (record->event.pressed) {
                mac_mode = !mac_mode;
            }
            return false;

        case LGUI_K:
            handle_platform_modifier(mac_mode, record, KC_LGUI, KC_LALT);
            return false;

        case RGUI_K:
            handle_platform_modifier(mac_mode, record, KC_RGUI, KC_RALT);
            return false;

        case LALT_K:
            handle_platform_modifier(mac_mode, record, KC_LALT, KC_LGUI);
            return false;

        case RALT_K:
            handle_platform_modifier(mac_mode, record, KC_RALT, KC_RGUI);
            return false;
    }
    return true;
}

// Left-hand home row mods
#define SFT_A LSFT_T(KC_A)
#define CTL_S LCTL_T(KC_S)
#define ALT_D LALT_T(KC_D)
#define GUI_F LGUI_T(KC_F)

// Right-hand home row mods
#define GUI_J RGUI_T(KC_J)
#define ALT_K LALT_T(KC_K)
#define CTL_L RCTL_T(KC_L)
#define SFT_SCLN RSFT_T(KC_SCLN)

// --- Keymaps ---
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base Layer
    [0] = LAYOUT(
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSLS,
        KC_CAPS,    SFT_A,      CTL_S,      ALT_D,      GUI_F,      KC_G,                                   KC_H,       GUI_J,      ALT_K,      CTL_L,      SFT_SCLN,   KC_QUOT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       XXXXXXX,        XXXXXXX,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                KC_LCTL,    LALT_K,     LGUI_K,     KC_SPC,     MO(2),          KC_ENT,     RGUI_K,     MO(1),      RALT_K,     KC_RCTL
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
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    OS_TGL,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    RM_TOGG,    RM_HUEU,    RM_SATU,    RM_VALU,    XXXXXXX,                                XXXXXXX,    KC_VOLD,    KC_MUTE,    KC_VOLU,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    RM_NEXT,    RM_HUED,    RM_SATD,    RM_VALD,    XXXXXXX,   XXXXXXX,         XXXXXXX,    XXXXXXX,    KC_MPRV,    KC_MPLY,    KC_MNXT,    XXXXXXX,    XXXXXXX,
                                _______,    _______,    _______,    _______,   _______,         _______,    _______,    _______,    _______,    _______
    )
};
