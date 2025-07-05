#!/bin/bash
KAO="🇪🇺
🇮🇹
🇮🇹
🇨🇭
🇳🇱
🌍
🏰
🇦🇹
🇵🇱
"
MENU="$(rofi -p "Emoji" -dmenu -i <<< $KAO)"
notify-send "$MENU" "Copied to clipboard!" && echo $MENU | tr -d "\n" | xclip -selection clipboard
