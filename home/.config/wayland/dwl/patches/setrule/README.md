### Description

This patch adds an ability to add or change client rules at runtime.

Sometimes it happens that some client rule I've set is not relevant in the
current circumstance and adds major disturbance and annoyance to my work
(e.g., `isfloating` is set or unset and I want the opposite). Changing the rule
is not an option because it will require recompilation and restarting dwl, which
is even worse. Having an option of always being able to change a rule solves
this issue.

The patch only adds one keybinding (`Alt+Shift+R`) to toggle `isfloating`
option. Upon pressing it, dwl will try to find a matching rule for the focused
client and change its `isfloating` setting. If there's no such a rule, a new
rule will be added. The new rule will inherit an appid of the focused client.

It's very easy to add support for more rule options from other patches as well.
You just need to define a new function similar to `setruleisfloating` and add a
new keybinding to `config.h`. For example, this is a function I created for my
build to toggle `noswallow` option from the [swallow][swallow] patch:

```c
void
setrulenoswallow(const Arg *arg)
{
	Rule *r = getrule(focustop(selmon));
	if (!r)
		return;
	r->noswallow = !r->noswallow;
}
```

You can also try [menurule][menurule] patch if you want to be able to edit rules
with dmenu.

[swallow]:  /dwl/dwl-patches/src/branch/main/patches/swallow
[menurule]: /dwl/dwl-patches/src/branch/main/patches/menurule

### Download

- [0.8](/dwl/dwl-patches/raw/branch/main/patches/setrule/setrule-0.8.patch)
- [0.7](/dwl/dwl-patches/raw/branch/main/patches/setrule/setrule-0.7.patch)
- [2025-02-14 v0.7](https://codeberg.org/dwl/dwl-patches/raw/commit/268bee3cee239e5bd52cceed88a52bfc21143cc3/patches/setrule/setrule.patch)

### Authors

- [Nikita Ivanov](https://codeberg.org/nikitaivanov) ([GitHub](https://github.com/NikitaIvanovV))
