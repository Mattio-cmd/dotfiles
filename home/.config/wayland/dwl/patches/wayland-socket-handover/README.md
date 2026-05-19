### Description

When your Wayland compositor crashes, your entire session dies with it. This
patch allows your session to survive a restart or crash of dwl by passing in
the Wayland socket from an outside wrapper program such as
[wl-restart](https://github.com/Ferdi265/wl-restart).

To use, apply this patch and start dwl with `wl-restart --env dwl [args...]`.
This automatically restarts dwl when it crashes and tries to keep applications
alive.

Currently, only **Qt6** supports surviving a compositor restart. The
environment variable `QT_WAYLAND_RECONNECT=1` needs to be set in order for Qt
apps to stay alive when the compositor crashes.

## Download
- [git branch](https://codeberg.org/yrlf/dwl/src/branch/feature-socket-handover)
- [2025-03-26](https://codeberg.org/yrlf/dwl-patches/raw/branch/main/patches/wayland-socket-handover/wayland-socket-handover.patch)

### Authors
- [yrlf](https://codeberg.org/yrlf)
