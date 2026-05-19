### Description
This patch **requires** the dwl [barconfig](https://codeberg.org/dwl/dwl-patches/src/branch/main/patches/bar) patch be applied first! The barconfig patch provides configuration for the dwl bar via the variable
`barlayout`. This determines which of the elements listed below to
display on the bar and in which order:

- 't' -> the tags
- 'l' -> the current layout symbol
- 'n' -> the window name
- 's' -> the status message
- '|' -> elements on the right of this separator will be displayed from
         the right

**NOTE**: This patch is a dwl port of the [original](https://dwm.suckless.org/patches/barconfig/) barconfig patch for dwm.

### Known Issues With Patch
Changing the location of the tags breaks the tag button presses (the buttons expect the click in the usual location of the tags). I do not have any plans to look into this, as I ported this patch for the sole purpose of having the option to omit the layout symbol from the bar.

### Download
- [main 2025-10-24](/dwl/dwl-patches/raw/branch/main/patches/barconfig/barconfig.patch)


### Authors - latest at top
- Rumen Mitov  
  Codeberg: [rumenmitov](https://codeberg.org/rumenmitov)  
  Email: rumenmitov@protonmail.com
