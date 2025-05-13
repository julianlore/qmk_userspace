/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "custom_keycodes.h"
#include "keymap_canadian_multilingual.h"
#include "layers.h"

// Formatted with qmk.nvim: https://github.com/codethread/qmk.nvim/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────┬────┬────┬─────────────┬──────┬────────────┐   ┌───────────────────┬──────────────┬────────────┬────┬────┬────┐
//    │ q  │ w  │ e  │      r      │  t   │    lctl    │   │ LCTL(LALT(home))  │      y       │     u      │ i  │ o  │ p  │
//    ├────┼────┼────┼─────────────┼──────┼────────────┤   ├───────────────────┼──────────────┼────────────┼────┼────┼────┤
//    │ Ca │ Cs │ Cd │     Cf      │  g   │    f14     │   │      LCTL(a)      │      h       │     Cj     │ Ck │ Cl │ C; │
//    ├────┼────┼────┼─────────────┼──────┼────────────┘   └───────────────────┼──────────────┼────────────┼────┼────┼────┤
//    │ Cz │ Cx │ Cc │      v      │  b   │                                    │      n       │     m      │ C, │ C. │ C/ │
//    └────┴────┴────┼─────────────┼──────┼────────────┐   ┌───────────────────┼──────────────┼────────────┼────┴────┴────┘
//                   │ LSFT_T(tab) │ Cspc │ OSL(L_NAV) │   │ LT(L_SYMBOL, ent) │ LSFT_T(bspc) │ OSL(L_NUM) │
//                   └─────────────┴──────┴────────────┘   └───────────────────┴──────────────┴────────────┘
[L_ALPHA] = LAYOUT_split_3x5_3_ex2(
  KC_Q  , KC_W  , KC_E  , KC_R           , KC_T    , KC_LCTL    ,     LCTL(LALT(KC_HOME))  , KC_Y            , KC_U       , KC_I     , KC_O    , KC_P    ,
  CKC_A , CKC_S , CKC_D , CKC_F          , KC_G    , KC_F14     ,     LCTL(KC_A)           , KC_H            , CKC_J      , CKC_K    , CKC_L   , CKC_SCLN,
  CKC_Z , CKC_X , CKC_C , KC_V           , KC_B    ,                                         KC_N            , KC_M       , CKC_COMM , CKC_DOT , CCA_SLSH,
                          LSFT_T(KC_TAB) , CKC_SPC , OSL(L_NAV) ,     LT(L_SYMBOL, KC_ENT) , LSFT_T(KC_BSPC) , OSL(L_NUM)
),

//    ┌──────┬────────────┬───────┬───────────┬─────────────┬─────────────┐   ┌─────┬───────────┬────────────┬───────────────┬─────────────────┬─────────┐
//    │ esc  │    home    │  up   │    end    │    pgup     │ www_forward │   │ no  │  LCTL(c)  │  LCTL(z)   │      ins      │      pscr       │ LCTL(v) │
//    ├──────┼────────────┼───────┼───────────┼─────────────┼─────────────┤   ├─────┼───────────┼────────────┼───────────────┼─────────────────┼─────────┤
//    │ lsft │    left    │ down  │   rght    │    pgdn     │  www_back   │   │ no  │ LSFT(ins) │    lctl    │     lsft      │      lalt       │  lgui   │
//    ├──────┼────────────┼───────┼───────────┼─────────────┼─────────────┘   └─────┼───────────┼────────────┼───────────────┼─────────────────┼─────────┤
//    │ lctl │ LCTL(home) │ M_CEH │ LCTL(end) │     no      │                       │ M_TMUXSCR │    tab     │ LCTL(LSFT(;)) │ LCTL(LALT(del)) │   no    │
//    └──────┴────────────┴───────┼───────────┼─────────────┼─────────────┐   ┌─────┼───────────┼────────────┼───────────────┴─────────────────┴─────────┘
//                                │           │ TO(L_MOUSE) │ TO(L_ALPHA) │   │ esc │    del    │ LSFT(lgui) │
//                                └───────────┴─────────────┴─────────────┘   └─────┴───────────┴────────────┘
[L_NAV] = LAYOUT_split_3x5_3_ex2(
  KC_ESC  , KC_HOME       , KC_UP   , KC_END       , KC_PGUP     , KC_WWW_FORWARD ,     XXXXXXX , LCTL(KC_C)      , LCTL(KC_Z)    , KC_INSERT           , KC_PSCR            , LCTL(KC_V),
  KC_LSFT , KC_LEFT       , KC_DOWN , KC_RIGHT     , KC_PGDN     , KC_WWW_BACK    ,     XXXXXXX , LSFT(KC_INSERT) , KC_LCTL       , KC_LSFT             , KC_LALT            , KC_LGUI   ,
  KC_LCTL , LCTL(KC_HOME) , M_CEH   , LCTL(KC_END) , XXXXXXX     ,                                M_TMUXSCR       , KC_TAB        , LCTL(LSFT(KC_SCLN)) , LCTL(LALT(KC_DEL)) , XXXXXXX   ,
                                      _______      , TO(L_MOUSE) , TO(L_ALPHA)    ,     KC_ESC  , KC_DEL          , LSFT(KC_LGUI)
),

//    ┌────┬────┬────┬─────┬──────┬─────┐   ┌─────┬─────────────┬─────────────┬─────┬─────┬─────┐
//    │ f1 │ f2 │ f3 │ f4  │  f5  │ f6  │   │ f7  │     f8      │     f9      │ f10 │ f11 │ f12 │
//    ├────┼────┼────┼─────┼──────┼─────┤   ├─────┼─────────────┼─────────────┼─────┼─────┼─────┤
//    │ 1  │ 2  │ 3  │  4  │  5   │ no  │   │ no  │      6      │      7      │  8  │  9  │  0  │
//    ├────┼────┼────┼─────┼──────┼─────┘   └─────┼─────────────┼─────────────┼─────┼─────┼─────┤
//    │ !  │ @  │ #  │  $  │  %   │               │      ^      │      &      │  *  │  (  │  )  │
//    └────┴────┴────┼─────┼──────┼─────┐   ┌─────┼─────────────┼─────────────┼─────┴─────┴─────┘
//                   │     │ lsft │     │   │     │ TO(L_ALPHA) │ TO(L_ALPHA) │
//                   └─────┴──────┴─────┘   └─────┴─────────────┴─────────────┘
[L_NUM] = LAYOUT_split_3x5_3_ex2(
  KC_F1   , KC_F2 , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,     KC_F7   , KC_F8       , KC_F9       , KC_F10  , KC_F11  , KC_F12 ,
  KC_1    , KC_2  , KC_3    , KC_4    , KC_5    , XXXXXXX ,     XXXXXXX , KC_6        , KC_7        , KC_8    , KC_9    , KC_0   ,
  KC_EXLM , KC_AT , KC_HASH , KC_DLR  , KC_PERC ,                         KC_CIRC     , KC_AMPR     , KC_ASTR , KC_LPRN , KC_RPRN,
                              _______ , KC_LSFT , _______ ,     _______ , TO(L_ALPHA) , TO(L_ALPHA)
),

//    ┌────┬───────┬───┬────┬──────┬──────┐   ┌──────────────┬─────────────┬─────────────┬───────┬───┬────┐
//    │ !  │   É   │ É │ ^  │  `   │  no  │   │      no      │      |      │   M_ARROW   │ M_GRV │ ~ │ no │
//    ├────┼───────┼───┼────┼──────┼──────┤   ├──────────────┼─────────────┼─────────────┼───────┼───┼────┤
//    │ À  │   {   │ [ │ (  │  -   │  no  │   │      no      │      =      │      )      │   ]   │ } │ :  │
//    ├────┼───────┼───┼────┼──────┼──────┘   └──────────────┼─────────────┼─────────────┼───────┼───┼────┤
//    │ no │ M_GRV │ Ç │ _  │  <   │                         │      >      │      +      │   '   │ " │ \  │
//    └────┴───────┴───┼────┼──────┼──────┐   ┌──────────────┼─────────────┼─────────────┼───────┴───┴────┘
//                     │ no │ lsft │ lsft │   │ TO(L_SYSTEM) │ TO(L_ALPHA) │ TO(L_ALPHA) │
//                     └────┴──────┴──────┘   └──────────────┴─────────────┴─────────────┘
[L_SYMBOL] = LAYOUT_split_3x5_3_ex2(
  KC_EXLM , CA_EGRV , CA_EACU , CA_CIRC , CA_GRV  , XXXXXXX ,     XXXXXXX      , CA_PIPE     , M_ARROW     , M_GRV   , CA_DTIL , XXXXXXX,
  CA_AGRV , CA_LCBR , CA_LBRC , CA_LPRN , KC_MINS , XXXXXXX ,     XXXXXXX      , KC_EQL      , CA_RPRN     , CA_RBRC , CA_RCBR , KC_COLN,
  XXXXXXX , M_GRV   , CA_CCED , KC_UNDS , CA_LABK ,                              CA_RABK     , KC_PLUS     , CA_QUOT , CA_DQUO , CA_BSLS,
                                XXXXXXX , KC_LSFT , KC_LSFT ,     TO(L_SYSTEM) , TO(L_ALPHA) , TO(L_ALPHA)
),

//    ┌─────────┬─────────┬─────────┬──────────────┬─────────────┬─────────────┐   ┌─────────┬───────────────┬─────┬───────────┬────┬───────────────┐
//    │ LWIN(6) │ LWIN(5) │   f22   │   LWIN(7)    │   LWIN(4)   │ LALT(left)  │   │   no    │ LCTL(LSFT(c)) │ no  │ LSFT(ins) │ no │ LCTL(LSFT(v)) │
//    ├─────────┼─────────┼─────────┼──────────────┼─────────────┼─────────────┤   ├─────────┼───────────────┼─────┼───────────┼────┼───────────────┤
//    │ LWIN(1) │ LWIN(2) │ LWIN(3) │   LWIN(4)    │   LWIN(5)   │ LALT(rght)  │   │ QK_BOOT │      no       │ no  │    no     │ no │      no       │
//    ├─────────┼─────────┼─────────┼──────────────┼─────────────┼─────────────┘   └─────────┼───────────────┼─────┼───────────┼────┼───────────────┤
//    │   no    │ LWIN(3) │ LWIN(2) │   LWIN(3)    │   LWIN(1)   │                           │      no       │ no  │    no     │ no │      no       │
//    └─────────┴─────────┴─────────┼──────────────┼─────────────┼─────────────┐   ┌─────────┼───────────────┼─────┼───────────┴────┴───────────────┘
//                                  │ TO(L_SYSTEM) │ TO(L_ALPHA) │ TO(L_ALPHA) │   │         │               │     │
//                                  └──────────────┴─────────────┴─────────────┘   └─────────┴───────────────┴─────┘
[L_SHORTCUT] = LAYOUT_split_3x5_3_ex2(
  LWIN(KC_6) , LWIN(KC_5) , KC_F22     , LWIN(KC_7)   , LWIN(KC_4)  , LALT(KC_LEFT)  ,     XXXXXXX , LCTL(LSFT(KC_C)) , XXXXXXX , LSFT(KC_INS) , XXXXXXX , LCTL(LSFT(KC_V)),
  LWIN(KC_1) , LWIN(KC_2) , LWIN(KC_3) , LWIN(KC_4)   , LWIN(KC_5)  , LALT(KC_RIGHT) ,     QK_BOOT , XXXXXXX          , XXXXXXX , XXXXXXX      , XXXXXXX , XXXXXXX         ,
  XXXXXXX    , LWIN(KC_3) , LWIN(KC_2) , LWIN(KC_3)   , LWIN(KC_1)  ,                                XXXXXXX          , XXXXXXX , XXXXXXX      , XXXXXXX , XXXXXXX         ,
                                         TO(L_SYSTEM) , TO(L_ALPHA) , TO(L_ALPHA)    ,     _______ , _______          , _______
),

//    ┌──────┬─────────┬─────────┬─────────────┬─────────┬─────────┐   ┌────┬────┬─────────────┬──────┬──────┬──────┐
//    │ esc  │   no    │  MS_UP  │   MS_BTN3   │ MS_WHLU │ MS_BTN4 │   │ no │ no │     no      │  no  │ pscr │  no  │
//    ├──────┼─────────┼─────────┼─────────────┼─────────┼─────────┤   ├────┼────┼─────────────┼──────┼──────┼──────┤
//    │ lsft │ MS_LEFT │ MS_DOWN │   MS_RGHT   │ MS_WHLD │ MS_BTN5 │   │ no │ no │    lctl     │ lsft │ lalt │ lgui │
//    ├──────┼─────────┼─────────┼─────────────┼─────────┼─────────┘   └────┼────┼─────────────┼──────┼──────┼──────┤
//    │ lctl │ MS_WHLL │   no    │   MS_WHLR   │   no    │                  │ no │     no      │  no  │  no  │  no  │
//    └──────┴─────────┴─────────┼─────────────┼─────────┼─────────┐   ┌────┼────┼─────────────┼──────┴──────┴──────┘
//                               │ TO(L_ALPHA) │ MS_BTN1 │ MS_BTN2 │   │ no │ no │ TO(L_ALPHA) │
//                               └─────────────┴─────────┴─────────┘   └────┴────┴─────────────┘
[L_MOUSE] = LAYOUT_split_3x5_3_ex2(
  KC_ESC  , XXXXXXX , MS_UP   , MS_BTN3     , MS_WHLU , MS_BTN4 ,     XXXXXXX , XXXXXXX , XXXXXXX     , XXXXXXX , KC_PSCR , XXXXXXX,
  KC_LSFT , MS_LEFT , MS_DOWN , MS_RGHT     , MS_WHLD , MS_BTN5 ,     XXXXXXX , XXXXXXX , KC_LCTL     , KC_LSFT , KC_LALT , KC_LGUI,
  KC_LCTL , MS_WHLL , XXXXXXX , MS_WHLR     , XXXXXXX ,                         XXXXXXX , XXXXXXX     , XXXXXXX , XXXXXXX , XXXXXXX,
                                TO(L_ALPHA) , MS_BTN1 , MS_BTN2 ,     XXXXXXX , XXXXXXX , TO(L_ALPHA)
),

//    ┌────┬────┬────┬─────────────┬─────────────┬─────────────┐   ┌─────────────┬─────────────┬─────────────┬────┬────┬────┐
//    │ no │ no │ no │     no      │     no      │     no      │   │     no      │     no      │     no      │ no │ no │ no │
//    ├────┼────┼────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼────┼────┼────┤
//    │ no │ no │ no │     no      │     no      │   QK_BOOT   │   │   QK_BOOT   │     no      │     no      │ no │ no │ no │
//    ├────┼────┼────┼─────────────┼─────────────┼─────────────┘   └─────────────┼─────────────┼─────────────┼────┼────┼────┤
//    │ no │ no │ no │     no      │     no      │                               │     no      │     no      │ no │ no │ no │
//    └────┴────┴────┼─────────────┼─────────────┼─────────────┐   ┌─────────────┼─────────────┼─────────────┼────┴────┴────┘
//                   │ TO(L_ALPHA) │ TO(L_ALPHA) │ TO(L_ALPHA) │   │ TO(L_ALPHA) │ TO(L_ALPHA) │ TO(L_ALPHA) │
//                   └─────────────┴─────────────┴─────────────┘   └─────────────┴─────────────┴─────────────┘
[L_SYSTEM] = LAYOUT_split_3x5_3_ex2(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX     , XXXXXXX     , XXXXXXX     ,     XXXXXXX     , XXXXXXX     , XXXXXXX     , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX     , XXXXXXX     , QK_BOOT     ,     QK_BOOT     , XXXXXXX     , XXXXXXX     , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX     , XXXXXXX     ,                                 XXXXXXX     , XXXXXXX     , XXXXXXX , XXXXXXX , XXXXXXX,
                                TO(L_ALPHA) , TO(L_ALPHA) , TO(L_ALPHA) ,     TO(L_ALPHA) , TO(L_ALPHA) , TO(L_ALPHA)
)
};
/* Shortcuts for certain windows:
// - B(rowser) = Win + 1
// - V(isual Studio/other text editor) = Win + 3
// - C(onsole) = Win + 2
// - T(eams/other communications program) = Win + 4
// - W(indows terminal) = Win + 5*/
// Blank layer:
//   XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
//   XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
//   XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
//                                 XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX
