#!/usr/bin/dash
export _JAVA_AWT_WM_NONREPARENTING=1

# slstatus
slstatus &


# Loop
while true; do
   dwm>/dev/null 2>&1
done

# Startx
startx

# Execute dwm
exec dwm

dunst &
eww daemon &

