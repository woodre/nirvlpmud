/*
// /bin/_update.c
//
// Daemonized by Shadowhawk.
*/

#include <security.h>

#pragma strict_types
#pragma save_types

int
cmd_update(string str) {
  string junk;
  object ob;

  if ((int)this_player()->query_level() < CREATE)
    return 0;
  if (!str) {
    write("Update what object ?\n");
    return 1;
  }
  str = resolv_path(this_player()->get_path(), str);
  if (strlen(str) > 2 && sscanf(str, "%s.c", junk))
    str = junk;
  if (str == "/obj/master3044") {
    write("You cannot update /obj/master.c, doing so may crash the game.\n");
    return 1;
  }
  if (str == "/obj/partymaster" && this_player()->query_level() < 99) {
     write("Updating /obj/partymaster may cause problems, you cannot do so.\n");
     return 1;
  }
  str = (string)this_player()->valid_read(str);
  if (!str) {
    write("Invalid file name.\n");
    return 1;
  }
  ob = find_object(str);
  if (!ob) {
    write("No such object.\n");
    return 1;
  }
  destruct(ob);
  write(str + " will be reloaded at next reference.\n");
  return 1;
}
