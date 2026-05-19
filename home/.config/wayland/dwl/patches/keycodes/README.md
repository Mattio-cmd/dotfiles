### Description
Use keycodes instead of keysyms. This way, input is independent from keyboard
layout (you can use the keys.h file to customize, or get the keycodes with
`wev` or `xkbcli interactive-wayland` (x11-libs/libxkbcommon[tools] in gentoo)).

### Download
- [git branch](https://codeberg.org/sevz/dwl/src/branch/keycodes)
- [main 2025-01-20](/dwl/dwl-patches/raw/branch/main/patches/keycodes/keycodes.patch)
- [keycodes-0.7.patch](/dwl/dwl-patches/raw/branch/main/patches/keycodes/keycodes-0.7.patch)

### Config after patching 
(run in DWL source directory)
```
export XKB_DEFAULT_VARIANT=yourbestkeyboardlayout
cc -lxkbcommon -o generate-keys generate-keys.c
./generate-keys
```

### Authors
- [sevz](https://codeberg.org/sevz)
