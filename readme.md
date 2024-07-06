
# Information

A user repository with own keymaps for QMK Keyboards, followed guide:

[Guide for QMK GitRepo](https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd)


# Setup

## Requirements and supported OS

- Linux
- Window (Cygwin Console).
- Python

## Setup own small QMK Repo

1. Install QMK via python
2.  Clone this, the oringal qmk repo and if necessary the framework qmk repo next to each other in one folder
3. Enter the original QMK and execute qmk setup
4. Enter the framework repo and checkout the latest tag of the repo, than execute qmk doctor to see if everything works

```shell
git clone <url> [folder] 
git clone https://github.com/qmk/qmk_firmware.git
git clone https://github.com/FrameworkComputer/qmk_firmware.git fw16_qmk_firmware
cd qmk_firmware
qmk setup
cd ../fw16_qmk_firmware
git fetch --all --tags
git checkout $(git describe --tags "$(git rev-list --tags --max-count=1)")
qmk doctor
```

1. Remove/Replace folder [lily58](lily58) with your specific keymap/keyboard.
2. Replace content of [user](user) folder with your own information.


# Usage

Script [compile.sh](compile.sh) will handle everything for you!
Just specify which keymap **folder** you want to generate hex files for you.
Output is currently the main folder of this repo, you are free to change that inside that script.

```
./compile.sh build lily58
```

If it's not executable, maybe file rights aren't correct. (chmod may help)
