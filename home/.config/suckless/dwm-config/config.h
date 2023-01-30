/*
* __  __       _   _   _                                _
*|  \/  | __ _| |_| |_(_) ___         ___ _ __ ___   __| |
*| |\/| |/ _` | __| __| |/ _ \ _____ / __| '_ ` _ \ / _` |
*| |  | | (_| | |_| |_| | (_) |_____| (__| | | | | | (_| |
*|_|  |_|\__,_|\__|\__|_|\___/       \___|_| |_| |_|\__,_|
*/
#include <X11/XF86keysym.h>

static const char *upvol[]   = { "/usr/bin/pactl", "set-sink-volume", "0", "+5%",     NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "0", "-5%",     NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute",   "0", "toggle",  NULL };


/* appearance */
static unsigned int borderpx  = 0;        /* border pixel of windows */
static unsigned int snap      = 32;       /* snap pixel */
static int showbar            = 1;        /* 0 means no bar */
static int topbar             = 1;        /* 0 means bottom bar */
static const unsigned int gappx     = 12;        /* gaps between windows */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int user_bh            = 30;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height (normally at 34)*/
static const int vertpad            = 0;       /* vertical padding of bar  10*/ //8
static const int sidepad            = 0;       /* horizontal padding of bar  12*/ //8
static const char *fonts[]          = { "Iosevka Nerd Font:size=14", "Material Design Icons-Regular:size=10" };  // If tags icons dont work, just install mononoki font and use it OR just install anonymous pro nerd font from the aur and you should be fine really
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=17";


static char normbgcolor[]           = "#000000";
static char normbordercolor[]       = "#000000";
static char normfgcolor[]           = "#fbf1c7"; //inactive border
static char selfgcolor[]            = "#000000";
static char selbordercolor[]        = "#a89984"; //315025
static char selbgcolor[]            = "#a89984";

static const char black[]           = "#000000";
static const char blue[]            = "#458588";
static const char yellow[]          = "#fabd2f";
static const char pink[]            = "#d3869b";
static const char white[]           = "#ffffff";
static const char white_gruv[]      = "#fbf1c7";
static const char red[]             = "#fb4934";
static const char purple[]          = "#83a598";
static const char green[]           = "#8ec07c";
static const char orange[]          = "#fe8019";
static const char gray2[]           = "#a89984";
static const char gray3[]           = "#928374";
static const char scheme_tag_c[]    = "#879C78";
static const int colorfultag        = 0;  /* 0 means use SchemeSel for selected non vacant tag */
/*For dmenu*/
static const char dmenu_prompt[]    = "Run"; /*dmenu promt*/
//static const char col_sb[]			    = "#8ec07c"; /*colo for the selected foreground in dmenu*/
static const char col_sf[]			    = "#000000"; /*colo for the selected foreground in dmenu*/
static const char col_border[]      = "#fbf1c7"; /*Color for the cool accents*/
static const char col_nf[]          = "#fbf1c7"; /*Color for the cool accents*/
static const char numb_columns[]    = "4"; /*Number of columns for the grid in dmenu*/
static const char numb_lines[]      = "4"; /*Number of lines for the grid in dmenu*/

static const char *colors[][3]      = {
	/*               fg         bg         border   */

  //[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
  [SchemeSel]  = { col_border,  normbgcolor,  selbordercolor  },

  /*[TabSel]           = { blue, gray2,  black  },*/
  /*[TabNorm]          = { gray3, black, black },*/

  [SchemeTag]        = { scheme_tag_c, black, black },
  [SchemeTag1]       = { white_gruv, black, black },
  [SchemeTag2]       = { white_gruv, black, black },
  [SchemeTag3]       = { white_gruv, black,black  },
  [SchemeTag4]       = { white_gruv, black, black },
  [SchemeTag5]       = { white_gruv, black, black },
  [SchemeTag6]       = { white_gruv, black, black },
  [SchemeTag7]       = { white_gruv, black, black },
  [SchemeTag8]       = { white_gruv, black, black },
  [SchemeTag9]       = { white_gruv, black, black },
  [SchemeLayout]     = { scheme_tag_c, black, black },
  /*[SchemeBtnPrev]    = { white_gruv, black, black },*/
  /*[SchemeBtnNext]    = { yellow, black, black },*/
  /*[SchemeBtnClose]   = { red, black, black },*/
};

/*
This are just some of the icons i may use idk




























♫





*/

static const char *const autostart[] = {
  //"themechanger.sh", NULL,
  "killall", "picom", "dunst", "mpd", "xsnow"
  "light", "-S", "30", NULL,
  "picom", "--no-fading-openclose", NULL,
  "dunst", "&", NULL,
  "autostart.sh", NULL,
  "setxkbmap" "-layout" "us,es" "-variant" "qwerty" "-option" "grp:alt_space_toggle" "&", NULL,
  "eww", "daemon", "&", NULL,
  "mpd", "&", NULL,
  "notify_log.sh", "/home/mattio/.log/notify.log", "&", NULL,
  "pipewire_start.sh", "&", NULL,
  "nitrogen", "--restore", NULL,
  "xrdb", "/home/mattio/.Xresources", NULL,
  "xsnow", "-notrees", "&", NULL,
	NULL /* terminate */
};

/* tagging */
//static const char *tags[] = { " " , " ", " ", "ﭮ ", " ", " ", " ", " ", " "};
//static const char *tags[] = { "⬤" , "⬤ ", "⬤ ", "⬤ ", "⬤ ", "⬤ ", "⬤ ", "⬤ ", "⬤ "};
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
//static const char *tags[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
//static const char *tags[] = { "www", "dev", "doc", "chat", "mus", "gaming", "sig", "kvm", "obs" };
/*static const char *tags[] = { "", "", "", "", "", "", "", "", "" };*/
/*static const char *tags[] = { "", "", "", "4", "5", "6", "7", "8", "ﭮ" };*/
/*static const char *tags[] = { " ", " ", " ", " ", " ", "  ", " ", " ", " " };*/

static const int tagschemes[] = { SchemeTag1, SchemeTag2, SchemeTag3,
                                  SchemeTag4, SchemeTag5, SchemeTag6,
                                  SchemeTag7, SchemeTag8, SchemeTag9
                                };

static const char *tagsel[][2] = {
	{ "#fe8019", "#000000" },
	{ "#8ec07c", "#000000" },
	{ "#d3869b", "#000000" },
	{ "#458588", "#000000" },
	{ "#fabd2f", "#000000" },
	{ "#4b0082", "#000000" },
	{ "#fb4934", "#000000" },
	{ "#ffffff", "#000000" },
	{ "#a89984", "#000000" },
};

static const unsigned int ulinepad	= 4;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",	    NULL,   NULL,           1 << 2,         0,             0,           0,        -1 },
	{ "firefox",  NULL,   NULL,           1 << 0,    0,             0,          -1,        -1 },
	{ "St",		    NULL,   NULL,           0,         0,             1,           0,        -1 },
	{ "Alacritty", NULL,  NULL,           0,         0,             1,           0,        -1 },
	{ NULL,		    NULL,   "Event Tester", 0,         0,             0,           1,        -1 }, /* xev */
	{ "Lutris",   NULL,   NULL,         1 << 1,      0,             0,           0,        -1 },
	{ "discord",  NULL,   NULL,         1 << 3,      0,		          0,           0,        -1 },
	{ "War Thunder (Vulkan, 64bit)",  NULL,   NULL,         1 << 5,      0,		          0,           0,        -1 },
	{ "Steam",    NULL,   NULL,         1 << 5,      0,	            0,           0,        -1 },
	{ "obs",      NULL,   NULL,         1 << 8,      0,		          0,           0,        -1 },
	{ "Brave",    NULL,   NULL,         1 << 0,      0,             0,           0,        -1 },
	{ "librewolf",    NULL,   NULL,         1 << 0,      0,             0,           0,        -1 },
	{ "LibreWolf", NULL,  NULL,         1 << 0,      0,             0,           0,        -1 },
	{ "GZDoom",    NULL,  NULL,         1 << 1,      0,             0,           0,        -1 },
	{ NULL, NULL, "Virtual Machine Manager",         1 << 7,      0,             0,           0,        -1 },
	{ "Signal",   NULL,   NULL,         1 << 6,      0,             0,           0,        -1 },
  { "ncmpcpp",     NULL,   NULL,         1 << 4,      0,             0,           0,        -1 },
  { "minecraft-launcher",     NULL,   NULL,         1 << 1,      0,             0,           0,        -1 },
  { "Minecraft* 1.19.2",     NULL,   NULL,         1 << 1,      0,             0,           0,        -1 },
  { "libreoffice", NULL, NULL,        1 << 2,      0,             0,           0,        -1 },
  { "qbittorrent", NULL, NULL,        1 << 2,      0,             0,           0,        -1 },
  { "Planner", NULL, NULL,        1 << 2,      0,             0,           0,        -1 },
  { "Heroic Games Launcher", NULL, NULL, 1 << 1,   0,             0,           0,        -1 },
};

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
/*0*/	{ "[]= ",   tile    },    /* first entry is default */
/*1*/	{ "[M] ",   monocle },
/*2*/	{ "><> ",   NULL    },    /* no layout function means floating behavior */
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

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *eww_opensidecard[]  = { "eww_opensidecard", NULL };
static const char *eww_opendashboard[] = { "eww_opendashboard.sh", NULL };
static const char *termcmd[]          = { "st", NULL };
static const char *rofi_launchermd[]  = { "launcher_rofi.sh", NULL };
//static const char *termcmd[]          = { "alacritty", NULL };
static const char *librewmd[]         = { "librewolf", NULL };
static const char *pcmanfmmd[]        = { "pcmanfm", NULL };
static const char *libreofficemd[]    = { "libreoffice", "--nologo", NULL };
static const char *screenshotmd[]     = { "xfce4-screenshooter", NULL };
static const char *obsmd[]            = { "obs", NULL };
static const char *virtmanager[]      = { "virt-manager", NULL };
static const char *slockmd[]          = { "slock", NULL };
static const char *killxorgmd[]       = { "killall Xorg", NULL };
static const char *dmenu_networkmd[]  = { "networkmanager_dmenu", NULL };
static const char *steam[]            = { "steam", NULL };
static const char *keyboar_lay[]      = { "layout_changer.sh", NULL };
static const char *lightmd[]          = { "sh", "/home/mattio/.config/dwm-6.2/startup.sh", NULL };
static const char *gzdoom[]           = { "gzdoom", NULL };
//static const char *discord[]  = { "discord", NULL };
static const char *discord[]          = { "discord_start.sh", NULL };
static const char *passmenu[]         = { "passmenu", NULL };
static const char *nvimcmd[]          = { "st", "-e", "nvim", NULL };
static const char *signalmd[]         = { "signal-desktop", NULL };
static const char *steamcmd[]         = { "steam", NULL };
static const char *cmuscmd[]          = { "st", "-e", "ncmpcpp", NULL };
static const char *nvidia[]           = { "nvidia-settings", NULL };
static const char *planner[]          = { "planner", NULL };
static const char *greek[]            = { "greekleters.sh", NULL };
static const char *plans[]            = { "zathura", "~/Documents/lista/test.pdf", NULL };
static const char *get_vol[]          = { "get-volume.sh", NULL };
static const char *get_light[]        = { "get-light.sh", NULL };
static const char *next_Notif         = { "notify-send", NULL };

static const char *dunst_closea[]     = { "dunstctl", "close-all", NULL };
static const char *dunst_hist[]       = { "dunstctl", "history-pop", NULL };

static const char *kill_eww[]       = { "killall", "eww", NULL };

static const char *control_center[]   = { "eww_not_center.sh", NULL };

static const char *nextSong[]         = { "mpc", "next", NULL };
static const char *pauseSong[]        = { "mpc", "toggle", NULL };
static const char *prevSong[]         = { "mpc", "prev", NULL };

static const char *mpd_volume[]       = { "mpd-volume.sh", NULL };
static const char *mpd_volume_up[]    = { "mpc", "volume", "+5", NULL };
static const char *mpd_volume_down[]  = { "mpc", "volume", "-5", NULL };

static const char *pauseSong2[]       = { "pause_song.sh", NULL };

static const char *light_down[]       = { "light", "-U", "5", NULL };
static const char *light_up[]         = { "light", "-A", "5", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */

  // For light
  { 0,                       XK_F2, spawn, {.v = light_down } },
	{ 0,                       XK_F2, spawn, {.v = get_light } },

  { 0,                       XK_F3, spawn, {.v = light_up } },
	{ 0,                       XK_F3, spawn, {.v = get_light } },

	{ 0,                       XF86XK_AudioNext, spawn, {.v = nextSong } },
	{ 0,                       XF86XK_AudioPlay, spawn, {.v = pauseSong } },
	{ 0,                       XF86XK_AudioPrev, spawn, {.v = prevSong   } },

	{ 0,                       XF86XK_AudioLowerVolume, spawn, {.v = downvol } },
	{ 0,                       XF86XK_AudioMute,        spawn, {.v = mutevol } },
	{ 0,                       XF86XK_AudioRaiseVolume, spawn, {.v = upvol   } },

	/*{ 0,                       XF86XK_AudioNext, spawn, {.v = next_Notif } },*/
	/*{ 0,                       XF86XK_AudioPlay, spawn, {.v = pause_Notif } },*/
	/*{ 0,                       XF86XK_AudioPrev, spawn, {.v = prev_Notif  } },*/

	{ 0,                       XF86XK_AudioLowerVolume, spawn, {.v = get_vol } },
	{ 0,                       XF86XK_AudioMute,        spawn, {.v = get_vol } },
	{ 0,                       XF86XK_AudioRaiseVolume, spawn, {.v = get_vol   } },

  // For mpv song status
	{ 0,                       XF86XK_AudioNext, spawn, {.v = pauseSong2 } },
	{ 0,                       XF86XK_AudioPlay, spawn, {.v = pauseSong2 } },
	{ 0,                       XF86XK_AudioPrev, spawn, {.v = pauseSong2   } },

	{ 0,                       XK_F6,        spawn, {.v = get_vol } },
	{ 0,                       XK_F6,        spawn, {.v = mutevol } },

	{ 0,                       XK_F7,        spawn, {.v = mpd_volume } },
	{ 0,                       XK_F7,        spawn, {.v = mpd_volume_down } },

	{ 0,                       XK_F8,        spawn, {.v = mpd_volume } },
	{ 0,                       XK_F8,        spawn, {.v = mpd_volume_up } },

	{ 0,                       XK_F10,        spawn, {.v = pauseSong } },
	{ 0,                       XK_F10,        spawn, {.v = pauseSong2 } },
	{ 0,                       XK_F9,         spawn, {.v = prevSong } },
	{ 0,                       XK_F11,        spawn, {.v = nextSong } },


	{ MODKEY,                       XK_space,  spawn,          {.v = keyboar_lay } },

	/*Custom keybinds for spawning apps*/
	{ MODKEY,                       XK_q,  spawn,          		 {.v = lightmd } },
	{ MODKEY,                       XK_e,  spawn,          		 {.v = nvimcmd } },
	{ MODKEY,                       XK_n,  spawn,          		 {.v = nvidia } },
	{ MODKEY,                       XK_q,  spawn,          		 {.v = planner } },
	{ MODKEY,                       XK_a,  spawn,          		 {.v = eww_opensidecard } },
	{ MODKEY,                       XK_space,  spawn,      		 {.v = eww_opendashboard } },
	{ MODKEY|ShiftMask,             XK_s,  spawn,          		 {.v = steamcmd } },
	{ MODKEY,                       XK_q,  spawn,          		 {.v = plans } },
	{ MODKEY|ShiftMask,             XK_z,  spawn,          		 {.v = kill_eww} },

	{ MODKEY,                       XK_z,  spawn,          		 {.v = control_center } },
	//{ MODKEY|ShiftMask,             XK_z,  spawn,          		 {.v = dunst_closea } },


	{ MODKEY,                       XK_g,  spawn,          		 {.v = gzdoom } },
	{ MODKEY|ShiftMask,             XK_Tab,  spawn,          	 {.v = passmenu } },
	{ MODKEY,                       XK_n,  spawn,          		 {.v = dmenu_networkmd } },
	{ MODKEY,                       XK_x,  spawn,         		 {.v = killxorgmd } },
  { MODKEY|ShiftMask,             XK_p,  spawn,          	   {.v = slockmd } },
  { MODKEY,                       XK_s,  spawn,          	   {.v = screenshotmd } },

	{ MODKEY|ShiftMask,             XK_a,  spawn,              {.v = signalmd } },
	{ MODKEY,                       XK_o,  spawn,         	   {.v = obsmd } },
	{ MODKEY,                       XK_v,  spawn,          		 {.v = virtmanager } },
	{ MODKEY,              					XK_c,  spawn,          		 {.v = cmuscmd } },
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
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_Tab,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	/*For incrementing gaps n stuff*/
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
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

/*
 * Xresources preferences to load at startup
 */

ResourcePref resources[] = {
		{ "normbgcolor",        STRING,  &normbgcolor },
		{ "normbordercolor",    STRING,  &normbordercolor },
		{ "normfgcolor",        STRING,  &normfgcolor },
		{ "selbgcolor",         STRING,  &selbgcolor },
		{ "selbordercolor",     STRING,  &selbordercolor },
		{ "selfgcolor",         STRING,  &selfgcolor },
		{ "borderpx",          	INTEGER, &borderpx },
		{ "snap",          		INTEGER, &snap },
		{ "showbar",          	INTEGER, &showbar },
		{ "topbar",          	INTEGER, &topbar },
		{ "nmaster",          	INTEGER, &nmaster },
		{ "resizehints",       	INTEGER, &resizehints },
		{ "mfact",      	 	FLOAT,   &mfact },
};
