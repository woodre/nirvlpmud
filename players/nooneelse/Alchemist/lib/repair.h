/*
  repair.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- repair a weapon ---------- */
repair(str) {
  object weapon_obj;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 80) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  weapon_obj=present(str, MY_PLAYER);
  if (!weapon_obj) {
    write(NORM+CYN+"You don't have a "+str+"!\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("flint") < 1) {
    write(NORM+CYN+"You don't have the appropriate component(flint).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("iron rod") < 1) {
    write(NORM+CYN+"You don't have the appropriate component(iron rod).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("diamond") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (diamond).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  if (weapon_obj->query_broke()==1) {
    write(NORM+CYN+"But, this weapon isn't broken!\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_weapon()==weapon_obj) {
    write(NORM+CYN+"You must 'unwield "+str+"' first\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("flint", 1);
  MY_POUCH->subtract_quantity("iron rod", 1);
  MY_POUCH->subtract_quantity("diamond", 1);
  MY_PLAYER->add_spell_point(- 50);
  write(NORM+CYN+"You grind the "+str+" with a flint, a diamond and an iron rod.\n"+NORM);
  MY_POUCH->tell_my_room(NORM+CYN+MY_NAME_CAP+
                      " grinds the "+str+" with a flint, adiamond and an iron rod."+NORM);
  weapon_obj->set_its_broken(0);
  return 1;
}
