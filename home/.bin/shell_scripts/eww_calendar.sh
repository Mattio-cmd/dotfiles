#!/bin/bash

## CMD and DIR
EWW="/usr/bin/eww"
DIR="$HOME/.config/eww/calendar"

${EWW} -c ${DIR} open --toggle calendar
