

// -- Disable Debug --
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
// END Disable Debug


#ifdef OLED_ENABLE
#   define OLED_TIMEOUT 10000
#   define CUSTOM_OLED_TIMEOUT 15000
#endif

// Own Defines
#define COMBO_COUNT 4