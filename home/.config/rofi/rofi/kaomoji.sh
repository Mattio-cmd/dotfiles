#!/bin/bash
# ok so what this does, is something that lets you pick in between emojis i think. Ill be using this for shitposting tho
KAO="¯\_(ツ)_/¯
Add options here :)
"
MENU="$(rofi -p "Kaomoji" -dmenu -i <<< $KAO)"
notify-send "$MENU" "Copied to clipboard!" && echo $MENU | tr -d "\n" | xclip -selection clipboard
