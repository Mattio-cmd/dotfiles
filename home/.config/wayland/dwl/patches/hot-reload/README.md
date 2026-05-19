### Description
Enables hot-reloading of dwl; meaning almost all logic can be changed at runtime.
This obviously requires some black magic so for now there's a glibc 2.0 or later
dependency to this.
In particular this allows for every option in config.h to be changed at runtime.

#### Reloading
To reload rebuild dwl.so, perhaps reinstall it and then run trigger reload function (bound to Mod+Shift+R by default).
This currently calls `notify-send` in order to inform you of a reloading taking place.
So in short:
1. make changes to `config.h` or `dwl.c`
2. run `make` to rebuild dwl.so
3. run `sudo make install` to reinstall dwl


#### Limitations
Reloading the compositor will replace all functionality except for `main`, `setup`, `run` and the reload logic.
Note that you're responsible yourself for reloading resources like fonts, which may only get acquired once.
A lot of components of dwl will also only get run on a trigger (the tiling for example).
So not every change will be immediate.
Furthermore, any patch adding more global state to dwl cannot currently be reloaded properly since
we keep state in the cold part. These patches will still work and their functionality will (hopefully) be
reloadable but you will need to restart the compositor once.

#### Notes
##### reduce compile errors
This patch triggers `-Wpedantic` a bunch (I don't think there's a way around this, `dlsym` yields `void*` pointers to functions).
This will show a lot of warnings but cause no errors.
So you may want to disable this compile option in order to get readable compiler output.
##### runtime dependencies
This does depend on you having a notification daemon like `dunst` or `mako` running as well as
having `notify-send` installed in order for the compositor to inform you of the reload.


#### How?
Most of all dwl functionality is moved into a shared object file `dwl.so`, which can be reloaded at runtime.

#### How do I make this work with other patches?
Most patches should already put everything in more or less the correct place but if they don't, then here is
where you learn how to fix it.

The concept itself is quite simple. We compile dwl.c twice once normally and once with the `HOT` macro defined.
The first run will yield the executable and the second will yield a shared object file to be reloaded at runtime.
From the cold part there are some newly available macros:
> symbol names are written as-is, never as string literals
* `TSYM(T, s)` dynamically loads the symbol `s` with type `T` from the shared object file use this if you need to call functions in the cold part (i.e. the `setup` function).
* `CSYM(T, v)` dynamically accesses the value of the symbol `v` of type `T` from the shared object. Use this to query values from config.h for example.
* `LISTEN_GLOBAL(E, L)` is similar to the `LISTEN` macro. `E` is an event and `L` the name of a global
listener. Current implementation is a bit messy and I may fix it if someone bothers me about it.
* `UNLISTEN(L)` takes a listener and unregisters it. This is important for reloading.

When adding new code there are some considerations to be made. Since dwl decorates all symbols with `static` by default, we cannot access them as-is.
C's macro system is a bit too powerful though and we use this to our advantage. We will repeatedly define and
undefine a macro called `static` in order to replace the `static` keyword inside some sections.
This allows us to do less refactoring and preserve a lot of the original patch compatibility since we're only
strategically adding lines. We're trying to be as minimally invasive as we can.
As a general guide:
* global state should be global for the cold part and `extern` in the cold part meaning it should be inside a block like this:
    ```C
    #ifdef HOT
        #define static extern
    #else
        #define static 
    #endif
    ... // your global variables go here
    #undef static
    ```
* function declarations should be visible in the hot part but not included in the cold part meaning they should be enclosed like this:
    ```C
    #ifdef HOT
    #define static
    ... // your function declarations go here
    #undef static
    #endif
    ```
* static data like the event handler structs in the current `main` branch are a bit more difficult but we will let them reside inside the hot part.
Thus, we enclose them the same way we do functions:
    ```C
    #ifdef HOT
    #define static
    ... // your struct wl_listener event handlers go here
    #undef static
    #endif
    ```
* function definitions should go in the hot part, so they need to be inside a big block like this:
    ```C
    #ifdef HOT
    ... // function definitions here
    #endif
* enforce use of the `LISTEN_GLOBAL` and `UNLISTEN` macros (I know this sucks but what can I do, I need to get
access to the callbacks somehow). So you want
    * `wl_list_remove(listener.link)` to become `UNLISTEN(listener)` and
    * `wl_signal_add(event, global_listener)` to become `LISTEN_GLOBAL(event, global_listener)`.
* Make sure that any patch you're using also uses static everywhere.
* If a patch adds any config variables that are accessed in the cold part (i.e. probably `setup`),
then you'll have to manually remove the `static` keyword from them.

Note that usually you do not have to create the big `#ifdef` blocks yourself.
There is for example already a huge `#ifdef HOT`-delimited codeblock at the bottom
of dwl.c where all the function definitions go.

If you have any troubles, feel free to reach out.

### Download
- [0.7](/dwl/dwl-patches/raw/branch/main/patches/hot-reload/hot-reload-0.7.patch)
- [main 2025-05-30](/dwl/dwl-patches/raw/branch/main/patches/hot-reload/hot-reload.patch)
- find the repo for the patch [here](/Sivecano/dwl/src/branch/hot-reload)
### Authors
- [Sivecano](https://codeberg.org/Sivecano)
- Sérécano at [dwl Discord](https://discord.gg/jJxZnrGPWN)
