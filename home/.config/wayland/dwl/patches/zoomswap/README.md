### Description
This patch swaps the current window (C) with the previous master (P) when zooming.
```
Original behaviour :
+-----------------+-------+
|                 |       |
|                 |       |
|                 |       |
|        P        +-------|
|                 |       |
|                 |   C   |
|                 |       |
+-----------------+-------+

+-----------------+-------+
|                 |       |
|                 |   P   |
|                 |       |
|        C        +-------|
|                 |       |
|                 |       |
|                 |       |
+-----------------+-------+

New Behaviour :
+-----------------+-------+
|                 |       |
|                 |       |
|                 |       |
|        C        +-------+
|                 |       |
|                 |   P   |
|                 |       |
+-----------------+-------+

+-----------------+-------+
|                 |       |
|                 |       |
|                 |       |
|        P        +-------+
|                 |       |
|                 |   C   |
|                 |       |
+-----------------+-------+
```

### Download
- [git branch](https://codeberg.org/Palanix/dwl/src/branch/zoomswap)
- [v0.7](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/zoomswap/zoomswap-v0.7.patch)
- [v0.6](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/zoomswap/zoomswap-v0.6.patch)
- [2024-02-15](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/zoomswap/zoomswap.patch)

### Authors
- [Palanix](https://codeberg.org/Palanix)
