#!/bin/bash
export LANG=C.UTF-8

#------------------------------------------
# Constants
#------------------------------------------
WORKING_DIR="$(pwd)"
export QMK_FIRMWARE_HOME="${WORKING_DIR}/qmk_firmware"
QMK_USER="${WORKING_DIR}/user"
KEYMAP="custom"

#------------------------------------------
# Variable depending on input
#------------------------------------------
KEYBOARD=""
KEYBOARD_FOLDERNAME=""
KEYMAP_LINK=""
FILENAME=""
ACTION=""


#------------------------------------------
# Argument Handling
#------------------------------------------
ACTION="$1"
KEYBOARD_FOLDERNAME="$2"

if [[ "${ACTION}" != @("build"|"flash"|"clean") ]]
then
    echo -e "Wrong Action specified! \nExiting..."
    exit 0
fi

if [[ -z "${KEYBOARD_FOLDERNAME}" ]]
then
    echo -e "No Keyboard specified! \nExiting..."
    exit 0
fi

echo "-------------------------"
echo "> Compiling QMK Firmware"
echo -e "-------------------------\n"

#------------------------------------------
# Create Keymap symbolic link
#------------------------------------------
case ${KEYBOARD_FOLDERNAME} in
    "lily58" )
        echo "> Keymap folder lily58 will be used!"
        KEYBOARD="splitkb/aurora/lily58/rev1"
        KEYMAP_LINK="${QMK_FIRMWARE_HOME}/keyboards/splitkb/aurora/lily58/keymaps/custom"
        FILENAME="splitkb_aurora_lily58_rev1"
        ln -s "${WORKING_DIR}/lily58" ${KEYMAP_LINK}
        mv ${KEYMAP} ${KEYMAP_LINK}
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
# Do Actions
#------------------------------------------
pushd qmk_firmware
case ${ACTION} in
    "build" )
        echo -e "> Compiling Firmware now...\n"
        # Use this feature on Windows
        # qmk compile -j 10  -kb $KEYBOARD -km $KEYMAP
        make ${KEYBOARD}:${KEYMAP}
        ;;
    "flash" )
        make ${KEYBOARD}:${KEYMAP}:flash -o ${FILENAME}
        ;;
    "clean" )
        echo -e "> Removing Output files..."
        echo -e ">      .*hex files in qmk_firmware folder"
        echo -e ">      .build folder in qmk_firmware folder"
        rm -r -- "${QMK_FIRMWARE_HOME}/.build" 
        rm -- "${QMK_FIRMWARE_HOME}"/*.hex 
        ;;
    *)
        echo -e "No Keyboard specified! \nExiting..."
        exit 0
        ;;
esac
popd



#------------------------------------------
#  Cleanup of Links and Files
#------------------------------------------
echo -e "> Cleanup of symbolic link dir...\n"
rm -r ${KEYMAP_LINK}

echo -e "> Copy Output to Working Direction..."
mv "${QMK_FIRMWARE_HOME}/${FILENAME}_${KEYMAP}.hex" "new_${KEYBOARD_FOLDERNAME}.hex"
