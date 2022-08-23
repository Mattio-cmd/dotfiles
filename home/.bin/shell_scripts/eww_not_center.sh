#!/bin/bash

## CMD and DIR
EWW="/usr/bin/eww"
DIR="$HOME/.config/eww/control-center"

${EWW} -c ${DIR} open --toggle control-center

