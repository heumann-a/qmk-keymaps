

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
AUDIO_ENABLE = no           # Audio output on port C6
MIDI_ENABLE = no            # MIDI controls


ifdef OCEAN_DREAM
  # Include my fancy rgb functions source here
  SRC += ocean_dream.c
  WPM_ENABLE = yes
endif
