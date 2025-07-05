if [[ "light" -ge 100 ]]; then
  dunstify "Light: Max" -u low -t 1000
else
  #dunstify "Light: " `light` -u normal -t 1000
      dunstify "Light: `light`" \
        -i ~/.config/dunst/images/dante.jpg \
        -u normal \
        -t 1000 \
        -h int:value:"`light`" \
        -h string:synchronous:"Light: " \
        --replace=555
fi
