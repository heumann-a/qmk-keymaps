/* Copyright 2022 splitkb.com <support@splitkb.com>
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

// Force Update of Information for Second OLED
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#undef SPLIT_USB_DETECT

#define TAPPING_TERM 150
#define TAPPING_TOGGLE 2

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES
#   define ENABLE_RGB_MATRIX_BREATHING
#   define ENABLE_RGB_MATRIX_HUE_BREATHING
#   define ENABLE_RGB_MATRIX_MULTISPLASH
#   define ENABLE_RGB_MATRIX_HUE_PENDULUM 
#   define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#endif

#ifdef RGB_MATRIX_KEYPRESSES  
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#endif

// Not yet available in `info.json`
#ifdef OLED_ENABLE
#   undef OLED_DISPLAY_128X64
#   define OLED_DISPLAY_128X32
#   define SPLIT_OLED_ENABLE
#endif

