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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌───┬───┬───┬──────┬───────┬──────┐   ┌──────┬───────┬──────┬───┬───┬───┐
//    │ q │ w │ e │  r   │   t   │ lctl │   │ rctl │   y   │  u   │ i │ o │ p │
//    ├───┼───┼───┼──────┼───────┼──────┤   ├──────┼───────┼──────┼───┼───┼───┤
//    │ a │ s │ d │  f   │   g   │ lalt │   │ ralt │   h   │  j   │ k │ l │ ; │
//    ├───┼───┼───┼──────┼───────┼──────┘   └──────┼───────┼──────┼───┼───┼───┤
//    │ z │ x │ c │  v   │   b   │                 │   n   │  m   │ , │ . │ / │
//    └───┴───┴───┼──────┼───────┼──────┐   ┌──────┼───────┼──────┼───┴───┴───┘
//                │ lgui │ MO(1) │ spc  │   │ ent  │ MO(2) │ ralt │
//                └──────┴───────┴──────┘   └──────┴───────┴──────┘
[0] = LAYOUT_split_3x5_3_ex2(
  KC_Q , KC_W , KC_E , KC_R    , KC_T  , KC_LCTL ,     KC_RCTL , KC_Y  , KC_U    , KC_I    , KC_O   , KC_P   ,
  KC_A , KC_S , KC_D , KC_F    , KC_G  , KC_LALT ,     KC_RALT , KC_H  , KC_J    , KC_K    , KC_L   , KC_SCLN,
  KC_Z , KC_X , KC_C , KC_V    , KC_B  ,                         KC_N  , KC_M    , KC_COMM , KC_DOT , KC_SLSH,
                       KC_LGUI , MO(1) , KC_SPC  ,     KC_ENT  , MO(2) , KC_RALT
),

//    ┌────┬────┬────┬──────┬─────┬─────┐   ┌─────┬───────┬──────┬────┬──────┬────┐
//    │ 1  │ 2  │ 3  │  4   │  5  │ no  │   │ no  │   6   │  7   │ 8  │  9   │ 0  │
//    ├────┼────┼────┼──────┼─────┼─────┤   ├─────┼───────┼──────┼────┼──────┼────┤
//    │ no │ no │ no │  no  │ no  │ no  │   │ no  │ left  │ down │ up │ rght │ no │
//    ├────┼────┼────┼──────┼─────┼─────┘   └─────┼───────┼──────┼────┼──────┼────┤
//    │ no │ no │ no │  no  │ no  │               │  no   │  no  │ no │  no  │ no │
//    └────┴────┴────┼──────┼─────┼─────┐   ┌─────┼───────┼──────┼────┴──────┴────┘
//                   │ lgui │     │ spc │   │ ent │ MO(3) │ ralt │
//                   └──────┴─────┴─────┘   └─────┴───────┴──────┘
[1] = LAYOUT_split_3x5_3_ex2(
  KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , XXXXXXX ,     XXXXXXX , KC_6    , KC_7    , KC_8    , KC_9     , KC_0   ,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX,
                                KC_LGUI , _______ , KC_SPC  ,     KC_ENT  , MO(3)   , KC_RALT
),

//    ┌────┬────┬────┬──────┬───────┬─────┐   ┌─────┬─────┬──────┬───┬───┬───┐
//    │ !  │ @  │ #  │  $   │   %   │ no  │   │ no  │  ^  │  &   │ * │ ( │ ) │
//    ├────┼────┼────┼──────┼───────┼─────┤   ├─────┼─────┼──────┼───┼───┼───┤
//    │ no │ no │ no │  no  │  no   │ no  │   │ no  │  -  │  =   │ [ │ ] │ \ │
//    ├────┼────┼────┼──────┼───────┼─────┘   └─────┼─────┼──────┼───┼───┼───┤
//    │ no │ no │ no │  no  │  no   │               │  _  │  +   │ { │ } │ | │
//    └────┴────┴────┼──────┼───────┼─────┐   ┌─────┼─────┼──────┼───┴───┴───┘
//                   │ lgui │ MO(3) │ spc │   │ ent │     │ ralt │
//                   └──────┴───────┴─────┘   └─────┴─────┴──────┘
[2] = LAYOUT_split_3x5_3_ex2(
  KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , XXXXXXX ,     XXXXXXX , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE,
                                KC_LGUI , MO(3)   , KC_SPC  ,     KC_ENT  , _______ , KC_RALT
),

//    ┌─────────┬─────────┬─────────┬─────────┬─────┬─────┐   ┌─────┬─────┬──────┬────┬────┬────┐
//    │ QK_BOOT │   no    │   no    │   no    │ no  │ no  │   │ no  │ no  │  no  │ no │ no │ no │
//    ├─────────┼─────────┼─────────┼─────────┼─────┼─────┤   ├─────┼─────┼──────┼────┼────┼────┤
//    │ RM_TOGG │ RM_HUEU │ RM_SATU │ RM_VALU │ no  │ no  │   │ no  │ no  │  no  │ no │ no │ no │
//    ├─────────┼─────────┼─────────┼─────────┼─────┼─────┘   └─────┼─────┼──────┼────┼────┼────┤
//    │ RM_NEXT │ RM_HUED │ RM_SATD │ RM_VALD │ no  │               │ no  │  no  │ no │ no │ no │
//    └─────────┴─────────┴─────────┼─────────┼─────┼─────┐   ┌─────┼─────┼──────┼────┴────┴────┘
//                                  │  lgui   │     │ spc │   │ ent │     │ ralt │
//                                  └─────────┴─────┴─────┘   └─────┴─────┴──────┘
[3] = LAYOUT_split_3x5_3_ex2(
  QK_BOOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  RM_TOGG , RM_HUEU , RM_SATU , RM_VALU , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  RM_NEXT , RM_HUED , RM_SATD , RM_VALD , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                                KC_LGUI , _______ , KC_SPC  ,     KC_ENT  , _______ , KC_RALT
)
};
