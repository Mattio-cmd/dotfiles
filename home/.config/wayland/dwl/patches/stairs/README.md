### Description
Port of the [stairs](https://dwm.suckless.org/patches/stairs/) patch from dwm.

The remaining text is from the description on the dwm site:

This layout can be modified using the 3 variables provided in config.h: stairpx, stairdirection and stairsamesize.

```
+-------------+--------+----------------+
|             |        |                |
|             |     +--|       S1       |
|             |     |S2|                |
|             |  +--|  |                |
|             |  |S3|  |                |
|      M      |--|  |  +----------------+
|             |S4|  |                 | |
|             |  |  +-----------------+ |
|             |  |                  |   |
|             |  +------------------+   |
|             |                   |     |
+-------------+-------------------+-----+
            stairsamesize = 1

+-------------+--------+----------------+
|             |        |                |
|             |     +--|       S1       |
|             |     |S2|                |
|             |  +--|  |                |
|             |  |S3|  |                |
|      M      |--|  |  |                |
|             |S4|  |  |                |
|             |  |  |  |                |
|             |  |  |  |                |
|             |  |  |  |                |
|             |  |  |  |                |
+-------------+--+--+--+----------------+
            stairsamesize = 0
```
### Download
- [0.7](/dwl/dwl-patches/raw/branch/main/patches/stairs/stairs.patch)
### Authors
- [MayOrMayNotBeACat](https://codeberg.org/MayOrMayNotBeACat)
