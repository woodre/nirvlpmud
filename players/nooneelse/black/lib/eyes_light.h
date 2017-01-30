/*
  eyes_light.h
*/

#include "defs.h"

/* -------- Make a light ---------- */
eyes_light() {
  if (MY_LEVEL < 1 || MY_GUILD_EXP < 666) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 5) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 5);
  MY_FANGS->set_glowing_eyes(1);
  write(HIY+"Your eyes begin to glow"+NORM+".\n");
  MY_FANGS->tell_my_room(
    MY_NAME_CAP+"'s "+HIY+"eyes begin to glow"+NORM+"!\n");
  return 1;
}
