/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define ORYX_CONFIGURATOR
#define LAYER_STATE_16BIT

#define RGB_MATRIX_STARTUP_SPD 6

#include "moonlander_wrapper.h"
#define LAYOUT_split_3x5_3(...) MOONLANDER_LAYOUT_WRAPPER_EX_CORNER(__VA_ARGS__, KC_MNXT, KC_MPLY)
#define LED_LAYOUT_split_3x5_3 MOONLANDER_LED_LAYOUT_WRAPPER_CORNER
