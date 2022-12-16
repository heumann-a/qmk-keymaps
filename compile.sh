#!/bin/bash
export LANG=C.UTF-8

#------------------------------------------
# Constants
#------------------------------------------
WORKING_DIR="$(pwd)"
export QMK_FIRMWARE_HOME="$WORKING_DIR/qmk_firmware"
QMK_USER="$WORKING_DIR/user"
KEYMAP="custom"

#------------------------------------------
# Variable depending on input
#------------------------------------------
KEYBOARD=""
KEYMAP_LINK=""

echo "-------------------------"
echo "> Compiling QMK Firmware"
echo -e "-------------------------\n"

if [[ -z "$1" ]]
then
    echo -e "No Keyboard specified! \nExiting..."
    exit 0
fi

#------------------------------------------
# Create Keymap symbolic link
#------------------------------------------
case $1 in
    "lily58" )
        echo "> Keymap folder lily58 will be used!"
        KEYBOARD="splitkb/aurora/lily58/rev1"
        KEYMAP_LINK="$QMK_FIRMWARE_HOME/keyboards/splitkb/aurora/lily58/keymaps/custom"
        ln -s "$WORKING_DIR/lily58" $KEYMAP
        mv $KEYMAP $KEYMAP_LINK
        ;;
    *)
        echo -e "No Keyboard specified! \nExiting..."
        exit 0
        ;;
esac

#------------------------------------------
# Create User Symbolic Link
#------------------------------------------
# ln -s $QMK_USER $KEYMAP "$QMK_FIRMWARE_HOME/users/halex"

#------------------------------------------
# Compile Firmware
#------------------------------------------
echo -e "> Compiling Firmware now...\n"
qmk compile -kb $KEYBOARD -km compile.keymap=$KEYMAP


# Cleanup of Links and Files
echo "> Cleanup of symbolic link dir...\n"
rm -r $KEYMAP_LINK