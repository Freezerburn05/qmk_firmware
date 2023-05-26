#include QMK_KEYBOARD_H
//#include "print.h"

/*
Copy in Case of Emergency:
qmk flash
*/

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    FB_TOG,                //Second toggle for the LEDs
};

/*
qk_tap_dance_action_t tap_dance_actions[] = {
    [0] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_B),
};
*/

enum layer_names {
    _KL = 0,    // Keyboard Layout - Default layer
    _FL,        // Function layer
    _PL,        // Coding (Programming) Layer
    _CL,        // Caps Lock Layer
    //_SH,        // Swap Hands Layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_KL] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, FB_TOG,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,
        MO(_CL), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(_FL), KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, _______, _______,
        _______, TO(_PL), _______, _______, _______, _______, _______, _______, _______, _______, TO(_KL), _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU,
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, _______, DBG_TOG, DBG_KBD, _______, _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD,
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, DBG_MTRX,DBG_MOU, _______, _______, _______,
        _______, RGB_TOG, FB_TOG,  _______, _______, MD_BOOT, _______, _______, _______, _______, _______, _______,                              _______,
        _______, _______, _______,                   _______,                            _______, _______, KC_F24,  _______,            _______, _______, _______
    ),
    [_PL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_LSPO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSPC,                              _______,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______
    ),
    [_CL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______,
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______,   _______, _______, _______,
        KC_CAPS, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______, KC_L,    KC_K,    KC_J,    KC_H,    KC_G,    _______, _______, _______, _______, _______, _______, _______,
        _______, KC_M,    KC_N,    KC_B,    KC_V,    _______, _______, _______, _______, _______, _______, _______,                              _______,
        _______, _______, KC_BSPC,                   _______,                            _______, _______, _______, _______,            _______, _______, _______
    ),
    /*
    [_SH] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______, KC_L,    KC_K,    KC_J,    KC_H,    KC_G,    _______, _______, _______, _______, _______, _______, _______,
        _______, KC_M,    KC_N,    KC_B,    KC_V,    _______, _______, _______, _______, _______, _______, _______,                              _______,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______
    ),
    */
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______
    ),
    */
};

const key_override_t f1_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_F1, KC_F13);
const key_override_t f2_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_F1, KC_F14);
const key_override_t f3_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_F1, KC_F15);
const key_override_t f4_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_F1, KC_F16);
const key_override_t f5_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_F1, KC_F17);
const key_override_t f6_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_F1, KC_F18);
const key_override_t f7_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_F1, KC_F19);
const key_override_t f8_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_F1, KC_F20);
const key_override_t f9_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_F1, KC_F21);
const key_override_t f10_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_F1, KC_F22);
const key_override_t f11_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_F1, KC_F23);
const key_override_t f12_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_F1, KC_F24);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &f1_key_override,
    &f2_key_override,
    &f3_key_override,
    &f4_key_override,
    &f5_key_override,
    &f6_key_override,
    &f7_key_override,
    &f8_key_override,
    &f9_key_override,
    &f10_key_override,
    &f11_key_override,
    &f12_key_override,
    NULL // Null terminate the array of overrides!
};

#define MODS_SHIFT  (get_mods() & MOD_MASK_SHIFT)
#define MODS_CTRL   (get_mods() & MOD_MASK_CTRL)
#define MODS_ALT    (get_mods() & MOD_MASK_ALT)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    //uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

    switch (keycode) {
        case FB_TOG:
            if (record->event.pressed) {
                rgb_matrix_toggle();
            }
            return false;
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
