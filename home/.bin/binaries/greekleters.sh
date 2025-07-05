#!/bin/bash
KAO="λ
Σ
μ
π"
MENU="$(rofi -p "Greek leters" -dmenu -i <<< $KAO)"
notify-send "$MENU" "Copied to clipboard!" && echo $MENU | tr -d "\n" | xclip -selection clipboard
