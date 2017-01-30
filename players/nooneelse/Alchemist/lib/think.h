/*
  think.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Think feelings/emotes - tell all Alchemists ---------- */
telepathyfeel(str) {
  int i;
  object stuff;
  string who, msg, player_list, junk1, junk2;

  if (!str) {
    write(NORM+CYN+"What did you want to say?\n"+NORM);
    return 1;
  }

  sscanf(str, "%s==>%s", junk1, junk2);
  if (junk1)
    str = BLU+junk1+"==>"+NORM+junk2;

  player_list=users();
  for (i = 0; i < sizeof(player_list); i++) {
    stuff=present("Alchemist Pouch", player_list[i]);
    if (stuff) {
      if (stuff->query_telepathy())
        if (MY_PLAYER->query_invis() > 0)
          if (query_verb()=="tf" || query_verb()=="telepathyfeel") {
            tell_object(player_list[i],
                        NORM+BLU+":[ Someone "+NORM+CYN+str+NORM"\n");
          }
          else {
            tell_object(player_list[i],
                        NORM+BLU+":[ Someone . o O ("+NORM+CYN+str+BLU+")"+NORM+"\n");
          }
        else
          if (query_verb()=="tf" || query_verb()=="telepathyfeel") {
            tell_object(player_list[i],
                        NORM+BLU+":[ "+MY_NAME_CAP+NORM+" "+NORM+CYN+str+NORM"\n");
          }
          else {
            tell_object(player_list[i],
                        NORM+BLU+":[ "+MY_NAME_CAP+" . o O ("+NORM+CYN+str+BLU+")"+NORM+"\n");
          }
    }
  }
  return 1;
}
