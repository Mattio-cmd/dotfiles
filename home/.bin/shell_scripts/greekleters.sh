#!/bin/bash
KAO="λ
Σ"
MENU="$(rofi -p "Kaomoji" -dmenu -i <<< $KAO)"
notify-send "$MENU" "Copied to clipboard!" && echo $MENU | tr -d "\n" | xclip -selection clipboard
