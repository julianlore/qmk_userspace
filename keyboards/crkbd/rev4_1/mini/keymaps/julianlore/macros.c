#include "custom_keycodes.h"

#define SSCA_GRV SS_RALT(SS_TAP(X_LBRC)) // CA_GRV = ALGR(CA_CIRC) = ALGR(KC_LBRC)

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case M_GRV: {
            // In Canadian Multilingual, CA_GRV is a modifier, press space to get "`"
            if (record->event.pressed) {
                SEND_STRING(SSCA_GRV SS_TAP(X_SPC));
            }
            return false;
        }
    }
    return true;
}
