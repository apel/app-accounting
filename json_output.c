#include "server.h"

static bool g_open_brace  = false;
static bool g_first_node  = true;
static bool g_first_child = true;

void
json_close_previous()
{
    if (g_open_brace) {
        printf("}");
    }
    g_open_brace = false;
}

void
json_start()
{
    printf("{");
    g_first_node = true;
}

void
json_end()
{
    json_close_previous();
    printf("}\n");
}

void
json_node(char *name)
{
    json_close_previous();
    if (!g_first_node) {
        printf(", ");
    }
    g_first_node = false;
    g_first_child = true;
    printf("\"%s\": ", name);
}

void
json_text(char *text)
{
    printf("\"%s\"", text);
}

void
json_child_node(char *name, char *text)
{
    if (!g_open_brace) {
        printf("{");
    }
    g_open_brace = true;
    if (!g_first_child) {
        printf(", ");
    }
    g_first_child = false;
    printf("\"%s\": \"%s\"", name, text);
}

