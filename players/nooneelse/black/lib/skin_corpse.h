/*
  skin_corpse.h
*/

#include "defs.h"

/* -------- Skin corpse ---------- */
skin_corpse(str) {
  object corpse_obj, skin_obj;
  int corpse_level;
  if (MY_LEVEL < 1 || MY_GUILD_EXP < 666) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (!str || str != "corpse") {
    write("Skin what?\n");
    return 1;
  }
  corpse_obj = present("corpse", MY_PLAYER);
  if (!corpse_obj) {
    write("You must have the corpse to do that.\n");
    return 1;
  }
  skin_obj = clone_object(VAMPIRE_SKIN);
  skin_obj->set_skin_msg(lower_case(corpse_obj->short()));
  corpse_level = corpse_obj->query_level() / 2;
  if (corpse_level < 1) corpse_level = 1;
  skin_obj->set_skin_strength(corpse_level);
  destruct(corpse_obj);
  move_object(skin_obj, MY_PLAYER);
  write("You carefully skin the corpse.\n");
  MY_FANGS->tell_my_room(
              MY_NAME_CAP+" carefully removes the skin from the corpse.");
  return 1;
}
