/*
  tell.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Telepathy - tell all alchemists ---------- */
telepathy(str) {
  int i, n, n2, n3;
  object stuff, curse_obj;
  string who, msg, player_list, junk1, junk2;

  if (!str) {
    write(NORM+CYN+"What did you want to say?\n"+NORM);
    return 1;
  }
  if (str=="on") {
    MY_POUCH->set_telepathy(1);
    write(NORM+CYN+"Alchemist telepathy is now on.\n"+NORM);
    return 1;
  }
  if (str=="off") {
    MY_POUCH->set_telepathy(0);
    write(NORM+CYN+"Alchemist telepathy is now off.\n"+NORM);
    return 1;
  }
  player_list=users();
  for (i = 0; i < sizeof(player_list); i++) {
    if (present("Alchemist Pouch", player_list[i])) {
      if (stuff->query_telepathy())
        if (MY_PLAYER->query_invis() > 0)
          tell_object_wblock(player_list[i],
            NORM+BLU+":[ Someone==>"+NORM+CYN+str+NORM"\n");
        else
          tell_object_wblock(player_list[i],
            NORM+BLU+":[ "+MY_NAME_CAP+"==>"+NORM+CYN+str+NORM+"\n");
    }
  }
  return 1;
}
