/*
  Dismiss a little bat
*/

#include "/players/eurale/defs.h"

/* -------- Dismiss alarm bat ---------- */
dismiss_bat(str) {
  if (!str) {
    write("You must specify what you want to dismiss.\n");
    return 1;
  }
  if (str != "bat") return 0;
  if (!FANGS->query_littlebat_obj()) {
    write("You don't have an active bat to dismiss.\n");
    return 1;
  }
  write("Your bat squeaks and flys away.\n");
  tell_room(environment(FANGS->query_littlebat_obj()),
            "The bat squeaks, then flys away.\n");
  destruct(FANGS->query_littlebat_obj());
  FANGS->set_littlebat_obj(0);
  return 1;
}
