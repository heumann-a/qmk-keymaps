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

# New Liatris Setting
# BOOTLOADER = rp2040 # currently not supported
CONVERT_TO=promicro_rp2040


OLED_ENABLE = yes
OCEAN_DREAM_ENABLE = yes
LUNA_ENABLE = yes

# RGB Matrix is enabled at the revision level,
# while we use the regular RGB underglow for testing
RGBLIGHT_ENABLE = no		# Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE = yes		# Enable keyboard backlight functionality
RGB_MATRIX_KEYPRESSES = yes

# Keyboard specific defines overwrite userspace
TAP_DANCE_ENABLE = no		# Enable Tab Dance for Tap-Hold features

