
# Information

A user repository with own keymaps for QMK Keyboards, followed guide:

[Guide for QMK GitRepo](https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd)


# Setup

## Requirements and supported OS

- Linux
- Window (Cygwin Console).

## Setup own small QMK Repo

1. Clone this and the oringal qmk repo into the same folder:

```shell
git clone <url> [folder] 
git clone https://github.com/qmk/qmk_firmware.git
```

2. Remove/Replace folder [lily58](lily58) with your specific keymap/keyboard.
3. Replace content of [user](user) folder with your own information.


# Usage

Script [compile.sh](compile.sh) will handle everything for you!
Just specify which keymap **folder** you want to generate hex files for you.
Output is currently the main folder of this repo, you are free to change that inside that script.

```
./compile.sh build lily58
```

If it's not executable, maybe file rights aren't correct. (chmod may help)
