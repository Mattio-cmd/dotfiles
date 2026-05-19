### Description
This layout is a scalable alternative to the "tile" and "spiral" layouts, optimized for wide monitors. Both the master area and the stack are "spirals", but windows in the master area are split horizontally as long as the master area has enough horizontal space, and the first window in the stack is split vertically unless the stack is wide.

With one window in the master area and `mfact = 0.5`, it behaves like the spiral layout:

```
┌───────────────┬────────────────┐
│               │                │
│               │                │
│               │                │
│               │                │
│               ├───┬───┬────────┤
│               │   │   │        │
│               ├───┴───┤        │
│               │       │        │
│               │       │        │
└───────────────┴───────┴────────┘
```

With 2 windows in the master area and 2 in the stack:

```
┌───────────────┬────────────────┐
│               │                │
│               │                │
│               │                │
│               │                │
├───────────────┼────────────────┤
│               │                │
│               │                │
│               │                │
│               │                │
└───────────────┴────────────────┘
```

With 3 windows in the master area and 2 in the stack:

```
┌───────────────┬────────────────┐
│               │                │
│               │                │
│               │                │
│               │                │
├───────┬───────┼────────────────┤
│       │       │                │
│       │       │                │
│       │       │                │
│       │       │                │
└───────┴───────┴────────────────┘
```

With many windows in both areas:

```
┌───────────────┬────────────────┐
│               │                │
│               │                │
│               │                │
│               │                │
├───┬───┬───────┼───┬───┬────────┤
│   │   │       │   │   │        │
├───┴───┤       ├───┴───┤        │
│       │       │       │        │
│       │       │       │        │
└───────┴───────┴───────┴────────┘
```

With 2 windows in the master area, many windows in the stack and high mfact:

```
┌──────────┬──────────┬──────────┐
│          │          │          │
│          │          │          │
│          │          │          │
│          │          │          │
│        master       ├──┬stack──┤
│          │          │  │  │    │
│          │          ├──┴──┤    │
│          │          │     │    │
│          │          │     │    │
└──────────┴──────────┴─────┴────┘
```

With 2 windows in the master area, many windows in the stack and low mfact:

```
┌──────────┬──────────┬──────────┐
│          │          │          │
│          │          │          │
│          │          │          │
│          │          │          │
├──master──┤        stack┬──┬────┤
│          │          │  │  │    │
│          │          ├──┴──┤    │
│          │          │     │    │
│          │          │     │    │
└──────────┴──────────┴─────┴────┘
```

### Download
- [0.8](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/snail/snail-0.8.patch)
- [0.7](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/snail/snail-0.7.patch)

### Authors
- [Dima Krasner](https://codeberg.org/dimkr) (<dima@dimakrasner.com>)
- [Nikita Ivanov](https://github.com/NikitaIvanovV)
