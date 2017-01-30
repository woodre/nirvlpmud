/*
  fear.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Fear ---------- */
cause_fear(str) {
  object target_obj;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str) {
    write(NORM+CYN+"You must specify who you want to frighten.\n"+
          "use: fear <who>\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 60) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("sulphur") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (sulphur).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("flint") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (flint).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 25) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("sulphur", 1);
  MY_POUCH->subtract_quantity("flint", 1);
  MY_PLAYER->add_spell_point(- 25);
  target_obj=present(str, MY_ROOM);
  if (!target_obj) {
    write(NORM+CYN+capitalize(str)+" is not here.\n"+NORM);
    return 1;
  }
  if (!target_obj->query_npc() &&
      target_obj->query_level() > 19 &&
      MY_LEVEL < 20) {
    write(NORM+CYN+
          "The only way to frighten a wizard is to find bugs in their code!\n"+NORM);
    return 1;
  }
  if(target_obj->query_level() > (this_player()->query_level() - 1)) {
    write(NORM+CYN+"The target is far too powerful to terrorize!\n"+NORM);
    return 1;
  }
  if (!target_obj->query_wimpy()) {
    write(NORM+CYN+capitalize(str)+" withstands your fearsome glare.\n"+NORM);
    return 1;
  }
  write(NORM+CYN+"You glare at "+str+"!\n"+NORM);
  tell_object(target_obj, MNORM+CYN+Y_NAME_CAP+" glares at you!  You panic!\n"+NORM);
  target_obj->run_away();
  return 1;
}
