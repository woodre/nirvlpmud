/*
  emote.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* built in emoter */
emote(str) {
  string cheat1, cheat2;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (MY_LEVEL > 20) return 0;
  cheat1=0;
  cheat2=0;
  sscanf(str, "give%s", cheat1);
  sscanf(str, "hand%s", cheat2);
  if (cheat1 || cheat2) {
    write(NORM+CYN+"You can't use the emote command to do that!\n"+NORM);
    return 1;
  }
  MY_POUCH->tell_my_room(NORM+CYN+MY_NAME_CAP+" "+str+NORM);
  write(MNORM+CYN+Y_NAME_CAP+" "+str+"\n"+NORM);
  return 1;
}
