/*
  cause_fear.h
*/

#include "defs.h"

/* -------- Fear ---------- */
cause_fear(str) {
  object target_obj;
  if (!str) {
    write("You must specify who you want to frighten.\n");
    write("Use: fear <who>\n");
    return 1;
  }
  if (MY_LEVEL < 7 || MY_GUILD_EXP < 669) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 25) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 25);
  target_obj=present(str, MY_ROOM);
  if (!target_obj) {
    write(capitalize(str)+" is not here.\n");
    return 1;
  }
  if (!target_obj->query_npc() &&
      target_obj->query_level() > 19 &&
      MY_LEVEL < 20) {
    write("You can't frighten a wizard!\n");
    return 1;
  }
  /* adding this in as a level checker.. all force runaways and all must check versus level - mythos <1-29-96> */
    if(target_obj->query_level() > (this_player()->query_level() - 1)) {
    write("The target is far too powerful to fear,\n");
  return 1;}
  if (!target_obj->query_wimpy()) {
    write(capitalize(str)+" withstands your fearsome glare.\n");
    return 1;
  }
  write("You glare at "+str+"!\n");
  tell_object(target_obj, MY_NAME_CAP+" glares at you!  You panic!\n");
  target_obj->run_away();
  return 1;
}
