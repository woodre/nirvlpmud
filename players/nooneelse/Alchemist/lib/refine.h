/*
  refine.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Drain corpse ---------- */
drain_corpse(str) {
  object target_obj;

  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 10) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (!str || str != "corpse") return 0;
  target_obj = present("corpse", MY_ROOM);
  if (!target_obj) target_obj=present("corpse", MY_PLAYER);
  if (!target_obj) {
    write(NORM+CYN+"A corpse must be present to do that.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("flint") < 1) {
    write(NORM+CYN+"You don't have the appropriate components (flint).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("iron rod") < 1) {
    write(NORM+CYN+"You don't have the appropriate components (iron rod).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("flint", 1);
  MY_POUCH->subtract_quantity("iron rod", 1);
  MY_PLAYER->add_spell_point(- 50);
  MY_PLAYER->heal_self(target_obj->heal_value());
  destruct(target_obj);
  write(NORM+CYN+"You pour some orange dust onto the corpse.\n"+
        "As it dissolves, a wisp of energy floats from it to you.\n"+
        "Your mind feels clearer."+NORM+"\n");
  MY_FANGS->tell_my_room(
               NORM+CYN+MY_NAME_CAP+" pours some orange dust onto the corpse.\n"+
               "As it dissolves a wisp of energy floats from it to "+
               MY_NAME_CAP+"."+NORM);
  return 1;
}
