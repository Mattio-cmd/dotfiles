### Description
This patch adds river-control-unstable-v1 support to dwl.
This protocol allows sending args to dwl to execute functions via the included dwlctl.
This is used to allow changing rules and binds, at runtime via dwlctl.

Most of this patch is stored in river-control.h, It contains a list of functions which can be called via dwlctl so adding support for new functions is as simple as adding them to the list.

This patch's main intended use case is to have a startup script that calls dwlctl a bunch to add all the binds/rules you want, without the need of restarting dwl if you make any changes to the list of binds/rules.

This patch also adds keybind modes which allow switching between a different sets of keybinds on the fly.
Also you can set a keybind mode as  oneshot (meaning as soon as a keybind is activated the mode is switched) by using...
`dwlctl oneshot-mode _layout_you_want_to_make_oneshot_here_ _layout_you_want_to_switch_to_after_keybind_pressed_`
Just make sure to set a mode as oneshot after creating a bind under it otherwise it won't work.


### dwlctl syntax example
```
dwlctl clear-binds

dwlctl bind normal super,shift Return spawn kitty tmux

dwlctl bind normal supershift q killclient

dwlctl bind normal super l enter-mode layoutpick

dwlctl bind layoutpick none t layout 0
dwlctl bind layoutpick none f layout 1
dwlctl bind layoutpick none m layout 2
dwlctl oneshot-mode layoutpick normal

dwlctl clear-rules

dwlctl rule-add -appid steam -title steam float tags $((1 << 2))

dwlctl rule-add -appid kitty float

dwlctl rule-add -title firefox float

dwlctl spawn kitty tmux

dwlctl setlayout 2

dwlctl togglefullscreen
```

### Download
- [git branch](/zuki/dwl-ctl/src/main) 
- [0.7](/dwl/dwl-patches/raw/branch/main/patches/riverctl/riverctl.patch)
- [main 2025-07-29](/dwl/dwl-patches/raw/branch/main/patches/riverctl/riverctl.patch)
### Authors - latest at top
- [zuki](https://codeberg.org/zuki)
  zukirust@gmail.com
  zuki at [Libera IRC dwl channel](https://web.libera.chat/?channels=#dwl)
  #zukigay at [dwl Discord](https://discord.gg/jJxZnrGPWN)
