/*
  peace.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- stop fighting in the room ---------- */
calm_fighters(str) {
  object target_obj;

  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str || str!="dust") {
    write(NORM+CYN+"use: peace dust\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 40) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("olive branch") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (olive branch).\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("olive branch", 1);
  if (MY_SPELL_POINTS < 20) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  MY_PLAYER->add_spell_point(- 20);
  target_obj = first_inventory(MY_ROOM);
  while (target_obj) {
    target_obj->stop_fight();
    target_obj->stop_fight();
    target_obj->stop_hunter();
    MY_PLAYER->stop_fight();
    MY_PLAYER->stop_fight();
    MY_PLAYER->stop_hunter();
    target_obj=next_inventory(target_obj);
  }
  return 1;
}
