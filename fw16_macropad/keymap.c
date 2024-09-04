// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "keyrecords/combos.h"
#include "keyrecords/keycodes.h" 
#include "rgb/rgb.h"
#include "hexa.h"

enum layers {
    NUMPAD = 0,
    FN,
    MEDIA
};

static bool last_numpad_value = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
     *         ┌────┬────┬────┬────┐
     *  4 keys │Esc │Calc│MEDI│ <- │
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
    [NUMPAD] = LAYOUT(
        KC_ESC,  KC_CALC, TG(MEDIA),  KC_BSPC,
        KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_P0,   KC_PCMM, KC_PDOT, KC_PENT
    ),
     /*
     *         ┌───────┬───────┬───────┬───────┐
     *  4 keys │ RGB   │ RGB + │       │       │
     *         │ vAI   │ VAI   │       │       |
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │       │       │       │       │
     *         │       │       │       |       │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │       │       │       │       │
     *         │       │       │       │       │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │       │       │       │       │
     *         │       │       │       │       │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │       │       │       │       │
     *         │       │       │       │       │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │       │       │       │       │
     *         │       │       │       │       │
     *         └───────┴───────┴───────┴───────┘
     * 24 total
     */
    [FN] = LAYOUT(
        RGB_VAI, RGB_VAD, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______
    ),
    /*
     *         ┌───────┬───────┬───────┬───────┐
     *  4 keys │       │       │       │ Boot  │
     *         │       │       │       │ loader│
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │       │       │       │       │
     *         │       │       │       │       │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ Prev  │ Play  │ Next  │       │
     *         │ Track │ Pause │ Track │       │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ Page  │  UP   │ Page  │       │
     *         │  UP   │       │  DOWN |       │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ LEFT  │  DOWN │ RIGHT │       │
     *         │       │       │       │       │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │       │       │       │       │
     *         │       │       │       │       │
     *         └───────┴───────┴───────┴───────┘
     * 24 total
 +    */
    [MEDIA] = LAYOUT(
        EE_CLR,  XXXXXXX, _______,  QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,
        KC_PGUP, KC_UP,   KC_PGDN, XXXXXXX,
        KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

void keyboard_post_init_user(void) {

    /*
    * Sync initial NUMPAD state from the host
    */
    if (host_keyboard_led_state().num_lock) {
        layer_on(FN);
        last_numpad_value = true;
    } else {
        layer_off(FN);
        last_numpad_value = false;
    }

    rgb_matrix_enable();
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv(HSV_WHITE);
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {

    return true;
}

bool led_update_user(led_t led_state) {

    /*
    * Keep NUMPAD state in sync with the host
    * can be triggered by OS or numlock key
    * 
    * need to save last state to avoid triggering layer_state_set_user() endlessly
    * thus resulting in broken RGB Matrix
    */

    if(last_numpad_value != led_state.num_lock) {
        last_numpad_value = led_state.num_lock;
        if (led_state.num_lock) {
            layer_off(FN);
        } else {
            layer_on(FN);
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {

    switch (get_highest_layer(state)) {
    case FN:
        rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_sethsv(HSV_TURQUOISE_HALF);
        break;
    case MEDIA:
        rgb_matrix_mode(RGB_MATRIX_PIXEL_RAIN);
        rgb_matrix_sethsv(HSV_TEAL);
        break;
    case NUMPAD:
    default:
        //  for any other layers, or the default layer
        rgb_matrix_mode(RGB_MATRIX_SPLASH);
        rgb_matrix_sethsv(HSV_PURPLE);
        break;
    }

    return state;
}
