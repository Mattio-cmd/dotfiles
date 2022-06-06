#!/usr/bin/dash
export _JAVA_AWT_WM_NONREPARENTING=1

userresources=$HOME/.config/xorg-related/.Xresources
usermodmap=$HOME/.config/xorg-related/.Xmodmap
sysresources=/etc/X11/xinit/.Xresources
sysmodmap=/etc/X11/xinit/.Xmodmap

# merge in defaults and keymaps

if [ -f $sysresources ]; then







    xrdb -merge $sysresources

fi

if [ -f $sysmodmap ]; then
    xmodmap $sysmodmap
fi

if [ -f "$userresources" ]; then







    xrdb -merge "$userresources"

fi

if [ -f "$usermodmap" ]; then
    xmodmap "$usermodmap"
fi

# start some nice programs

if [ -d /etc/X11/xinit/xinitrc.d ] ; then
 for f in /etc/X11/xinit/xinitrc.d/?*.sh ; do
  [ -x "$f" ] && . "$f"
 done
 unset f
fi


# Keyboar toggle
setxkbmap -layout us,es -variant qwerty -option "grp:alt_space_toggle" &

# slstatus
slstatus &


# Wallpaper
#nitrogen --restore &

# for dunst
dunst &

# Loop
while true; do
   dwm>/dev/null 2>&1
done
# xlock
xautolock -time 10 -locker slock &

# Startx
startx

# Start qtile
#qtile

# Execute dwm
exec dwm

dunst &
eww daemon &



pcmanfm -daemon-mode &



# Compositor #picom
#Network Manager Applet #nm-applet &
#
#ratbagctl 'Glorious Model O' rate set 300

