#include <stdio.h>
#include <gio/gio.h>
#include <glib.h>

int main(int argc, char *argv[]) {
  GFile *f;
  char *uri;
  GError *error = NULL;
  GAppLaunchContext *context;
  context = g_app_launch_context_new();

  if (argc != 2) {
    printf("Usage: xdg-open <path>\n");
    return -1;
  }

  // printf("%s\n", argv[1]);
  f = g_file_new_for_commandline_arg (argv[1]);
  uri = g_file_get_uri (f);
  g_app_info_launch_default_for_uri(uri, context, &error);
  return 0;
}
