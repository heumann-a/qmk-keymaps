// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "keyrecords/combos.h"
#include "keyrecords/keycodes.h" 
#include "hexa.h"

enum layers {
    NUMPAD = 0,
    FN,
    MEDIA
};

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
     *  4 keys │ RGB   │ RGB + │       │ Boot  │
     *         │ vAI   │ VAI   │       │ loader│
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │NUMLOCK│       │       │       │
     *         │       │       │       |       │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ Prev  │ Play  │ Next  │RGB Nxt│
     *         │ Track │ Pause │ Track │Effect │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ Page  │       │ Page  │RGB Prv│
     *         │  UP   │       │  DOWN │Effect │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ End   │  ↓    │ Page  │ BL    │
     *         │       │       │ Down  │ Step  │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ Insert│ Insert│ Delete│ BL    │
     *         │       │       │       │ Step  │
     *         └───────┴───────┴───────┴───────┘
     * 24 total
 +    */
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
     *  4 keys │ RGB   │ RGB + │       │ Boot  │
     *         │ vAI   │ VAI   │       │ loader│
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │NUMLOCK│       │       │       │
     *         │       │       │       |       │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ Prev  │ Play  │ Next  │RGB Nxt│
     *         │ Track │ Pause │ Track │Effect │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ Page  │       │ Page  │RGB Prv│
     *         │  UP   │       │  DOWN │Effect │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ End   │  ↓    │ Page  │ BL    │
     *         │       │       │ Down  │ Step  │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ Insert│ Insert│ Delete│ BL    │
     *         │       │       │       │ Step  │
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

    // does not work at all
    rgb_matrix_enable();
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv(HSV_WHITE);
    // rgb_matrix_set_flags(LED_FLAG_ALL);


    // Sync initial NUMPAD state from the host
    if (host_keyboard_led_state().num_lock) {
        layer_on(FN);
    } else {
        layer_off(FN);
    }
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
    uprintf("RGB Matrix Status %u\n", rgb_matrix_is_enabled());
    uprintf("RGB Matrix Suspend %u\n", rgb_matrix_get_suspend_state());
    uprintf("RGB Matrix Mode %u\n", rgb_matrix_get_mode());
    uprintf("RGB Matrix Brightness %u\n", rgb_matrix_get_val());

    // This somehow works and displays a color and mode although wrong colours
    // rgb_matrix_enable_noeeprom();
    // rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
    // rgb_matrix_set_color_all(HSV_SPRINGGREEN);

    return true;
}

bool rgb_matrix_indicators_kb() {

    led_t led_state = host_keyboard_led_state();
    if (led_state.num_lock) {
        layer_off(FN);
    } else {
        layer_on(FN);
    }

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {

    // uprintf("Layer State %u\n", state);
    // does nothing as of right now
    switch (get_highest_layer(state)) {
    case FN:
        // uprintf("State FN\n");
        rgb_matrix_mode(RGB_MATRIX_BREATHING);
        rgb_matrix_sethsv(HSV_TEAL);
        break;
    case MEDIA:
        // uprintf("State MEDIA\n");
        rgb_matrix_mode(RGB_MATRIX_HUE_WAVE);
        rgb_matrix_sethsv(HSV_TEAL);
        break;
    case NUMPAD:
    default: //  for any other layers, or the default layer
        // uprintf("State NUMPAD\n");
        rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_sethsv(HSV_PURPLE);
        break;
    }

    return state;
}
