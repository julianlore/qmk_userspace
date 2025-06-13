#include QMK_KEYBOARD_H
#include "layers.h"

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Immediately select the hold action when another key is pressed while these keys are held to avoid false negatives.
        case LT(L_SYMBOL, KC_ENT):
        case LSFT_T(KC_BSPC):
            return true;
        default:
            return false;
    }
}
