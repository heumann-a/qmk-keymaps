#pragma once

#include "keymap_german.h"

// Tap Dance declarations
enum {
    TD_O_OE,
    TD_U_UE,
    TD_A_AE,
    TD_S_SS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for O, twice for German OE
    [TD_O_OE] = ACTION_TAP_DANCE_DOUBLE(KC_O, DE_ODIA),
    // Tap once for U, twice for German UE
    [TD_U_UE] = ACTION_TAP_DANCE_DOUBLE(KC_U, DE_UDIA),
    // Tap once for A, twice for German AE
    [TD_A_AE] = ACTION_TAP_DANCE_DOUBLE(KC_A, DE_ADIA),
    // Tap once for S, twice for German ß
    [TD_S_SS] = ACTION_TAP_DANCE_DOUBLE(KC_S, DE_SS),
};
