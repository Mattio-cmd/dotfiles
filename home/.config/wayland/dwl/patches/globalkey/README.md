### Description

This patch adds the ability to pass keys that are specified in the config header globally, similar to Hyprland's approach.
This might deal with Wayland's lack of global shortcuts.

Example:
```
static const PassKeypressRule pass_rules[] = {
	ADDPASSRULE("com.obsproject.Studio", XKB_KEY_Home),
	ADDPASSRULE("WebCord", XKB_KEY_n),
    /* xkb key is case-insensitive */
};
```

This will pass the `Home` key (alongside with mods) to OBS regardless of what client is currently focused, if any.
The string "com.obsproject.Studio" should match the exact appid of the client.

To get the appid use [dwlmsg](https://codeberg.org/notchoc/dwlmsg) or run stock dwl from a terminal then launch the needed application inside, dwl will print all the info to the stdout.

Note that if a popup (like [fuzzel](https://codeberg.org/dnkl/fuzzel)) is focused, no keys will be globally passed.
This is done so these menus don't get closed after hitting some of the global keys.

## Warning
This patch is a stupid hack, it doesn't work all the time.
Examples: obs needs to be clicked on once before applying global hotkeys.
Electron (discord/webcord/chromium) with wayland backend ignores the very first press.
Other programs might not work at all.

### Download
- [git branch](https://codeberg.org/korei999/dwl/src/branch/globalkey)
- [2024-06-08](https://codeberg.org/dwl/dwl-patches/src/branch/main/patches/globalkey/globalkey.patch)
### Authors
- [korei999](https://codeberg.org/korei999)
