### Description

This patch adds `menu` command, which allows dwl to interface with dmenu-like
programs.

By default, two menus are available:
- focusing a window by its title/appid by pressing `Alt+o`
- selecting a layout from a list by pressing `Alt+Shift+o`

Edit `menus` array in `config.h` to add/change menus and use a different dmenu
program (`wmenu` is the default).

### Download
- [v0.8](/dwl-patches/raw/branch/main/patches/menu/menu-0.8.patch)
- [2025-03-21 v0.7](/dwl/dwl-patches/raw/branch/main/patches/menu/menu-0.7.patch)
- [2024-07-13 v0.7](/dwl/dwl-patches/raw/commit/65ea99519bbf7a52f48932aea7385f81f8b30867/patches/menu/menu.patch)

### Authors
- [Nikita Ivanov](https://codeberg.org/nikitaivanov) ([GitHub](https://github.com/NikitaIvanovV))
