#include QMK_KEYBOARD_H
#include "macros.h"

bool process_smtd(uint16_t keycode, keyrecord_t* record);

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        if (!keypress_macros(keycode)) return false;
    }

    if (!process_smtd(keycode, record)) return false;

    return true;
}
