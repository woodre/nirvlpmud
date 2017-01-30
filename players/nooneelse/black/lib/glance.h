/*
  glance.h
*/

#include "defs.h"

/* -------- glance around the room ---------- */
glance() {
  int n;
  string dest_dir;
  object obj;
  if (MY_LEVEL < 1 || MY_GUILD_EXP < 666) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_LEVEL >= 21) write(file_name(MY_ROOM)+"\n");
  write(MY_ROOM->short()+".\n");
  dest_dir = MY_ROOM->query_dest_dir();
  if (sizeof(dest_dir) > 0) {
    if (sizeof(dest_dir)==1)
      write("Exit: ");
    else
      write("Exits: ");
    n=1;
    while (n < sizeof(dest_dir)) {
      write(dest_dir[n]);
      if (n < (sizeof(dest_dir) - 2) && sizeof(dest_dir) > 1) write(", ");
      n++;
      n++;
    }
  }
  else
    write("Exit(s):  The glance command cannot determine "+
          "the exits in this room.\n"+
          "          You'll have to use the look command.");
  write("\n\n");
  obj = first_inventory(MY_ROOM);
  while(obj) {
    if (obj!=MY_PLAYER && !obj->id("vampire mist") && obj->short())
      write(obj->short()+".\n");
    obj = next_inventory(obj);
  }
  return 1;
}
