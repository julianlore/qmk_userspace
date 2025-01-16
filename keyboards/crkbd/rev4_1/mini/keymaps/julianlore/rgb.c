#include QMK_KEYBOARD_H
#include "layers.h"

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case L_NAV:
            rgb_matrix_set_color_all(RGB_GREEN);
            break;
        case L_NUM:
            rgb_matrix_set_color_all(RGB_CYAN);
            break;
        case L_SYMBOL:
            rgb_matrix_set_color_all(RGB_PINK);
            break;
        case L_SHORTCUT:
            rgb_matrix_set_color_all(RGB_ORANGE);
            break;
        case L_SYSTEM:
            rgb_matrix_set_color_all(RGB_RED);
            break;
        default:
            break;
    }
    // Do not continue running keyboard level callback
    return false;
}
