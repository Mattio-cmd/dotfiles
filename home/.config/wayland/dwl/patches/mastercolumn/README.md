### Description
This patch adds a layout, `mastercol`, in which the windows in the master area are arranged in columns of equal size. The number of columns is always nmaster + 1, and the last column is a stack of leftover windows (as in the normal tile layout). It effectively differs from the default tile layout only in that master windows are arranged horizontally rather than vertically.

For gaps, apply `mastercolumn-gaps.patch` on top of `mastercolumn.patch` and `gaps.patch`.

### Download
##### `mastercolumn.patch`
- [git branch](/shivers/dwl/src/branch/mastercolumn)
- [0.7](/dwl/dwl-patches/raw/branch/main/patches/mastercolumn/mastercolumn.patch)

##### `mastercolumn-gaps.patch`
- [git branch](/shivers/dwl/src/branch/mastercolumn-gaps)
- [0.7](/dwl/dwl-patches/raw/branch/main/patches/mastercolumn/mastercolumn-gaps.patch)

### Authors
- [shivers](https://codeberg.org/shivers)
