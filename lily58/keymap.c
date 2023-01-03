/* Copyright 2022 splitkb.com <support@splitkb.com>
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
#include "keymap_german.h"
#include "tapdances.h"
#include "keycodes.h"


enum layers {
    // Default LAYERS
    _QWERTZ = 0,
    _RACING,
    // Special Layers
    _RAISE = 8,
    _CODE,
    _MEDIA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    /* DEFAULT
     * ,----------------------------------------.                     ,-------------------------------------------------.
     * |GRESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |    PRINT     |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+--------------|
     * |  TAB |   Q  |   W  |   E  |   R  |   T  |                    |   Z  |  U   |   I  |  O   |   P  |      DEL     |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+--------------|
     * | SHIFT|   A  |  S   |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ß  |     SHIFT    |
     * |------+------+------+------+------+------| MEDIA |    |       |------+------+------+------+------+--------------|
     * | LCTRL|   Y  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M   |  ,  |   .  |   -  |       #      |
     * `-----------------------------------------/       /     \      \-------------------------------------------------'
     *                |  GUI  |LALT |SPLT(_CODE)| ENTER /       \BSPC \  | SPLT(_RAISE) |  RALT  |TT(_RACING)|
     *                |       |     ||||||||||||||/    /         \      \ |              |||||||||            |
     *                `------------------------------'            '------''---------------------------------'
     */
    
    [_QWERTZ] = LAYOUT(
        QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5,                          KC_6, KC_7, KC_8, KC_9, KC_0, KC_PSCR,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                           DE_Z, KC_U, KC_I, KC_O, KC_P, KC_DEL,
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,                          KC_H, KC_J, KC_K, KC_L, DE_SS, KC_RSFT,
        KC_LCTL, DE_Y, KC_X, KC_C, KC_V, KC_B, MO(_MEDIA),              ____, KC_N, KC_M, DE_COMM, DE_DOT, DE_MINS, DE_HASH,
            KC_RCMD, KC_LALT, SPLT(_CODE), KC_ENTER,                 KC_BSPC, SPLT(_RAISE), KC_RALT, TT(_RACING)
    ),

    /* RACING  
     * ,----------------------------------------.                     ,---t--------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |  UP  |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | CTRL |      |      |      |      |      |-------.    ,-------|      | LEFT | DOWN | RIGHT|      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * | C S  |      |      |      |      |      |-------|    |-------|      |       |     |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      | SPACE | /       /       \      \  |      |      |      |
     *                   |      |      ||||||||/       /         \      \ |      ||||||||      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_RACING] = LAYOUT(
        ____, ____, ____, ____, ____, ____,                         ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____,                         ____, ____, KC_UP, ____, ____, ____,   
        KC_LCTL, ____, ____, ____, ____, ____,                      ____, KC_LEFT, KC_DOWN, KC_RIGHT, ____, ____,
        C_S_T(____), ____, ____, ____, ____, ____, ____,            ____, ____, ____, ____, ____, ____, ____,
            ____, ____, KC_SPACE, ____,                             ____, ____, ____, ____
    ),
    /* RAISE
     * ,----------------------------------------.                     ,-----------------------------------------.
     * |  ^   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |   Ä  |   Ö  |   Ü  |      |      |                    |  NUM | NUM7 | NUM8 | NUM9 |  /   |  F12 |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | CAPS |      |      |      |      |      |-------.    ,-------|      | NUM4 | NUM5 | NUM6 |  *   |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------| NUM0 | NUM1 | NUM2 | NUM3 |  +   |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /       /       \      \  |      |      |      |
     *                   |      |      ||||||||/       /         \      \ |      ||||||||      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_RAISE] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        ____, DE_ADIA, DE_ODIA, DE_UDIA, ____, ____,                KC_NUM, KC_P7, KC_P8, KC_P9, KC_KP_SLASH, KC_F12,   
        KC_CAPS, ____, ____, ____, ____, ____,                      ____, KC_P4, KC_P5, KC_P6, KC_KP_ASTERISK, ____,
        ____, ____, ____, ____, ____, ____, ____,                   ____, KC_P0, KC_P1, KC_P2, KC_P3, KC_KP_PLUS, ____,
            ____, ____, ____, ____,                                     ____, ____, ____, ____
    ),
    /* CODE
     * ,-----------------------------------------------.                    ,------------------------------------------------.
     * |      |      |        |        |        |      |                    |      |        |        |         |      |      |
     * |------+------+--------+--------+--------+------|                    |------+--------+--------+---------+------+------|
     * |      |   (  |   )    |    <   |   >    |   =  |                    |      |        |        |         |      |      |
     * |------+------+--------+--------+--------+------|                    |------+--------+--------+---------+------+------|
     * |      |   {  |   }    |    &   |   |    |   +  |-------.    ,-------|      |        |        |         |      |      |
     * |------+------+--------+--------+--------+------|       |    |       |------+--------+--------+---------+------+------|
     * |      |   [  |   ]    |    *   |   ~    |   -  |-------|    |-------|      |        |        |         |      |      |
     *  -----------------------------------------------/       /             -----------------------------------------------'
     *                          |      |      |      | /      /       \      \  |      |      |      |
     *                          |      |      ||||||||/       /         \      \ |      ||||||||      |
     *                          `----------------------------'           '------''--------------------'
     */
    [_CODE] = LAYOUT(
        ____, ____, ____, ____, ____, ____,                         ____, ____, ____, ____, ____, ____,
        ____, DE_LPRN, DE_RPRN, DE_LABK, DE_RABK, DE_EQL,             ____, ____, ____, ____, ____, ____,   
        ____, DE_LCBR, DE_RCBR, DE_AMPR, DE_PIPE, DE_PLUS,             ____, ____, ____, ____, ____, ____,
        ____, K_BRTO, K_BRTC, DE_ASTR, DE_TILD, DE_MINS, ____,          ____, ____, ____, ____, ____, ____, ____,
            ____, ____, ____, ____,                                     ____, ____, ____, ____
    ),

    /* MEDIA
     * ,-----------------------------------------------.                     ,------------------------------------------------.
     * |      | MUTE |        |        |        |      |                    |      |        |        |         |      |      |
     * |------+------+--------+--------+--------+------|                    |------+--------+--------+---------+------+------|
     * |      | VOLU | PTrack | Play/P | NTrack |      |                    |       |        |       |         |      |      |
     * |------+------+--------+--------+--------+------|                    |------+--------+--------+---------+------+------|
     * | CAPS | VOLD |        |        |        |      |-------.    ,-------|      |        |        |         |      |      |
     * |------+------+--------+--------+--------+------|       |    |       |------+--------+--------+---------+------+------|
     * |      |      |  CALC  |  COPY  |  PASTE |      |-------|    |-------|      |        |        |         |      |      |
     *  -----------------------------------------------/       /             -----------------------------------------------'
     *                          |      |      |      | /      /       \      \  |      |      |      |
     *                          |      |      ||||||||/       /         \      \ |      ||||||||      |
     *                          `----------------------------'           '------''--------------------'
     */
    [_MEDIA] = LAYOUT(
        ____, KC_MUTE, ____, ____, ____, ____,                      ____, ____, ____, ____, ____, ____,
        ____, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, ____,             ____, ____, ____, ____, ____, ____,   
        ____, KC_VOLD, ____, ____, ____, ____,                      ____, ____, ____, ____, ____, ____,
        ____, ____, KC_CALC, KC_COPY, KC_PASTE, ____, ____,         ____, ____, ____, ____, ____, ____, ____,
            ____, ____, ____, ____,                                     ____, ____, ____, ____
    ),
};

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(HSV_SPRINGGREEN);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _RACING:
        rgb_matrix_sethsv (HSV_PURPLE); 
        rgb_matrix_mode_noeeprom(RGB_MATRIX_MULTISPLASH);
        break;
    case _RAISE:
        rgb_matrix_sethsv (HSV_TEAL);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR); 
        break;
    case _MEDIA:
        rgb_matrix_sethsv (HSV_CORAL);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR); 
        break;
    case _CODE:
        rgb_matrix_sethsv (HSV_RED);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR); 
        break;
    default: //  for any other layers, or the default layer
    case _QWERTZ:
        rgblight_sethsv (HSV_SPRINGGREEN);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
        break;
    }
  return state;
}

#endif


#ifdef OLED_ENABLE

static void render_home(void) {
    static const char PROGMEM home_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x20, 0x30, 0x30, 0xcc, 0xcc, 0xf3, 
        0xf3, 0xcc, 0xcc, 0x30, 0x30, 0x70, 0xff, 0xff, 0x03, 0x03, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
        0x80, 0x80, 0x60, 0x60, 0x98, 0x9c, 0xe2, 0xe3, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xe0, 0xe0, 0x9f, 0x9f, 0x60, 0x60, 0x80, 0x80, 
        0x01, 0x01, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x07, 0x07, 0x07, 
        0x07, 0x07, 0x07, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0x01, 0x01, 
        0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00
    };
    oled_write_raw_P(home_logo, sizeof(home_logo));
    oled_set_cursor(0, 4);
}

static void render_code(void) {
    static const char PROGMEM code_logo[] = {
        0xf0, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
        0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0xf0, 
        0xff, 0x00, 0x00, 0x00, 0x00, 0x10, 0x28, 0x08, 0x44, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 
        0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x44, 0x40, 0x28, 0x10, 0x00, 0x00, 0x00, 0x00, 0xff, 
        0x3f, 0x00, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0xd0, 0x50, 0x50, 
        0x50, 0x50, 0xd0, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x00, 0x3f, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x04, 0x06, 0x01, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x06, 0x04, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(code_logo, sizeof(code_logo));
    oled_set_cursor(0, 4);
}

static void render_car(void) {
    static const char PROGMEM car_logo [] = {
        0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
        0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x30, 0xe0, 0x00, 0x00, 0x00, 0x00, 
        0xc0, 0x60, 0x30, 0x1e, 0x13, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
        0x10, 0x18, 0x1c, 0x16, 0x13, 0x11, 0x11, 0x11, 0x13, 0x1e, 0x1c, 0x11, 0x1f, 0x18, 0x60, 0xc0, 
        0xff, 0xc0, 0x80, 0x8f, 0x9f, 0x99, 0x99, 0x99, 0x9f, 0x8f, 0x80, 0x80, 0x8a, 0x8a, 0x8a, 0x8a, 
        0x8a, 0x8a, 0x8a, 0x8a, 0x80, 0x80, 0x8f, 0x9f, 0x99, 0x99, 0x99, 0x9f, 0x8f, 0x80, 0xc0, 0xff, 
        0x07, 0x0c, 0x08, 0x08, 0x08, 0x08, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x08, 0x08, 0x08, 0x08, 0x0c, 0x07
    };

    oled_write_raw_P(car_logo, sizeof(car_logo));
    oled_set_cursor(0, 4);
}
void render_empty_line(void) {
    oled_write_ln_P(PSTR(""), false);
}

bool oled_task_user(void) {
    // A 128x32 OLED rotated 90 degrees is 5 characters wide and 16 characters tall

    if (is_keyboard_master()){
        enum layers current_active = IS_LAYER_ON(_RACING) ? _RACING : _QWERTZ;
        current_active = IS_LAYER_ON(_CODE) ? _CODE : current_active;

        switch (current_active) {
            case _RACING:
                render_car();
                break;
            case _CODE:
                render_code();
                break;
            default:
            case _QWERTZ:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                render_home();
        }
        
        render_empty_line();

    } else {

        oled_write_P(PSTR("Layer"), false);
        render_empty_line();
        switch (get_highest_layer(layer_state)) {
            case _QWERTZ:
                oled_write("Std\n", false);
                break;
            case _RACING:
                oled_write("Race\n", false);
                break;
            case _RAISE:
                oled_write("Raise", false);
                break;
            case _CODE:
                oled_write("Code\n", false);
                break;
            case _MEDIA:
                oled_write("Media", false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write("Undef", false);
        }

        render_empty_line();
        render_empty_line();
        // Host Keyboard LED Status
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.num_lock ? PSTR("NUM\n") : PSTR("    "), false);
        oled_write_P(led_state.caps_lock ? PSTR("CAP\n") : PSTR("    "), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCR\n") : PSTR("    "), false);
    }

    return false;
}

#endif
