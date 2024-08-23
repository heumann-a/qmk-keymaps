# How to setup and use own QMK code

I would recommend to disable VIA through [rules.mk](rules.mk) to avoid having weird issues QMK booting from EEPROM instead of flash and not using your latest firmware during your setup. 
I haven't tested enabling it again afterwards.

Before you begin:

    Download firmware of [Framework Repo](https://github.com/FrameworkComputer/qmk_firmware/tags) to reflash the macropad in case you mess up something!

## Setup environment

My setup is described [here](../README.md). I use an modified branch of framework because they use a function which should be reserved for us and not the keyboard manufacturer

I am currently using: https://github.com/heumann-a/fw_qmk_firmware/tree/fl16-v0.2.8-prep
This Repo you are currently in : https://github.com/heumann-a/qmk-keymaps

I will update the fw16-qmk repo regurlarly to the latest version of Framework QMK


## Reset EEPROM 

### Reset via Bootloader

- Reset the Macropad by pressing the Keys 2 + 6 and reseating the Macropad into the Laptop
- Reseat again
- EEPROM is cleared you can continue to flash own

### Use VIA (not tested)

- Open https://keyboard.frame.work
- Modify one key differently 
  - use Special > Any key and set it to `EE_CLR`
  - Press the key
- EEPROM is cleared you can continue to flash own

## Flash QMK

Use this folder as a base and start from there. Every Code commented with multiline comments are functions, which should be kept to keep core functionality of the numpad, if you want to keep it. Otherwise you are free to modify as you see fit.

```
/*
*
*\
./compile.sh build fw16_macropad
```



## The changed codebase

As of writing this, the last active branch is` fl16-v0.2.8-prep`, where i changed functions to be able to setup own things. In my own modified , you can already find all these changes. 


##### keyboards/framework/framework.c
- REMOVED function call `keyboard_post_init_user()` from `keyboard_post_init_kb()`

##### keyboards/framework/macropad/keymaps/default/keymap.c

- CHANGED function body of `led_update_user()`
- MOVED function  from `keyboards/framework/macropad/macropad.c` t this file `keyboard_post_init_user()`
- MOVED Enum for layers from `keyboards/framework/macropad/macropad.h` to this file

#### keyboards/framework/macropad/macropad.c

- SEE MOVING function two bullet points above this  one

#### keyboards/framework/macropad/macropad.h

- SEE MOVING enum two bullet points above this  one