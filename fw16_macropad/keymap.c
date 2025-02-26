// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "keyrecords/combos.h"
#include "keyrecords/keycodes.h" 
#include "rgb/rgb.h"
#include "hexa.h"


#define NUMLOCK_INTERVALL 200  // Trigger Intervall for Update Numlock in milliseconds

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

    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SPLASH);
    rgb_matrix_sethsv_noeeprom(HSV_PURPLE);

}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {

    return true;
}

bool led_update_user(led_t led_state) {

    /*
    * Keep NUMPAD state in sync with the host
    * can be triggered by OS or numlock key
    * 
    * Trigger function if State of Macropad does not align with 
    * state of NumLock Key
    */

    if (host_keyboard_led_state().num_lock) { 
        // uprintf("Disable FN\n");
        // NUM Lock active do nothing and let it overwrite by led effect
    } else {
        // uprintf("Enable FN\n");
        // NUM Lock deactivate, enable overlay layer
        rgb_matrix_set_color(5, RGB_BLUE);
        rgb_matrix_set_color(2, RGB_BLUE);
        rgb_matrix_set_color(22, RGB_BLUE);
        rgb_matrix_set_color(17 , RGB_BLUE);
    }

    
    return true;
}

void suspend_power_down_user(void) {
    // code will run multiple times while keyboard is suspended
    rgb_matrix_disable_noeeprom();
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SPLASH);
    rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
}

layer_state_t layer_state_set_user(layer_state_t state) {

    switch (get_highest_layer(state)) {
    // Skip this layer because it is no real layer   
    // case FN:
    //     break;
    case MEDIA:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_PIXEL_RAIN);
        rgb_matrix_sethsv_noeeprom(HSV_TEAL);
        break;
    case NUMPAD:
    default:
        //  for any other layers, or the default layer
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SPLASH);
        rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
        break;
    }

    return state;
}
