#include "custom_keycodes.h"
#include "sm_td/sm_td.h"
#include "keymap_canadian_multilingual.h"
#include "layers.h"

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_A, KC_A, KC_LEFT_GUI)
        SMTD_MT(CKC_S, KC_S, KC_LEFT_ALT)
        SMTD_MT(CKC_D, KC_D, KC_LSFT)
        SMTD_MT(CKC_F, KC_F, KC_LEFT_CTRL)
        SMTD_MT(CKC_J, KC_J, KC_LEFT_CTRL)
        SMTD_MT(CKC_K, KC_K, KC_LSFT)
        SMTD_MT(CKC_L, KC_L, KC_LEFT_ALT)
        SMTD_MT(CKC_SCLN, KC_SCLN, KC_LEFT_GUI)

        SMTD_MT(CKC_Z, KC_Z, KC_LSFT)
        SMTD_LT(CKC_X, KC_X, L_NUM)
        SMTD_LT(CKC_C, KC_C, L_SYMBOL)
        SMTD_LT(CKC_COMM, KC_COMM, L_SYMBOL)
        SMTD_LT(CKC_DOT, KC_DOT, L_NUM)
        SMTD_MT(CCA_SLSH, CA_SLSH, KC_LSFT)

        SMTD_LT(CKC_SPC, KC_SPC, L_SHORTCUT)
        SMTD_MT(CKC_BSPC, KC_BSPC, KC_LSFT)
    }
}
