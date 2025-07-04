#!/bin/sh

# Kill existing instances
killall -q picom dunst mpd slstatus nitrogen xrdb

# Start programs
xrandr --output HDMI-1-0 --mode 1920x1080 --rate 100.00 --left-of eDP-1
picom --no-fading-openclose &
dunst &
mpd &
setxkbmap -layout us,it -variant qwerty -option "grp:alt_space_toggle" &
slstatus &

pipewire &
pipewire-pulse &
wireplumber &

xrdb -load "$XDG_CONFIG_HOME/X11/xresources" &
nitrogen --restore &
