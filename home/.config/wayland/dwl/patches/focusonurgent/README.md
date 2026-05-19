### Description

By default, dwl responds to client requests to client messages by setting the urgency bit on the named window.
This patch changes the focus to the window instead.
Both behaviours are legitimate according to the cursed spec. 
This is the approximately the equivalent of the focusonactive patch of dwm.
If you want a more controlled behavior, for example setting which clients can focus, check [activation-rule patch](https://codeberg.org/sevz/dwl-patches/src/branch/activation-rules).

### Download
- [main dwl 0.8](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/focusonurgent/focusonurgent.patch)

### Authors
- [André Desgualdo Pereira](https://codeberg.org/Kana)
