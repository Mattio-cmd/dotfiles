### Description

# btrtile — A Focus-Driven Tiling Layout

It provides a focus-driven, mouse- and keyboard-friendly tiling layout that grants you granular control over how clients are placed and resized.

![btrtile in action](https://github.com/julmajustus/dwl-patches/blob/main/demos/btrtiledemo.gif?raw=true)

---

# Why btrtile

While dwl’s patches folder is full of different layouts, I couldn't find suitable layout that would work well with my workflow and single ultrawide monitor setup. btrtile aims to solve that by introducing a layout strategy that splits clients according to user focus and pointer position.

---

# Features

- **Combined Tiling and Management**  
  Combines tiling layout and management of clients under one patchset.

- **Focus-Driven Splits**  
  When you add a new client, btrtile checks where your pointer is relative to the focused client’s geometry.  
  - If the pointer is on the left half (for a horizontally large client), the new client spawns on the left side, and vice versa.  
  - By default, new splits are 50/50.

- **Adaptive Splitting**  
  - If the area to be split is wider than its height, btrtile does a vertical split.  
  - Otherwise, it does a horizontal split.

- **Keyboard and Mouse Driven**  
  - Supports keyboard-based commands for quick ratio adjustments and client swapping.  
  - Mouse-based resizing and moving are integrated for more intuitive manipulation.

---

# How It Works

btrtile organizes clients using a binary tree data structure that represents splits either vertically or horizontally.

When a new client appears:
1. **Focused Client Detection**  
   btrtile checks your pointer location to find which client (if any) you’re interacting with.
2. **Split Creation**  
   - If there’s a focused client, btrtile creates a split node around it, placing the new client on the side where your pointer is.  

3. **Ratio Management**  
   Each split node has a `split_ratio` (defaulting to 0.5). This ratio defines how much space is allocated to each child node. You can adjust this ratio using keyboard or mouse actions.

---

# What It Doesn’t Handle

- **Suckless philosophy**
  - Yea, it's a bloat. I tried to hide the suck inside a single file as much I could. While this approach is not ideal, it's how it's at least for now.

---

# Configuring btrtile

btrtile adds couple variables to config.h to fine tune the mouse resizing of tiled clients.

1. **resize_factor**
	- A multiplier to transfer pointer movement to client weight ratio. Depends heavily on mouse sensitivity.  
      Defaults to 0.0002f.

2. **resize_interval_ms**
	- A time based resize call limiter. Depends on framerate and screen refresh rate.   
      Defaults to 16ms. (~60 resize updates per second)

Fine tune these values to find the best values for your setup, smoother resizing can significally increase cpu overhead.  
If mouse resizing feels sluggish, you can try compiling dwl with more aggressive optimization flags like -O2/-O3. 

---

# Patch recommendations

1. **Patches that I use with my btrtile**
     
   - [focusdir](https://codeberg.org/dwl/dwl-patches/src/branch/main/patches/focusdir)  
     Great patch to move focus between clients.

   - [rotatetags](https://codeberg.org/dwl/dwl-patches/src/branch/main/patches/rotatetags)  
     Good patch to rotate the view or shift clients between tags.

   - [warpcursor](https://codeberg.org/dwl/dwl-patches/src/branch/main/patches/warpcursor)  
     Moves cursor location to focused client.

   - [pertag](https://codeberg.org/dwl/dwl-patches/src/branch/main/patches/pertag)  
     Allows each tag to have individual layout setups.

   - [gaps](https://codeberg.org/dwl/dwl-patches/src/branch/main/patches/gaps)  
     Add gaps between clients.

---

### Download
- [git branch](https://codeberg.org/julmajustus/dwl/src/branch/btrtile-dev) 
- [0.8](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/btrtile/btrtile-v0.8.patch)
- [0.8 WITH gaps](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/btrtile/btrtile-v0.8-gaps.patch)
- [wlroots-next](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/btrtile/btrtile-wlroots-next-d41ecb7.patch)
- [wlroots-next WITH gaps](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/btrtile/btrtile-wlroots-next-d41ecb7-gaps.patch)

### Authors
- [julmajustus](https://codeberg.org/julmajustus)
