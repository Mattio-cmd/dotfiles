#!/bin/bash

## CMD and DIR
EWW="/usr/bin/eww"
DIR="$HOME/.config/eww/lock"

${EWW} -c ${DIR} open --toggle lock-weather
