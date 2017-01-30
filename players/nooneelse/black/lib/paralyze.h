/*
  paralyze.h
*/

#include "defs.h"

/* ---------------  Paralyze curse --------------- */
paralyze(str) {
  object obj, target_obj;
  if (!str) {
    write("You must specify who you want to paralyze.\n");
    write("Use: paralyze <who>\n");
    return 1;
  }
  if (MY_LEVEL < 12 || MY_GUILD_EXP < 670) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  target_obj = present(str, MY_ROOM);
  if (MY_LEVEL < 21 && !target_obj->query_npc()) {
    write("You can't use guild spells against players anymore!\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 50);
  if (!target_obj) {
    write("That creature is not here.\n");
    return 1;
  }
  if (!target_obj->query_npc() &&
      target_obj->query_level() > 19 &&
      MY_LEVEL < 20) {
    write("You can't paralyze a wizard!\n");
    return 1;
  }
  if (!target_obj->query_npc()) {
    write("You can't paralyze another player.\n");
    return 1;
  }
  obj = clone_object(VAMPIRE_PARLYZE_CURSE);
  obj->do_paralyze(str);
  move_object(obj, target_obj);
  write("Ok.\n");
  return 1;
}
