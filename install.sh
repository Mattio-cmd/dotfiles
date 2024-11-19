#! /bin/sh

if (( $EUID == 0 )); then
    echo "ERROR, script can't be run as root"
    exit
fi

DOSU=sudo
read -p "If you are using doas instead of sudo, type doas" DOSU

printf "This is script is probably going to override old configs, so make sure to back them up first\n"
printf "control+c to safely quit the script if you haven donde so yet\n"
sleep 6

printf "The script will now copy X related stuff"
cp etc/X11/.xinitrc etc/X11/.Xresources $HOME
cp home/.themes $HOME && cp home/.icons $HOME

printf "Installing all configs to ~/.config..."
cp home/.config/* $HOME/.config
cp home/.bin/shell_scripts/* $HOME/.local/bin
cd $HOME/.config/suckless/ && cd dwm-6.5; $(DOSU) make clean install && cd ../st; $(DOSU) make clean install && cd ../slstatus; $(DOSU) make clean install && cd ../slock; $(DOSU) make clean install
