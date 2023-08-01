// Own Keycodes 
#pragma once

#define ____ KC_TRNS
#define XXXX KC_NO

#define K_BRTO RALT(KC_8)
#define K_BRTC RALT(KC_9)

// Tap Codes
#define SPLT(x) LT(x, KC_SPACE)
#define BSPLT(x) LT(x, KC_BSPC) 

enum keycodes {
  KC_BASE_CYCLE = QK_USER,
};