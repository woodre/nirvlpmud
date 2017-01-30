/*
  stone_skin.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- stone skin armor (only if player has no other armor) ---------- */
detect_disease(str) {
  object obj;

  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str || str!="skin") {
    write(NORM+CYN+"use: stone skin\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 10) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("granite") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (granite).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("flint") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (flint).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  if (MY_AC>0) {
    write("You cannot wear any armor when you use this ability.\n");
    return 1;
  }
  MY_POUCH->subtract_quantity("granite", 1);
  MY_POUCH->subtract_quantity("flint", 1);
  MY_PLAYER->add_spell_point(- 50);
  obj=clone_object(ALCHEMIST_STONE_SKIN):
  switch (MY_ALCHEMIST_RANK) {
    case 10: obj->set_ac(6); break;
    case 20: obj->set_ac(7); break;
    case 40: obj->set_ac(8); break;
    case 60: obj->set_ac(9); break;
    case 80: obj->set_ac(10); break;
    obj->set_ac(12);
  }
  move_object(obj, MY_PLAYER);
  command(MY_PLAYER, "wear stone_skin");
  write(NORM+CYN+"You rub an ointment all over your body.\n"+NORM);
  MY_POUCH->tell_my_room(NORM+CYN+MY_NAME_CAP+
                      " rubs an ointment all over "+MY_POSSESSIVE+" body."+NORM);

  return 1;
}
