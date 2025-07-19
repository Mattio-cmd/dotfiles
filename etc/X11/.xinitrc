# Start PipeWire + Pulse compatibility + WirePlumber
xrandr --output HDMI-0 --mode 1920x1080 --rate 100

pipewire &
#pipewire-pulse &
#wireplumber &

nitrogen --restore &
slstatus &
picom &
mpd &
dunst &
lxqt-policykit-agent &

setxkbmap -layout us,it,es -variant qwerty -option "grp:alt_space_toggle" &

exec dwm
