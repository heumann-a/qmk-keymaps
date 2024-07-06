// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "keyrecords/combos.h"
#include "keyrecords/keycodes.h" 
#include "hexa.h"

enum layers {
    _NUMLOCK = 0,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
     *         ┌────┬────┬────┬────┐
     *  4 keys │Esc │Calc│ =  │ <- │
     *         ├────┼────┼────┼────┤
     *  4 keys │ Num│ /  │ *  │ -  │
     *         ├────┼────┼────┼────┤
     *  3 keys │ 7  │ 8  │ 9  │ +  │
     *         ├────┼────┼────┼────┤
     *  4 keys │ 4  │ 5  │ 6  │ +  │
     *         ├────┼────┼────┼────┤
     *  3 keys │ 1  │ 2  │ 3  │Entr│
     *         ├────┼────┼────┼────┤
     *  3 keys │ 0  │ ,  │ .  │Entr│
     *         └────┴────┴────┴────┴
     * 21 total
     */
    [_NUMLOCK] = LAYOUT(
        KC_ESC,  KC_CALC, KC_EQL,  KC_BSPC,
        KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_P0,   KC_PCMM, KC_PDOT, KC_PENT
    ),
     /*
     *         ┌───────┬───────┬───────┬───────┐
     *  4 keys │ RGB   │ RGB + │ RGB + │ RGB + │
     *         │Toggle │ Speed │ Hue   │ Sat   │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │Numlock│ RGB - │ RGB - │ RGB - │
     *         │       │ Speed │ Hue   │ Sat   │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ Home  │   ↑   │ Page  │RGB Nxt│
     *         │       │       │ Up    │Effect │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │  ←    │       │   →   │RGB Prv│
     *         │       │       │       │Effect │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ End   │  ↓    │ Page  │ BL    │
     *         │       │       │ Down  │ Step  │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ Insert│ Insert│ Delete│ BL    │
     *         │       │       │       │ Step  │
     *         └───────┴───────┴───────┴───────┘
     * 24 total
     */
    [_FN] = LAYOUT(
        RGB_TOG, BL_STEP, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______
    ),
};


#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(HSV_WHITE);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _FN:
        rgb_matrix_sethsv(HSV_BLUE);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING); 
        break;
    default: //  for any other layers, or the default layer
    case _NUMLOCK:
        rgblight_sethsv (HSV_WHITE);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
        break;
    }
  return state;
}

#endif