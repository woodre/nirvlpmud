/*
  dismiss_bat.h
*/

#include "defs.h"

/* -------- Dismiss alarm bat ---------- */
dismiss_bat(str) {
  if (!str) {
    write("You must specify what you want to dismiss.\n");
    return 1;
  }
  if (str != "bat") return 0;
  if (!MY_FANGS->query_alarm_bat_obj()) {
    write("You don't have an active bat to dismiss.\n");
    return 1;
  }
  write("Your alarm bat squeaks and flys home.\n");
  tell_room(environment(MY_FANGS->query_alarm_bat_obj()),
            "The bat squeaks, then flys away.\n");
  destruct(MY_FANGS->query_alarm_bat_obj());
  MY_FANGS->set_alarm_bat_obj(0);
  return 1;
}
