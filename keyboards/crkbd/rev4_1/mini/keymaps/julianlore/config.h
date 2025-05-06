/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

#define RGB_MATRIX_DEFAULT_VAL 100 // 0 - 255
// For per layer RGB to work on both sides
#define SPLIT_LAYER_STATE_ENABLE
// 200 is the default, but we document it explicitly here for reference
#define TAPPING_TERM 200
// For sm_td
#define MAX_DEFERRED_EXECUTORS 10
#define PERMISSIVE_HOLD
// Default is TAPPING_TERM / 4. Lowering the value will avoid considering the release of two keys in this term as holds, i.e. avoid holds for fast typing.
#define SMTD_GLOBAL_RELEASE_TERM TAPPING_TERM / 8
