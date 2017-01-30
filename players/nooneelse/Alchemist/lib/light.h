/*
  light.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Make a light ---------- */
light() {
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 10) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("fire fly") < 1 || MY_POUCH->query_quantity("flint") < 1) {
    write(NORM+CYN+"You don't have the appropriate components.\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("fire fly", 1);
  MY_POUCH->subtract_quantity("flint", 1);
  MY_PLAYER->add_spell_point(- 50);
  MY_POUCH->set_light_ointment(1);
  write(NORM+CYN+"You smear an ointment on your forehead, which begins to glow.\n"+NORM);
  MY_POUCH->tell_my_room(MY_NAME_CAP+NORM+CYN+
                      " smears an ointment on "+MY_POSSESSIVE+
                      " forehead, which begins to glow."+NORM);
  return 1;
}
