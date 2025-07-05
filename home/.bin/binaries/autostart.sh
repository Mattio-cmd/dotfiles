#!/bin/sh

exec > /tmp/autostart.log 2>&1

setxkbmap -layout us,it,es -variant qwerty -option "grp:alt_space_toggle" &

# Restore wallpaper
pgrep -x nitrogen >/dev/null || nitrogen --restore &

# Status bar
pgrep -x slstatus >/dev/null || slstatus &

# Compositor (clean config required)
pgrep -x picom >/dev/null || picom &

# Notifications
pgrep -x dunst >/dev/null || dunst &

# Audio
#pgrep -x pipewire_start.sh >/dev/null || pipewire_start.sh &
#pgrep -x pipewire >/dev/null || pipewire &
#pgrep -x wireplumber >/dev/null || wireplumber &
#pgrep -x pipewire-pulse >/dev/null || pipewire-pulse &

# Music
#pgrep -x mpd >/dev/null || mpd &
