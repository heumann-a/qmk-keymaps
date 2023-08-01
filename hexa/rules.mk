

# User wide defines
CONSOLE_ENABLE ?= no
BOOTMAGIC_ENABLE ?= no       # Enable Bootmagic Lite
CONSOLE_ENABLE ?= no         # Console for debug
COMMAND_ENABLE ?= no         # Commands for debug and configuration

SWAP_HANDS_ENABLE ?= no      # Enable one-hand typing
AUDIO_ENABLE ?= no           # Audio output on port C6
EXTRAKEY_ENABLE ?= yes       # Audio control and System control
MIDI_ENABLE ?= no            # MIDI controls

NKRO_ENABLE ?= yes  
COMBO_ENABLE ?= yes
ENCODER_ENABLE ?= no
TAP_DANCE_ENABLE ?= no		# Enable Tab Dance for Tap-Hold features
MOUSEKEY_ENABLE ?= no        # Mouse keys


RGBLIGHT_ENABLE ?= no		  # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE ?= no  # Enable keyboard backlight functionality
OLED_ENABLE ?= no

WPM_ENABLE ?= yes
OCEAN_DREAM_ENABLE ?= no
LUNA_ENABLE ?= no

SRC += $(USER_PATH)/keyrecords/keycodes.c

ifeq ($(strip $(OLED_ENABLE)), yes)

  SRC += $(USER_PATH)/oled/oled.c

  ifdef RGB_MATRIX_ENABLE
    ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
      SRC +=  $(USER_PATH)/rgb/rgb.c
    endif
  endif

  ifdef OCEAN_DREAM_ENABLE
    ifeq ($(strip $(OCEAN_DREAM_ENABLE)), yes)
      SRC +=  $(USER_PATH)/oled/ocean_dream.c
      OPT_DEFS += -DOCEAN_DREAM_ENABLE
    endif
  endif
  ifndef OCEAN_DREAM_ENABLE
    SRC += $(USER_PATH)/oled/ocean_dream.c
    OPT_DEFS += -DOCEAN_DREAM_ENABLE
  endif


  ifdef LUNA_ENABLE
    ifeq ($(strip $(LUNA_ENABLE)), yes)
      SRC +=  $(USER_PATH)/oled/luna.c
      OPT_DEFS += -DLUNA_ENABLE
    endif
  endif
  ifndef LUNA_ENABLE
    SRC += $(USER_PATH)/oled/luna.c
    OPT_DEFS += -DLUNA_ENABLE
  endif
  
endif