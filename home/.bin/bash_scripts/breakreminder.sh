#!/bin/sh
function breakreminder() {
 notify-send -u low -i ~/.config/dunst/images/heart.png "Remember to have a good posture"
}

while true
do
  if [[ `date +%H` -gt 17 || `date +%H` -lt 7 ]]
  then
    breakreminder
  else
    breakreminder
  fi
  sleep 2000 # idk how many mins
done
