#ifndef OLED_H
#define OLED_H

#ifdef OLED_ENABLE

void render_home(void);
void render_code(void);
void render_car(void);
void render_arcade(void);
void render_arrow(void);
void render_media(void);
void render_navigation(void);

void render_empty_line(void);

bool oled_timeout_housekeeping(void);

#define TIMER_DURATION 200 // how long each frame lasts in ms

#if defined(OLED_DISPLAY_128X128) || defined(OLED_DISPLAY_128X64)
#    define OLED_DISPLAY_VERBOSE

#    define OLED_RENDER_KEYLOGGER "Keylogger: "
#    ifndef OLED_KEYLOGGER_LENGTH
#        define OLED_KEYLOGGER_LENGTH 9
#    endif
#    define OLED_RENDER_LAYOUT_NAME "Layout: "
#    define OLED_RENDER_LAYOUT_QWERTY "Qwerty"
#    define OLED_RENDER_LAYOUT_COLEMAK_DH "Colemak DH"
#    define OLED_RENDER_LAYOUT_COLEMAK "Colemak"
#    define OLED_RENDER_LAYOUT_DVORAK "Dvorak"
#    define OLED_RENDER_LAYOUT_WORKMAN "Workman"
#    define OLED_RENDER_LAYOUT_NORMAN "Norman"
#    define OLED_RENDER_LAYOUT_MALTRON "Matron"
#    define OLED_RENDER_LAYOUT_EUCALYN "Eucalyn"
#    define OLED_RENDER_LAYOUT_CARPLAX "Carplax"

#    define OLED_RENDER_LAYER_NAME "Layer:"
#    define OLED_RENDER_LAYER_LOWER "Lower"
#    define OLED_RENDER_LAYER_RAISE "Raise"
#    define OLED_RENDER_LAYER_ADJUST "Adjust"
#    define OLED_RENDER_LAYER_MODS "Mods"

#    define OLED_RENDER_LOCK_NAME "Lock: "
#    define OLED_RENDER_LOCK_NUML "NUM"
#    define OLED_RENDER_LOCK_CAPS "CAPS"
#    define OLED_RENDER_LOCK_SCLK "SCLK"

#    define OLED_RENDER_MODS_NAME "Mods"
#    define OLED_RENDER_MODS_SFT "Sft"
#    define OLED_RENDER_MODS_CTL "Ctl"
#    define OLED_RENDER_MODS_ALT "Alt"
#    define OLED_RENDER_MODS_GUI "GUI"

#    define OLED_RENDER_BOOTMAGIC_NAME "Boot  "
#    define OLED_RENDER_BOOTMAGIC_NKRO "NKRO"
#    define OLED_RENDER_BOOTMAGIC_NOGUI "nGUI"
#    define OLED_RENDER_BOOTMAGIC_GRV "GRV"
#    define OLED_RENDER_BOOTMAGIC_ONESHOT "1SHT"
#    define OLED_RENDER_BOOTMAGIC_SWAP "SWAP"
#    define OLED_RENDER_BOOTMAGIC_CAPS "CAPS"

#    define OLED_RENDER_USER_NAME "USER:"
#    define OLED_RENDER_USER_ANIM "Anim"
#    define OLED_RENDER_USER_LAYR "Layr"
#    define OLED_RENDER_USER_NUKE "Nuke"

#    define OLED_RENDER_WPM_COUNTER "WPM: "
#else

#    define OLED_RENDER_LAYOUT_NAME "Lyout"
#    define OLED_RENDER_LAYOUT_QWERTZ " QRTZ"
#    define OLED_RENDER_LAYOUT_QWERTZ_NEW " QRTZ"


#    define OLED_RENDER_LAYER_NAME "LAYER"
#    define OLED_RENDER_LAYER_LOWER "Lower"
#    define OLED_RENDER_LAYER_RAISE "Raise"
#    define OLED_RENDER_LAYER_ADJUST "Adjst"
#    define OLED_RENDER_LAYER_MODS " Mods"

#    define OLED_RENDER_LOCK_NAME "Lock:"
#    define OLED_RENDER_LOCK_NUML "NumL"
#    define OLED_RENDER_LOCK_CAPS "CapL"
#    define OLED_RENDER_LOCK_SCLK "ScrL"

#    define OLED_RENDER_MODS_NAME "Mods: "
#    define OLED_RENDER_MODS_SFT "Shft"
#    define OLED_RENDER_MODS_CTL "Ctrl"
#    define OLED_RENDER_MODS_ALT "Alt\n"
#    define OLED_RENDER_MODS_GUI "GUI\n"

#    define OLED_RENDER_USER_NAME "USER:"
#    define OLED_RENDER_USER_ANIM "Anim"
#    define OLED_RENDER_USER_LAYR "Layr"
#    define OLED_RENDER_USER_NUKE "Nuke"

#endif

#endif // OLED_ENABLE
#endif // OLED_H