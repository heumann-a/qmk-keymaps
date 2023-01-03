# Copyright 2022 splitkb.com <support@splitkb.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.


BOOTLOADER = atmel-dfu
MCU = atmega32u4
F_CPU = 16000000

ENCODER_ENABLE = no

OLED_ENABLE = yes
OLED_DRIVER = SSD1306

# RGB Matrix is enabled at the revision level,
# while we use the regular RGB underglow for testing
RGBLIGHT_ENABLE = no		# Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE = yes		# Enable keyboard backlight functionality

# Keyboard specific defines
NKRO_ENABLE = yes  
EXTRAKEY_ENABLE = yes       # Audio control and System control
TAP_DANCE_ENABLE = yes		# Enable Tab Dance for Tap-Hold features
CONSOLE_ENABLE = no
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
SWAP_HANDS_ENABLE = no      # Enable one-hand typing