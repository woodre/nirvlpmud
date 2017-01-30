/*
  air_elemental.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- air elemental ---------- */
air_elemental(str) {
  object elemental_obj;
  string str2;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str || sscanf(str, "elemental %s", str2)!=1) {
    write(NORM+CYN+"You must include a message for the elemental to say.\n"+
          "use: air elemental <msg>\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 40) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_air_elemental_obj()) {
    write(NORM+CYN+"You already have an active air elemental.\n");
    write("Use: 'dismiss air elemental' to get rid of it.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("fan") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (fan).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("feather") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (feather).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("fan", 1);
  MY_POUCH->subtract_quantity("feather", 1);
  MY_PLAYER->add_spell_point(- 50);
  elemental_obj=clone_object(AIR_ELEMENTAL);
  MY_POUCH->set_air_elemental_obj(elemental_obj);
  elemental_obj->set_message(str2);
  elemental_obj->set_elemental_owner(MY_NAME);
  move_object(elemental_obj, MY_ROOM);
  write(NORM+CYN+"Ok.\n"+NORM);
  return 1;
}
