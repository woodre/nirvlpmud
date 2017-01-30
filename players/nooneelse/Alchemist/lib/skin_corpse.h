/*
  skin_corpse.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Skin corpse ---------- */
skin_corpse(str) {
  object corpse_obj, skin_obj;
  int corpse_level;

  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 10) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (!str || str != "corpse") {
    write(NORM+CYN+"Skin what?\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 5) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  if (!present("knife", MY_PLAYER) {
    write(NORM+CYN+"You must have a knife to skin the corpse.\n"+NORM);
    return 1;
  }
  corpse_obj = present("corpse", MY_PLAYER);
  if (!corpse_obj) {
    write(NORM+CYN+"You must have the corpse to do that.\n"+NORM);
    return 1;
  }
  MY_PLAYER->add_spell_point(- 5);
  skin_obj = clone_object(ALCHEMIST_SKIN);
  skin_obj->set_skin_msg(lower_case(corpse_obj->short()));
  corpse_level = corpse_obj->query_level() / 2;
  if (corpse_level < 1) corpse_level = 1;
  skin_obj->set_skin_strength(corpse_level);
  destruct(corpse_obj);
  move_object(skin_obj, MY_PLAYER);
  write(NORM+CYN+"You carefully skin the corpse.\n"+NORM);
  MY_POUCH->tell_my_room(
              NORM+CYN+MY_NAME_CAP+" carefully removes the skin from the corpse.")+NORM;
  return 1;
}
