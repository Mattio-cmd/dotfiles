/* See LICENSE file for copyright and license details. */

/*
* __  __       _   _   _                                _
*|  \/  | __ _| |_| |_(_) ___         ___ _ __ ___   __| |
*| |\/| |/ _` | __| __| |/ _ \ _____ / __| '_ ` _ \ / _` |
*| |  | | (_| | |_| |_| | (_) |_____| (__| | | | | | (_| |
*|_|  |_|\__,_|\__|\__|_|\___/       \___|_| |_| |_|\__,_|
*/
#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Iosevka Nerd Font:size=14", "Material Design Icons-Regular:size=10" };  // If tags icons dont work, just install mononoki font and use it OR just install anonymous pro nerd font from the aur and you should be fine really
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=17";
static const char col_nero[]        = "#000000";
static const char col_grigioscuro[] = "#444444";
static const char col_grigio[]      = "#778899";
static const char col_ciano[]       = "#87ceeb";
static const char col_verde[]       = "#009246";
static const char col_bianco[]      = "#ffffff";
static const char col_rosso[]       = "#CE2B37";
static const char col_rosso_scuro[] = "#8b0000";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_ciano, col_nero, col_nero },
	[SchemeSel]  = { col_ciano, col_nero,  col_verde  },
};

/* tagging */
static const char *tags[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */

	{ "Gimp",	    NULL,   NULL,           1 << 2,    0,             0,           0,        -1 },
	{ "firefox",  NULL,   NULL,           1 << 0,    0,             0,          -1,        -1 },
	{ "St",		    NULL,   NULL,           0,         0,             1,           0,        -1 },
	{ "Alacritty", NULL,  NULL,           0,         0,             1,           0,        -1 },
	{ NULL,		    NULL,   "Event Tester", 0,         0,             0,           1,        -1 }, /* xev */

	{ "Lutris",   NULL,   NULL,         1 << 1,      0,             0,           0,        -1 },
	{ "discord",  NULL,   NULL,         1 << 3,      0,		          0,           0,        -1 },
	{ "War Thunder (Vulkan, 64bit)",  NULL,   NULL,         1 << 5,      0,		          0,           0,        -1 },
	{ "Steam",    NULL,   NULL,         1 << 5,      0,	            0,           0,        -1 },
	{ "steam",    NULL,   NULL,         1 << 5,      0,	            0,           0,        -1 },
	{ "obs",      NULL,   NULL,         1 << 8,      0,		          0,           0,        -1 },
	{ "Brave",    NULL,   NULL,         1 << 0,      0,             0,           0,        -1 },
	{ "librewolf",    NULL,   NULL,         1 << 0,      0,             0,           0,        -1 },
	{ "LibreWolf", NULL,  NULL,         1 << 0,      0,             0,           0,        -1 },
	{ "chromium", NULL,  NULL,         1 << 0,      0,             0,           0,        -1 },
	{ "GZDoom",    NULL,  NULL,         1 << 1,      0,             0,           0,        -1 },
	{ NULL, NULL, "Virtual Machine Manager",         1 << 7,      0,             0,           0,        -1 },
	{ "Signal",   NULL,   NULL,         1 << 6,      0,             0,           0,        -1 },
	{ "Syncthing GTK",   NULL,   NULL,         1 << 2,      0,             0,           0,        -1 },
	{ "telegram-desktop",   NULL,   NULL,         1 << 4,      0,             0,           0,        -1 },
	{ "TelegramDesktop",   NULL,   NULL,         1 << 4,      0,             0,           0,        -1 },
  { "minecraft-launcher",     NULL,   NULL,         1 << 1,      0,             0,           0,        -1 },
  { "libreoffice", NULL, NULL,        1 << 2,      0,             0,           0,        -1 },
  { "qbittorrent", NULL, NULL,        1 << 2,      0,             0,           0,        -1 },
  { "Heroic Games Launcher", NULL, NULL, 1 << 1,   0,             0,           0,        -1 },
  { "ollama-float",          NULL, NULL, 0, 1, 0, 0, -1 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
  { "[M]",      monocle },
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *termcmd[]  = { "st", NULL };
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_nero, "-nf", col_grigio, "-sb", col_ciano, "-sf", col_bianco, NULL };

static const char *librewmd[]         = { "librewolf", NULL };
static const char *pcmanfmmd[]        = { "pcmanfm", NULL };
static const char *libreofficemd[]    = { "libreoffice", "--nologo", NULL };
static const char *screenshotmd[]     = { "flameshot", "gui", NULL };
static const char *obsmd[]            = { "obs", NULL };
static const char *virtmanager[]      = { "virt-manager", NULL };
static const char *slockmd[]          = { "slock", NULL };
static const char *passmenu[]         = { "passmenu", NULL };
static const char *nvimcmd[]          = { "st", "-e", "nvim", NULL };
static const char *signalmd[]         = { "signal-desktop", NULL };
static const char *telegram_cmd[]     = { "telegram-desktop", NULL };

static const char *gzdoom[]           = { "prime-run", "gzdoom", NULL };
static const char *discord[]          = { "discord", NULL };
static const char *steamcmd[]         = { "steam", NULL };
static const char *nvidia[]           = { "nvidia-settings", NULL };
static const char *assist_ollama[]    = { "assist_ollama.sh", NULL };
static const char *syncthing[]        = { "syncthing-gtk", NULL };

static const char *greek[]            = { "greekleters.sh", NULL };

static const char *get_vol[]          = { "volume.sh", "show", NULL };
static const char *get_light[]        = { "get-light.sh", NULL };
static const char *next_Notif         = { "notify-send", NULL };

static const char *nextSong[]         = { "mpc", "next", NULL };
static const char *pauseSong[]        = { "mpc", "toggle", NULL };
static const char *prevSong[]         = { "mpc", "prev", NULL };

static const char *mpd_volume[]       = { "mpd-volume.sh", NULL };
static const char *mpd_volume_up[]    = { "mpc", "volume", "+5", NULL };
static const char *mpd_volume_down[]  = { "mpc", "volume", "-5", NULL };

static const char *pauseSong2[]       = { "pause_song.sh", NULL };

// For laptop
/*static const char *light_down[]       = { "light", "-U", "5", NULL };*/
/*static const char *light_up[]         = { "light", "-A", "5", NULL };*/

// For pc
static const char *light_down[]       = { "brightness-down.sh", NULL };
static const char *light_up[]         = { "brightness-up.sh", NULL };

static const char *upvol[]   = { "/usr/bin/pactl", "set-sink-volume", "0", "+5%",     NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "0", "-5%",     NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute",   "0", "toggle",  NULL };


static Key keys[] = {
	/* modifier                     key        function        argument */

  // For light


	{ 0,                       XF86XK_AudioNext, spawn, {.v = nextSong } },
	{ 0,                       XF86XK_AudioPlay, spawn, {.v = pauseSong } },
	{ 0,                       XF86XK_AudioPrev, spawn, {.v = prevSong   } },

  { 0,                       XK_F7, spawn, {.v = get_vol } },
	{ 0,                       XK_F7, spawn, {.v = downvol } },

	{ 0,                       XK_F6, spawn, {.v = get_vol } },
	{ 0,                       XF86XK_AudioMute,        spawn, {.v = mutevol } },

	{ 0,                       XK_F8, spawn, {.v = get_vol } },
	{ 0,                       XK_F8, spawn, {.v = upvol   } },


  // For mpv song status
	{ 0,                       XF86XK_AudioNext, spawn, {.v = pauseSong2 } },
	{ 0,                       XF86XK_AudioPlay, spawn, {.v = pauseSong2 } },
	{ 0,                       XF86XK_AudioPrev, spawn, {.v = pauseSong2   } },

	{ 0,                       XK_F6,        spawn, {.v = get_vol } },
	{ 0,                       XK_F6,        spawn, {.v = mutevol } },

	{ 0,                       XK_F4,        spawn, {.v = mpd_volume } },
	{ 0,                       XK_F4,        spawn, {.v = mpd_volume_down } },

	{ 0,                       XK_F5,        spawn, {.v = mpd_volume } },
	{ 0,                       XK_F5,        spawn, {.v = mpd_volume_up } },

	{ 0,                       XK_F10,        spawn, {.v = pauseSong } },
	{ 0,                       XK_F10,        spawn, {.v = pauseSong2 } },
	{ 0,                       XK_F9,         spawn, {.v = prevSong } },
	{ 0,                       XK_F11,        spawn, {.v = nextSong } },


	/*Custom keybinds for spawning apps*/
//	{ MODKEY,                       XK_q,  spawn,          		 {.v = lightmd } },
	{ MODKEY,                       XK_e,  spawn,          		 {.v = nvimcmd } },
	{ MODKEY,                       XK_n,  spawn,          		 {.v = nvidia } },
	{ MODKEY|ShiftMask,             XK_s,  spawn,          		 {.v = steamcmd } },

	//{ MODKEY|ShiftMask,             XK_z,  spawn,          		 {.v = dunst_closea } },


	{ MODKEY|ShiftMask,             XK_o,  spawn,          		 {.v = syncthing } },
//	{ MODKEY|ShiftMask,             XK_o,  spawn,          		 {.v = assist_ollama } },
	{ MODKEY,                       XK_g,  spawn,          		 {.v = gzdoom } },
	{ MODKEY|ShiftMask,             XK_Tab,  spawn,          	 {.v = passmenu } },
  { MODKEY|ShiftMask,             XK_p,  spawn,          	   {.v = slockmd } },
  { MODKEY,                       XK_s,  spawn,          	   {.v = screenshotmd } },

	{ MODKEY|ShiftMask,             XK_a,  spawn,              {.v = signalmd } },
	{ MODKEY,                       XK_o,  spawn,         	   {.v = obsmd } },
	{ MODKEY,                       XK_v,  spawn,          		 {.v = virtmanager } },
  { MODKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_r,      spawn,          {.v = greek } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
  { MODKEY,                       XK_p,      spawn,          {.v = librewmd } },
  { MODKEY,                       XK_t,      spawn,          {.v = pcmanfmmd } },
  { MODKEY,                       XK_i,      spawn,          {.v = libreofficemd } },
  { MODKEY,                       XK_d,      spawn,          {.v = discord } },

	/*Movement keys*/
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_l,      incnmaster,     {.i = -1 } },
	{ MODKEY,			                  XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,					              XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
/*	{ MODKEY,                     XK_alt,    view,           {0} },*/
	{ MODKEY,                       XK_w,      killclient,     {0} },

	/*For layouts*/
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_Tab,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

  /*For incrementing gaps*/
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	TAGKEYS(                        XK_9,                      8)
  /*  { MODKEY,                       XK_p,      spawn,      {.v = &layouts[2]} },*/
};
/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

void
setlayoutex(const Arg *arg)
{
	setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

void
viewex(const Arg *arg)
{
	view(&((Arg) { .ui = 1 << arg->ui }));
}

void
viewall(const Arg *arg)
{
	view(&((Arg){.ui = ~0}));
}

void
toggleviewex(const Arg *arg)
{
	toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagex(const Arg *arg)
{
	tag(&((Arg) { .ui = 1 << arg->ui }));
}

void
toggletagex(const Arg *arg)
{
	toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagall(const Arg *arg)
{
	tag(&((Arg){.ui = ~0}));
}

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum           function */
	{ "focusstack",     focusstack },
	{ "setmfact",       setmfact },
	{ "togglebar",      togglebar },
	{ "incnmaster",     incnmaster },
	{ "togglefloating", togglefloating },
	{ "focusmon",       focusmon },
	{ "tagmon",         tagmon },
	{ "zoom",           zoom },
	{ "view",           view },
	{ "viewall",        viewall },
	{ "viewex",         viewex },
	{ "toggleview",     view },
	{ "toggleviewex",   toggleviewex },
	{ "tag",            tag },
	{ "tagall",         tagall },
	{ "tagex",          tagex },
	{ "toggletag",      tag },
	{ "toggletagex",    toggletagex },
	{ "killclient",     killclient },
	{ "quit",           quit },
	{ "setlayout",      setlayout },
	{ "setlayoutex",    setlayoutex },
};
