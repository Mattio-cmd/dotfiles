### Description

This patch adds `spawninfo` function that is very similar to `spawn`, except it
also passes some information about the focused client via stdin.

The info is passed in this format:

    PID
    TITLE
    APPID
    TAGS
    X,Y WIDTHxHEIGHT

I use it for 2 things: grabbing a screenshot of a focused window and adjusting
volume of audio produced by a focused window (so much simpler than having to
open pulsemixer every time). If you want to have the same functionality, you
need to put these scripts into your PATH and make them executable:

[screenshotwin](/dwl/dwl-patches/raw/branch/main/patches/spawninfo/screenshotwin)
for taking a screenshot (`grim` is required):

```c
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_S,          spawninfo,      SHCMD("screenshotwin") },
```

[pamixerc](/dwl/dwl-patches/raw/branch/main/patches/spawninfo/pamixerc)
for adjusting volume (`pactl` is required):

```c
	{ MODKEY,                    XKB_KEY_XF86AudioRaiseVolume,spawninfo,SHCMD("pamixerc -- -i 5") },
	{ MODKEY,                    XKB_KEY_XF86AudioLowerVolume,spawninfo,SHCMD("pamixerc -- -d 5") },
	{ MODKEY,                    XKB_KEY_XF86AudioMute, spawninfo,    SHCMD("pamixerc -- -t") },
```

### Download

- [0.7](/dwl/dwl-patches/raw/branch/main/patches/spawninfo/spawninfo.patch)

### Authors

- [Nikita Ivanov](https://codeberg.org/nikitaivanov) ([GitHub](https://github.com/NikitaIvanovV))
