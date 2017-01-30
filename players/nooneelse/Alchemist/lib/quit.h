/*
  quit.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Quit command for the pouch (clean up) ---------- */
quit() {
  if (MY_POUCH->query_raven_obj()) {
    destruct(MY_POUCH->query_raven_obj());
    MY_POUCH->tell_my_room(
                NORM+CYN+MY_NAME_CAP+" dismisses "+MY_PLAYER->query_possessive()+
                " raven."+NORM);
  }
  if (MY_POUCH->query_vampire_obj()) {
    destruct(MY_POUCH->query_vampire_obj());
    MY_POUCH->tell_my_room(
                NORM+CYN+MY_NAME_CAP+" dismisses "+MY_PLAYER->query_possessive()+
                " vampire."+NORM);
  }
  if (MY_POUCH->query_sphere_obj()) destruct(MY_POUCH->query_sphere_obj());
  MY_POUCH->dismiss_elemental("air");
  MY_POUCH->dismiss_elemental("fire");
  MY_POUCH->forget_rooms();
  if (MY_LEVEL < 20) telepathyfeel(MY_POUCH->query_logoutmsg());
  /* now go to the normal quit command */
  return 0;
}
