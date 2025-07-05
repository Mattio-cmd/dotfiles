#!/bin/bash

INC=5  # Change step here
MAX=100
BUS=6   # Your I2C bus from `ddcutil detect`

curr=$(ddcutil getvcp 10 --bus=$BUS | grep -Po '(?<=current value = )\d+')
new=$(( curr + INC ))
[ $new -gt $MAX ] && new=$MAX

ddcutil setvcp 10 $new --bus=$BUS

dunstify "Light: $new" \
  -i ~/.config/dunst/images/dante.jpg \
  -u normal \
  -t 1000 \
  -h int:value:"$new" \
  -h string:synchronous:"Light: " \
  --replace=555

