#include "webview.h"

struct _RoseWebView {
	WebKitWebView parent_instance;

	GCancellable *cancellable;
	RoseWebViewNavigationFlags navigation;

	char *address;
};

enum {
	LAST_PROP,
	PROP_NAVIGATION,
	PROP_ADDRESS
};

static GParamSpec *obj_properties[LAST_PROP];

G_DEFINE_TYPE(RoseWebView, rose_webview, WEBKIT_TYPE_WEB_VIEW)

static void update_navigation_flags(RoseWebView *webview)
{
	guint flags = 0;
	if (webkit_web_view_can_go_back(WEBKIT_WEB_VIEW(webview)))
		flags |= ROSE_WEBVIEW_NAV_BACK;

	if (webkit_web_view_can_go_forward(WEBKIT_WEB_VIEW(webview)))
		flags |= ROSE_WEBVIEW_FORWARD;

	if (webview->navigation != (RoseWebViewNavigationFlags) flags) {
		webview->navigation = (RoseWebViewNavigationFlags) flags;
		g_object_notify_by_pspec(G_OBJECT(webview), obj_properties[PROP_NAVIGATION]);
	}
}

static void rose_webview_constructed(GObject *object)
{
	RoseWebView *webview = ROSE_WEBVIEW(object);
	g_auto(GStrv) cors_allowlist = NULL;
	GtkStyleContext *context;
	GdkRGBA color;

	G_OBJECT_CLASS(rose_webview_parent_class)->constructed (object);

	g_signal_connect_swapped(webkit_web_view_get_back_forward_list(WEBKIT_WEB_VIEW(webview)),
                           "changed", G_CALLBACK(update_navigation_flags), webview);

	context = gtk_widget_get_style_context(GTK_WIDGET(webview));

	if (gtk_style_context_lookup_color(context, "theme_base_color", &color))
		webkit_web_view_set_background_color(WEBKIT_WEB_VIEW(webview), &color);

	cors_allowlist = g_new(char*, 2);
	cors_allowlist[0] = g_strdup("rose-resource://*/*");
	cors_allowlist[1] = NULL;

	webkit_web_view_set_cors_allowlist(WEBKIT_WEB_VIEW(webview), (const char* const *) cors_allowlist);
}

static void rose_webview_dispose(GObject *object)
{
	RoseWebView *webview = ROSE_WEBVIEW(object);

	if (webview->cancellable) {
		g_cancellable_cancel(webview->cancellable);
		g_clear_object(&webview->cancellable);
	}

	G_OBJECT_CLASS(rose_webview_parent_class)->dispose (object);
}

static void rose_webview_finalize(GObject *object)
{
	RoseWebView *view = ROSE_WEBVIEW(object);

	g_free(view->address);

	G_OBJECT_CLASS(rose_webview_parent_class)->finalize (object);
}

static void rose_webview_class_init(RoseWebViewClass *class)
{
	GObjectClass *object_class = G_OBJECT_CLASS(class);

	object_class->dispose = rose_webview_dispose;
	object_class->finalize = rose_webview_finalize;
	object_class->constructed = rose_webview_constructed;

	obj_properties[PROP_ADDRESS] =
    g_param_spec_string ("address",
                         "Address",
                         "address",
                         "",
                         G_PARAM_READABLE | G_PARAM_STATIC_STRINGS);
}

static void rose_webview_init(RoseWebView *webview)
{
	gtk_widget_set_overflow(GTK_WIDGET(webview), GTK_OVERFLOW_HIDDEN);
}

void rose_webview_load_url(WebKitWebView *webview, const char *url)
{
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(webview), url);
	setatom(AtomUri, url);
}

void rose_load_changed_callback(WebKitWebView *webview,
																WebKitLoadEvent event)
{
	if (event == WEBKIT_LOAD_FINISHED) {
			const char *uri = webkit_web_view_get_uri(webview);
			char *cookiefile = calloc(1, sizeof(char) * (strlen(options[CACHE]) + 32) + 1);
			sprintf(cookiefile, "%s/history", options[CACHE]);

			FILE *cookie = fopen(cookiefile, "a");

			fprintf(cookie, "%s\n", uri);
			fclose(cookie);
			free(cookiefile);
		}
}

static void rose_download(const char* uri)
{
	char *cmd = calloc(1, sizeof(char) * strlen(uri) + 1);
	char *url = calloc(1, sizeof(char) * strlen(uri) + 1);

	strcpy(url, uri);

	int id = fork();
	if (id == 0) {
		close(spair[0]);
		close(spair[1]);
		setsid();
		char *argv[] = { "/bin/sh", "-c", "st -e /bin/sh -c", "\"aria2c \\", cmd, "\"", NULL };
		execvp("/bin/sh", argv);
		perror(" failed");
		exit(1);
	}
}

static void rose_response_reciver(WebKitDownload *download,
                                  GParamSpec *pspec)
{
	const char *uri = webkit_uri_response_get_uri(webkit_download_get_response(download));

	rose_download(uri);
}

static void rose_download_callback(WebKitWebContext *context,
                                   WebKitDownload *download)
{
		g_signal_connect(G_OBJECT(download), "notify::response",
	                 G_CALLBACK(rose_response_reciver), NULL);
}

GtkWidget* rose_webview_new()
{
	char cookiefile[128];
	WebKitWebView *webview;
	WebKitCookieManager *cookiemanager;
	WebKitUserContentManager *contentmanager;

	WebKitSettings *settings = webkit_settings_new_with_settings(
		"auto-load-images", TRUE,
		"enable-back-forward-navigation-gestures", TRUE,
		"enable-developer-extras", TRUE,
		"enable-media-stream", TRUE,
		"enable-plugins", FALSE,
		"enable-dns-prefetching", TRUE,
		"enable-smooth-scrolling", TRUE,
		"media-content-types-requiring-hardware-support", "video:/mp4;codecs=\"H.264-encoded\"",
		"hardware-acceleration-policy", WEBKIT_HARDWARE_ACCELERATION_POLICY_ALWAYS,
		"javascript-can-access-clipboard", TRUE, NULL);

	if (!options[CACHE]) {
		const char *HOME = getenv("HOME");
		char *buf = calloc(1, sizeof(char) * (strlen(HOME) + 32) + 1);
		sprintf(buf, "%s/.cache/rose/", HOME);
		options[CACHE] = buf;
	}

	WebKitWebContext *context = webkit_web_context_new_with_website_data_manager(
		webkit_website_data_manager_new(
		"base-cache-directory", options[CACHE],
		"base-data-directory", options[CACHE],
		NULL));

	webkit_settings_set_user_agent_with_application_details(
		settings, "Mini", "0.1");

	webkit_web_context_set_cache_model(context, WEBKIT_CACHE_MODEL_WEB_BROWSER);
	contentmanager = webkit_user_content_manager_new();
	cookiemanager = webkit_web_context_get_cookie_manager(context);

	strcpy(cookiefile, options[CACHE]);
	strcat(cookiefile, "cookies");

	webkit_cookie_manager_set_persistent_storage(cookiemanager,
		cookiefile, WEBKIT_COOKIE_PERSISTENT_STORAGE_SQLITE);

	webkit_cookie_manager_set_accept_policy(cookiemanager, WEBKIT_COOKIE_POLICY_ACCEPT_ALWAYS);

	g_signal_connect(G_OBJECT(context), "download-started",
		                 G_CALLBACK(rose_download_callback), NULL);

	return 	g_object_new(
			WEBKIT_TYPE_WEB_VIEW,
			"settings", settings,
			"user-content-manager", contentmanager,
			"web-context", context, NULL);
}
