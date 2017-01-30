/*
  fix_heartbeat.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- resart a player's heartbeat ---------- */
fix_heartbeat() {
  if (MY_GUILD_RANK < 10) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  MY_PLAYER->set_heartbeat(1);
  write(NORM+CYN+"Your slam yourself in the chest and feel your heart\n"+
        "start to beat again.\n"+NORM);
  MY_POUCH->tell_my_room(NORM+CYN+MY_NAME_CAP+
                      " slams "+MY_POSSESSIVE+"self in the chest."+NORM);
  return 1;
}
