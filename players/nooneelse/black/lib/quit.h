/*
  quit.h
*/

#include "defs.h"

/* -------- Quit command for the fangs (clean up) ---------- */
quit() {
  if (MY_FANGS->query_servant_obj()) {
    destruct(MY_FANGS->query_servant_obj());
    MY_FANGS->tell_my_room(
                MY_NAME_CAP+" dismisses "+MY_PLAYER->query_possessive()+
                " servant.");
  }
  if (MY_FANGS->query_wolf_obj()) {
    destruct(MY_FANGS->query_wolf_obj());
    MY_FANGS->tell_my_room(
                MY_NAME_CAP+" dismisses "+MY_PLAYER->query_possessive()+
                " wolf.");
  }
  if (MY_FANGS->query_sneak_seconds() > 0) {
    MY_FANGS->set_sneak_seconds(0);
    if (MY_PLAYER->query_invis() > 0 && MY_LEVEL < 21) MY_PLAYER->make_visible();
    write("You've changed back from wraith form to normal form.\n");
    MY_FANGS->tell_my_room(MY_NAME_CAP+" slowly fades into view...");
  }
  MY_FANGS->dismiss_bat("bat");
  MY_FANGS->forget_rooms();
/*
  if (MY_LEVEL < 20) telepathyfeel(MY_FANGS->query_logoutmsg());
  MY_PLAYER->quit();
  return 1;
*/
}
