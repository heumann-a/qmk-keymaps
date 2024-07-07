#include "quantum.h"
#include "keycodes.h"

// Add the behaviour of this new keycode
__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    default:
      break;
  }
  return process_record_keymap(keycode, record);
}