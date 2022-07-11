#!/bin/sh
function night() {
  notify-send -u low -i ~/.config/dunst/images/pacman-ghost.png "Changing to gruvbox-material systemwide"
  nitrogen --set-scaled ~/Pictures/Neon_city_green.png
  cp ~/.config/xressources/gruvbox/.Xresources ~/
  cp ~/.config/alacritty/alternatives/gruvbox/alacritty.yml ~/.config/alacritty
  cp ~/.config/nvim/lua/alternatives/gruvbox/init.lua /home/mattio/.config/nvim
  cp ~/.config/nvim/lua/alternatives/gruvbox/lualine.lua /home/mattio/.config/nvim/lua/plugins
  light -S 30 # My eyes hurt
  xrdb ~/.Xresources
}

function day() {
  notify-send -u low -i ~/.config/dunst/images/pacman-ghost.png "Changing to kanagawa systemwide"
  light -S 80
  nitrogen --set-scaled ~/.config/nvim/extras/wallpapers/kanagawa-wp.jpg
  cp ~/.config/xressources/kanagawa/.Xresources ~/
  cp ~/.config/alacritty/alternatives/kanagawa/alacritty.yml ~/.config/alacritty
  cp ~/.config/nvim/lua/alternatives/kanagawa/init.lua ~/.config/nvim
  cp ~/.config/nvim/lua/alternatives/kanagawa/lualine.lua ~/.config/nvim/lua/plugins
  xrdb ~/.Xresources
}

while true
do
  if [[ `date +%H` -gt 16 || `date +%H` -lt 7 ]]
  then
    night
  else
    day
  fi
  sleep 3530 # 60 mins
done
