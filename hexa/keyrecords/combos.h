#pragma once
#include "quantum.h"

enum combos {
  O_ODIA,
  U_UDIA,
  A_ADIA,
};

const uint16_t PROGMEM odia_combo[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM udia_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM adia_combo[] = {KC_A, KC_E, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [O_ODIA] = COMBO(odia_combo, DE_ODIA),
  [U_UDIA] = COMBO(udia_combo, DE_UDIA),
  [A_ADIA] = COMBO(adia_combo, DE_ADIA),
};