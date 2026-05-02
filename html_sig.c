#include <glib.h>
#include "common/claws.h"
#include "common/version.h"
#include "plugin.h"

gint plugin_init(gchar **error)
{
    g_print("HtmlSigPlugin: Initialized successfully.\n");
    return 0;
}

gboolean plugin_done(void)
{
    g_print("HtmlSigPlugin: Unloaded successfully.\n");
    return TRUE;
}

const gchar *plugin_name(void)
{
    return "HTML Signature Injector";
}

const gchar *plugin_desc(void)
{
    return "PoC Plugin: Detects HTML signatures and converts text/plain to multipart/alternative on the fly.";
}

const gchar *plugin_type(void)
{
    return "GTK3";
}

const gchar *plugin_licence(void)
{
    return "GPL";
}

const gchar *plugin_version(void)
{
    return VERSION;
}

struct PluginFeature *plugin_provides(void)
{
    static struct PluginFeature f[2];
    f[0].type = PLUGIN_UTILITY;
    f[0].name = "HTML Signature";
    f[1].type = PLUGIN_NOTHING;
    f[1].name = NULL;
    return f;
}
