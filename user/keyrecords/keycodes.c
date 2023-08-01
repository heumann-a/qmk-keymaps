#include "quantum.h"
#include "keycodes.h"

// Add the behaviour of this new keycode
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

        // Process other keycodes normally
        default:
            return true;
  } 

}