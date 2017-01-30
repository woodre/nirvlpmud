/*
  show_health.h
*/

#include "defs.h"

/* -------- Health ---------- */
show_health(str) {
  MY_FANGS->set_old_hp(0);
  MY_FANGS->set_old_sp(0);
  MY_FANGS->set_old_intox(0);
  MY_FANGS->set_old_stuffed(0);
  MY_FANGS->set_enemy_old_hp(0);
  if (MY_FANGS->query_monitor_self()) {
    write("Health monitor turned off.\n");
    MY_FANGS->set_monitor_self(0);
    return 1;
  }
  else {
    write("Health monitor turned on.\n");
    MY_FANGS->set_monitor_self(1);
  }
  return 1;
}
