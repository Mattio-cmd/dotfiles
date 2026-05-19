### Description
Replace the singular keyboard and pointer input configuration with an array allowing to set different variables matching by name.

Tip to find the names: Grep for `device_name` and add a line after it to print to stdout. Then run EX: `dwl > /tmp/print_device_names.log`, exit dwl, and should see the names.

Since 2025-11-19, this has been split into two patches, one for pointer and one for keyboard.

### Download
- [git branch (pointer)](https://codeberg.org/nullsystem/dwl/src/branch/main_perinputconfig-pointer)
- [git branch (keyboard)](https://codeberg.org/nullsystem/dwl/src/branch/main_perinputconfig-keyboard)
- [2025-11-19 (pointer)](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/perinputconfig/perinputconfig-pointer.patch)
- [2025-11-19 (keyboard)](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/perinputconfig/perinputconfig-keyboard.patch)
- [2024-06-08](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/perinputconfig/perinputconfig-2024-06-08.patch)
- [v0.5](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/perinputconfig/perinputconfig-v0.5.patch)

### Authors
- [nullsystem](https://codeberg.org/nullsystem)
