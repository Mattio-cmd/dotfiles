#! /bin/sh

declare STATUS="`mpc status | head -2 | tail -1 | cut -c2-7`"
declare VOLUME="`mpc volume | awk '{ print $2 }'`"

if [[ $STATUS == "paused" ]]; then
  dunstify "Song Paused!" -i ~/.config/dunst/images/novolume2.png -u low -t 1000
else
  dunstify "Song Volume: " -i ~/.config/dunst/images/volume2.png -u normal -t 1000 -h int:value:"`mpc volume | awk '{ print $2 }'`" -h string:synchronous:"Volume: " --replace=555
fi
