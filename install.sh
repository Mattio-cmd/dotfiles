#! /bin/sh

if (( $EUID == 0 )); then
    echo "ERROR, script cant be run as root"
    exit
fi

DOSU=sudo
read -p "If you are using doas instead of sudo, type doas" DOSU

printf "This is script is probably going to override old configs, so make sure to back them up first\n"
printf "So, control c out of this script if you haven donde so yet\n"
sleep 10

printf "The /etc files wont be installed as they are kind of personal and can get in your way.\n"
sleep 5

printf "Installing all configs to ~/.config..."
cp home/.config/* $HOME/.config
cp home/.bin/shell_scripts/* $HOME/.local/bin
cd $HOME/.config/suckless/ && cd dwm-6.2; $(DOSU) make clean install && cd ../st; $(DOSU) make clean install && cd ../slstatus; $(DOSU) make clean install && cd ../slock; $(DOSU) make clean install
