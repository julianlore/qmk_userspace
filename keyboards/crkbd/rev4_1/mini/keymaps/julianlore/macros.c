#include "custom_keycodes.h"

#define SSCA_GRV SS_RALT(SS_TAP(X_LBRC)) // CA_GRV = ALGR(CA_CIRC) = ALGR(KC_LBRC)
#define SSCA_RABK SS_RALT(SS_TAP(X_DOT)) // CA_RABK = ALGR(CA_DOT) = ALGR(KC_DOT)

bool SEND_STRING_AND_STOP(const char* string) {
    SEND_STRING(string);
    return false;
}

// Returns false to not continue processing, like process_record_user
bool keypress_macros(uint16_t keycode) {
    switch (keycode) {
        case M_GRV:
            // In Canadian Multilingual, CA_GRV is a modifier, press space to get "`"
            return SEND_STRING_AND_STOP(SSCA_GRV SS_TAP(X_SPC));
        case M_TMUXSCR:
            // Tmux scroll keybind: Ctrl+a for prefix, RALT(9) for scrolling
            return SEND_STRING_AND_STOP(SS_LCTL("a") SS_RALT("9"));
        case M_CEH:
            // LCTL + End to go to the end of a document, Home to go to the beginning of the line
            return SEND_STRING_AND_STOP(SS_LCTL(SS_TAP(X_END)) SS_TAP(X_HOME));
        case M_ARROW:
            // ->
            return SEND_STRING_AND_STOP("-" SSCA_RABK);
    }

    return true;
}
