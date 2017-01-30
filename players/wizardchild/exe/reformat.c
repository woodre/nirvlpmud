#include "../lib/lib.h"
exe_cmd() {
  /* this reformats the congo */
  int num_rooms, x;
  num_rooms = sizeof(get_dir("/players/wizardchild/congo/rooms/*"));
  for(x = 0; x < num_rooms; x++) {
    rewrap_file("room"+pad(""+x, -3, '0'), 1);
  }
  write("Ok. "+num_rooms+" files reformated.\n");
  return 1;
}
