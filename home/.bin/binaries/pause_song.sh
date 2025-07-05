#! /bin/sh

SONG="$(mpc status | head -1)"
CURRENT_STATE="$(mpc status | head -2 | tail -1 | cut -c2-7)"
declare PAUSED="paused"
declare PLAYING="playin"

if [ "$CURRENT_STATE" == "$PAUSED" ]
then
  notify-send "$SONG" "\nPaused" -i ~/.config/dunst/images/paused.png -t 1000
elif [ "$CURRENT_STATE" == "$PLAYING" ]
then
  notify-send "$SONG" "\nPlayin" -i ~/.config/dunst/images/resumed.png -t 1000
else
  echo
fi
