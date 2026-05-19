### Description
Implements dimming of clients which are unfocused.

The code also allows any color dimming. There is also an additional option in `Rule`, which allows you to keep the client `neverdim`, that is, as if it is focused.

There are also two functions that can be bound to a `Key` or `Button`, 
1. `toggledimming`: Which toggles dimming for all windows (except for `Rule`s)
2. `toggledimmingclient`: Which toggles dimming for the focused window, as if the client had `neverdim` applied to it. This overwrites an applied `Rule`.

### Download
- [2026-03-10](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/dim-unfocused/dim-unfocused.patch)
- [2024-09-18](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/dim-unfocused/dim-unfocused-20240918.patch)
- [2024-09-03](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/dim-unfocused/dim-unfocused-20240903.patch)
- [2024-07-14](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/dim-unfocused/dim-unfocused-20240714.patch)
- [2024-05-16](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/dim-unfocused/dim-unfocused-20240516.patch)
- [2024-04-16](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/dim-unfocused/dim-unfocused-20240416.patch)
- [git branch](https://codeberg.org/dhruva_sambrani/dwl/src/branch/dim-unfocused)

### Authors
- [Dhruva Sambrani](https://codeberg.org/dhruva_sambrani)
