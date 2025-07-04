if [[ "`light`" -ge 100 ]]; then
  dunstify "Light: Max" -u low -t 1000
else
  dunstify "Volume: " `light` -u normal -t 1000
fi
