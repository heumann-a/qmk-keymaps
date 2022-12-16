
# Information

A user repository with own keymaps for QMK Keyboards, followed guide:

[Guide for QMK GitRepo](https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd)


# Setup

## Requirements and supported OS

- Linux
- Window (Cygwin Console).

## Setup own small QMK Repo

1. Clone this repo with:

```shell
git clone --recurse-submodules <url> [folder]
```
If you have forgotten to pull the submodules just execute `git submodule update--recursive`

2. Remove/Replace folder [lily58](lily58) with your specific keymap/keyboard.
3. Replace content of [user](user) folder with your own information.

### Update Repo and its submodules

Default the QMK Firmware won't be updated.

```shell
git submodule update --recursive
git add .
git commit -m "Update git submodules"
git push
```

Afterwards you stil need to pull everything with

```shell
git pull --recurse-submodules
```

# Usage

Script [compile.sh](compile.sh) will handle everything for you!
Just specify which keymap **folder** you want to generate hex files for you.
Output is currently the main folder of this repo, you are free to change that inside that script.

```
./compile.sh lily58
```

If it's not executable, maybe file rights aren't correct. (chmod may help)

### ToDo

- [ ] Add UserSpace Functionality to [compile.sh](compile.sh) script
- [ ] Add More Arguments to [compile.sh](compile.sh) script
- [ ] Fix RGB Backlight Functionality (cant be used with RGB Lighting)