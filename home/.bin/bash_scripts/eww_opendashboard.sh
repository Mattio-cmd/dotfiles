#!/bin/bash

## CMD and DIR
EWW="/usr/bin/eww"
DIR="$HOME/.config/eww/dashboard"

${EWW} -c ${DIR} open --toggle dashboard
