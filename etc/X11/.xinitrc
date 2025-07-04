#!/bin/sh

userresources=$HOME/.config/X11/.Xresources
usermodmap=$HOME/.config/X11/.Xmodmap
sysresources=/etc/X11/xinit/.Xresources
sysmodmap=/etc/X11/xinit/.Xmodmap

if [ -f $userresources ]; then
    xrdb -merge $userresources
fi

if [ -f $sysmodmap ]; then
    xmodmap $sysmodmap
fi

# Keyboar toggle
dunst &
setxkbmap -layout us,it -variant qwerty -option "grp:alt_space_toggle" &
slstatus &
sh pipewire_start.sh &
nitrogen --restore &
picom --no-fading-openclose &
mpd &
xrandr --output HDMI-1-0 --mode 1920x1080 --rate 100.00 --left-of eDP-1

# Loop
while true; do
   dwm>/dev/null 2>&1
done


# Execute dwm
exec dwm
