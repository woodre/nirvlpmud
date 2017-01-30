/*
  calm_fighters.h
*/

#include "defs.h"

/* -------- Calm a monster ---------- */
calm_fighters(str) {
  object target_obj;
  if (MY_LEVEL < 5 || MY_GUILD_EXP < 668) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 20) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 20);
  if (!str) {
    target_obj = first_inventory(MY_ROOM);
    while (target_obj) {
      target_obj->stop_fight();
      target_obj->stop_fight();
      target_obj->stop_hunter();
      target_obj=next_inventory(target_obj);
    }
    return 1;
  }
  target_obj=present(str, MY_ROOM);
  if (!target_obj) {
    write(capitalize(str)+" is not present.\n");
    return 1;
  }
  target_obj->stop_fight();
  target_obj->stop_fight();
  target_obj->stop_hunter();
  MY_PLAYER->stop_fight();
  MY_PLAYER->stop_fight();
  MY_PLAYER->stop_hunter();
  return 1;
}
