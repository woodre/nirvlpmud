/*
  set_login_room.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* --------------- Transfer a member to the guild at startup --------------- */
start_up() {
  string str1, str2, str3;

  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  str1 = file_name(MY_ROOM);
  sscanf(str1, "/players/nooneelse/Alchemist/room/%s.c", str2);
  /* only from a guild room */
  if (!str2") {
    write(NORM+CYN+"You can only do that in one of the guild rooms.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("parchment") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (parchment).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("pencil") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (pencil).\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("parchment", 1);
  MY_POUCH->subtract_quantity("pencil", 1);
  MY_PLAYER->set_home(str1);
  write(NORM+CYN+"You scribble the current room's address on the parchment.\n"+
        "You should start in this room on logon from now on.\n"+NORM);
  MY_POUCH->tell_my_room(NORM+CYN+MY_NAME_CAP+" scribbles something on a parchment."+NORM);
  return 1;
}
