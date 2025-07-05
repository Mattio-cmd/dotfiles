#if [[ "`pamixer --get-mute`" == "true" ]]; then
  #dunstify "Volume: Muted!" -i ~/.config/dunst/images/novolume2.png -u low -t 1000
#else
  #dunstify "Volume: " `pamixer --get-volume` -i ~/.config/dunst/images/volume2.png -u normal -t 1000 -h int:value:"`pamixer --get-volume`" -h string:synchronous:"Volume: " --replace=555
#fi
