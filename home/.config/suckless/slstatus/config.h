/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;
/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cpu_perc            cpu usage in percent            NULL
 * cpu_freq            cpu frequency in MHz            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/")
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * separator           string to echo                  NULL
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 *                                                     NULL on OpenBSD
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 */
static const struct arg args[] = {
	/* function format          argument */
	//{ datetime, "%s",           "%F %T" },
	//{ wifi_perc, "W: (%3s%% on ", "wlp8s0" },

   /*{ netspeed_rx, "%sB/s  ", "enp0s3" }, */
/*	{ run_command, " [", NULL },*/
/*	{ separator, "%s", "[" },*/
/*	{ separator, "%s", "[" },*/
  {  disk_free,   "^c#000000^ %4s "        ,  "/"    }, // DO NOT DELETE, IT FIXES THE CPU BUG
//  { battery_perc, "^b#000000^^c#fabd2f^  ^b#000000^^c#fabd2f^%s ", "BAT1" },

//  { cpu_perc, "^b#000000^^c#d49191^  ^c#d49191^ %s%%", NULL	      }, /*funny color 4f5040*/
  /*{ cpu_perc, "^b#cc241d^^c#000000^  ^b#000000^ ^c#cc241d^ %s%%", NULL	      }, [>funny color 4f5040<]*/
  /*{ separator,           "^c#fbf1c7^|",                  NULL },*/
 // { ram_used, "^c#d7b788^ ^b#000000^  ^c#d7b788^ ^b#000000^ %s", NULL	      },
  /*{ separator,           "^c#fbf1c7^|",                  NULL },*/
  //!!!!!!!!!!!

//VOLUMEN  { run_command, "^c#cc241d^ ^b#000000^  ^c#cc241d^ ^b#000000^%4s", "pamixer --get-volume" },

  /*{ separator,           "^c#fbf1c7^|",                  NULL },*/
  /*{ separator,           "^b#000000^ ^c#83a598^",                  NULL },*/
{ keymap, "^c#83a598^ ^b#000000^  ^c#83a598^ ^b#000000^ %s ", "it us es" },
  /*{ separator,           "^c#fbf1c7^|",                  NULL },*/
	{ datetime, "^b#000000^ ^c#87ceeb^  ^b#000000^ ^c#87ceeb^%s", "%a %b %d %H:%M:%S  " }, //"%a %b %d %H:%M:%S
};

  /*{ separator,           "^c#458588^",                  NULL },*/
	/*{ datetime, "^b#689d6a^ ^c#000000^  ^b#8ec07c^ ^c#000000^%s",           "%a %b %d %r" },*/
  /*{ cpu_perc, "^c#8ec07c^   %s%% ", NULL	      },*/
  /*{ separator,           "^c#fbf1c7^|",                  NULL },*/
  /*{ ram_used, "^c#cc241d^   %s ", NULL	      }, [><]*/
  /*{ separator,           "^c#fbf1c7^|",                  NULL },*/
  /*{  disk_free,   "^c#fabd2f^ %4s "        ,  "/"    },*/
  /*{ separator,           "^c#fbf1c7^|",                  NULL },*/
  /*{ run_command, "^c#458588^  %4s ", "pamixer --get-volume" },*/
  /*{ separator,           "^c#fbf1c7^|",                  NULL },*/
	/*{ keymap, "^c#8ec07c^    %s ", " us es" }, */
  /*{ separator,           "^c#fbf1c7^|",                  NULL },*/
	/*{ datetime, "^c#cc241d^   %s",           "%a %b %d %r" },*/
/*};*/

/**/
/*{ separator,           "^c#fbf1c7^|",                  NULL },*/
/*{  disk_free,   "^c#83a598^  ^c#a89984^ %4s "        ,  "/"    },*/
