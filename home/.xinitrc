export GPG_TTY=$(tty)
gpgconf --kill gpg-agent
gpg-agent --daemon --pinentry-program /usr/bin/pinentry-gtk

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
syncthing -no-browser -logflags=0 >/dev/null 2>&1 &

#redshift -l 45.16031:10.79784 # Casa, a Mantova
#redshift -l 9.931806:-84.059444


setxkbmap -layout us,it,es -option "grp:alt_space_toggle" & # anki DOES NOT crash
#setxkbmap -layout us,it,es -variant qwerty -option "grp:alt_space_toggle" & # anki crashes

exec dbus-run-session dwm # remove dbus-run-session if startx does not work
