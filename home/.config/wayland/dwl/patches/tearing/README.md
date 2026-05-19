### Description
This patch adds support for tearing protocol. To get it working `export WLR_DRM_NO_ATOMIC=1` is probably required.
Some apps would send ASYNC hint and tearing will "just work", otherwise it's possible to force specified clients to tear with a rule.

Set rules in the config.h (exact string match):
```
static const ForceTearingRule force_tearing[] = {
	{.title = "", .appid = "hl_linux"},
	{.title = "Warcraft III", .appid = ""},
	{.title = "", .appid = "gamescope"},
};
```
### Download
- [0.7](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/tearing/tearing-0.7.patch)
- [2025-04-22](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/tearing/tearing.patch)
- [git branch](https://codeberg.org/korei999/dwl/src/branch/tearing)
### Authors
- [korei999](https://codeberg.org/korei999)
