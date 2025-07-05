#!/bin/bash

DEC=5
MIN=0
BUS=6

curr=$(ddcutil getvcp 10 --bus=$BUS | grep -Po '(?<=current value = )\d+')
new=$(( curr - DEC ))
[ $new -lt $MIN ] && new=$MIN

ddcutil setvcp 10 $new --bus=$BUS

dunstify "Light: $new" \
  -i ~/.config/dunst/images/dante.jpg \
  -u normal \
  -t 1000 \
  -h int:value:"$new" \
  -h string:synchronous:"Light: " \
  --replace=555

