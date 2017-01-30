#include <security.h>

#pragma strict_types
#pragma save_types

int
cmd_ls(string path) {
  string str;

  if (this_player()->query_level() < EXPLORE)
    return 0;
  str = resolv_path((string)this_player()->get_path(), path);
  if (str == "/players") {
    write("You can't ls in /players.\n");
    return 1;
  }
  write("Files in " + str + ":\n");
  ls(str);
  return 1;
}
