/*
  drain_corpse.h
*/

#include "defs.h"

/* -------- Drain corpse ---------- */
drain_corpse(str) {
  object target_obj;
  if (MY_LEVEL < 3 || MY_GUILD_EXP < 667) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (!str || str != "corpse") return 0;
  target_obj = present("corpse", MY_ROOM);
  if (!target_obj) target_obj=present("corpse", MY_PLAYER);
  if (!target_obj) {
    write("A corpse must be present to do that.\n");
    return 1;
  }
  MY_PLAYER->heal_self(target_obj->heal_value());
  MY_PLAYER->add_alignment(- 25);
  destruct(target_obj);
  write("You sink you fangs into the corpse and drain it's energy.\n"+
        "Your mind feels clearer.\n");
  MY_FANGS->tell_my_room(
               MY_NAME_CAP+" sinks "+MY_PLAYER->query_possessive()+
               " fangs into the corpse and drains it's blood.");
  return 1;
}
