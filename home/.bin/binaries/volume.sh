#!/bin/bash

# You can call this script like this:
# $ ./volume.sh show

function get_volume {
    pamixer --get-volume || echo "0"
}

function is_mute {
    pamixer --get-mute && echo "true" || echo "false"
}

function send_notification {
    volume=$(get_volume)
    # Ensure volume is a number
    if ! [[ "$volume" =~ ^[0-9]+$ ]]; then
        volume=0
    fi
    # Send the notification with the specified style
    dunstify "Audio Volume: $volume%" \
        -i ~/.config/dunst/images/volume2.png \
        -u normal \
        -t 1000 \
        -h int:value:"$volume" \
        -h string:synchronous:"Volume: " \
        --replace=555
}

case $1 in
    show)
        if [[ $(is_mute) == "true" ]]; then
            dunstify "Muted" \
                -i ~/.config/dunst/images/volume2.png \
                -u normal \
                -t 1000 \
                --replace=555
        else
            send_notification
        fi
        ;;
esac
