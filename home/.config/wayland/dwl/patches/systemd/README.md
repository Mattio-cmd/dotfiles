### Description
This is a simple patch that runs `systemctl --user import-environment WAYLAND_DISPLAY DISPLAY`, and `systemctl --user start dwl-session.target` after Dwl initializes, and then `systemctl --user stop dwl-session.target` when Dwl quits. This allows you to handle graceful startup and shutdown of your graphical systemd services, with the proper environment variables set. This is similar to [uwsm](https://github.com/Vladimir-csp/uwsm?tab=readme-ov-file), but it integrates natively with your existing systemd user services, and doesn't have uwsm's runtime overhead.

You must have a `dwl-session.target` created that binds to `graphical-session.target`. You can then set the WantedBy of your systemd services to either `graphical-session.target`, or `dwl-session.target`, depending on whether you want them to start for just Dwl, or for every graphical session.

Below is the Nix home-manager configuration I use to generate `dwl-session.target`, and its resulting output.
```
systemd.user.targets.dwl-session.Unit = {
  Description = "dwl compositor session";
  Documentation = [ "man:systemd.special(7)" ];
  BindsTo = [ "graphical-session.target" ];
  Wants = [ "graphical-session-pre.target" ];
  After = [ "graphical-session-pre.target" ];
};
```

```
[Unit]
After=graphical-session-pre.target
BindsTo=graphical-session.target
Description=dwl compositor session
Documentation=man:systemd.special(7)
Wants=graphical-session-pre.target
```

### Download
- [git branch](https://github.com/Shringe/dwl/tree/systemd) 
- [0.7](/dwl/dwl-patches/raw/branch/main/patches/systemd/systemd-0.7.patch)

### Authors
- [Shringe](https://codeberg.org/Shringe)
- shringe_ at [dwl Discord](https://discord.gg/jJxZnrGPWN)

