### Description

# fullscreenadaptivesync — Enables adaptive sync/VRR when a client is fullscreen.

Adds a function that automatically enables adaptive sync/VRR when a fullscreen client is detected, and disables it once the client exits fullscreen.
  
---

1. **Why**
  - Some VRR implementations can introduce distracting flickering when the display’s refresh rate is synced with the application’s framerate. While VRR is useful for some applications (especially fullscreen games), this patch automates the toggling of VRR whenever a client enters or exits fullscreen.

2. **Requirements**
  - A FreeSync/G-Sync capable monitor
  - GPU/driver support for adaptive sync

3. **How it works**
  - When a client enters fullscreen, adaptive sync is automatically enabled.
  - When the client exits fullscreen, adaptive sync is disabled again.

4. **togglefullscreenadaptivesync**
  - Adds a switch to enable or disable the fullscreenadaptivesync behavior.  
  - Enabled by default.

### Download
- [git branch](https://codeberg.org/julmajustus/dwl/src/branch/fullscreenadaptivesync-wlroots-next) 
- [0.7](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/fullscreenadaptivesync/fullscreenadaptivesync-v0.7.patch) 
- [0.8](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/fullscreenadaptivesync/fullscreenadaptivesync-v0.8.patch) 
- [wlroots-next-d41ecb7](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/fullscreenadaptivesync/fullscreenadaptivesync-wlroots-next-d41ecb7.patch) 

### Authors
- [julmajustus](https://codeberg.org/julmajustus)
