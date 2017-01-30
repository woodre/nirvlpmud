/*
  emit_mist.h
*/

#include "defs.h"

/* -------- Emit a mist that makes it dark ---------- */
emit_mist(str) {
  if (MY_NAME!="nooneelse") {
    write("\nNooneelse is still testing this.  You can't use it yet.\n");
    return 1;
  }
  if (MY_LEVEL < 1 || MY_GUILD_EXP < 666) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_FANGS->query_vampire_mist()) {
    MY_FANGS->set_vampire_mist(0);
    MY_FANGS->tell_my_room("The red mist clears, revealing "+MY_NAME_CAP+".");
    write("You dissipate the mist.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 15) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  if (!str || str!="mist") return 0;
  MY_PLAYER->add_spell_point(- 15);
  MY_FANGS->set_vampire_mist(1);
  MY_FANGS->tell_my_room(
               "A deep, blood-red mist starts to surround "+MY_NAME_CAP+".\n"+
               "After a moment, the mist obscures your vision.");
  write("A deep red mist exudes from your pores to darken the room.\n"+
        "Fortunately, you can still see through it.\n");
  return 1;
}
