#include QMK_KEYBOARD_H
#include "layers.h"

bool set_color_all_and_stop(uint8_t r, uint8_t g, uint8_t b) {
    rgb_matrix_set_color_all(r, g, b);
    return false;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case L_ALPHA:
            return set_color_all_and_stop(RGB_OFF);
        case L_NAV:
            return set_color_all_and_stop(RGB_GREEN);
        case L_NUM:
            return set_color_all_and_stop(RGB_CYAN);
        case L_SYMBOL:
            return set_color_all_and_stop(RGB_PINK);
        case L_SHORTCUT:
            return set_color_all_and_stop(RGB_ORANGE);
        case L_MOUSE:
            return set_color_all_and_stop(RGB_GOLD);
        case L_SYSTEM:
            return set_color_all_and_stop(RGB_RED);
        default:
            break;
    }
    // Do not continue running keyboard level callback
    return false;
}
