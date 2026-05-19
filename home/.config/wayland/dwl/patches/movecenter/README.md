### Description

> This patch is no longer being maintained by me [wochap](https://codeberg.org/wochap), since I'm now using a different patch specific to my use case: https://codeberg.org/wochap/dwl/src/branch/v0.6-c/betterfloat/betterfloat-diff.patch.

This patch provides a keybinding to center the focused floating window.

Press <kbd>MODKEY</kbd> + <kbd>x</kbd> to center the focused floating window.

It does NOT center windows that are not floating.

The variable `respect_monitor_reserved_area` allows the user to choose whether to center relative to the monitor or relative to the window area.

<details>
<summary>Explanation of respect_monitor_reserved_area:</summary>
<pre>
The "Monitor area" refers to the space enclosed by the green rectangle, while the "Window area" refers to the space enclosed by the red rectangle.
<img src="https://i.imgur.com/xhejzPh.png"/>
</pre>
</details>

### Download
- [git branch](https://codeberg.org/wochap/dwl/src/branch/v0.6/movecenter)
- [v0.6](https://codeberg.org/dwl/dwl-patches/raw/commit/b1ca929ee645cd3e175f198e250448b54624acd6/patches/movecenter/movecenter.patch)
- [v0.5](https://codeberg.org/dwl/dwl-patches/raw/commit/187d7f511572457750fcf6e42c99cdc7befe05e7/patches/movecenter/movecenter.patch)

### Authors
- [wochap](https://codeberg.org/wochap)

