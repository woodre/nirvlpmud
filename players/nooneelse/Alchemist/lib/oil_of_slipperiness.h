/*
  oil_of_slipperiness.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- disarm opponent ---------- */
fumble_curse(str) {
  object target_obj, stuff_obj, drop_this;
  int drop_item;
  string str;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str) {
    write(NORM+CYN+"use: grease <who>\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 40) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  target_obj=present(str, MY_ROOM);
  if (!target_obj) {
    write(NORM+CYN+capitalize(str)+" is not here.\n"+NORM);
    return 1;
  }
  if (target_obj->query_level()>20) {
    write(NORM+CYN+"You can't grease a wizard!\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("oil") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (oil).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("pork rind") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (pork rind).\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("oil", 1);
  MY_POUCH->subtract_quantity("pork rind", 1);
  if (MY_SPELL_POINTS < 35) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  drop_item=1;
  stuff_obj=first_inventory(target_obj);
  while (drop_item && stuff_obj) {
    str=stuff_obj->short();
    if (str && stuff_obj->query_wielded()) {
      stuff_obj->move(environment(target_obj));
      drop_this=stuff_obj;
      drop_item=0;
    }
    stuff_obj=next_inventory(stuff_obj);
  }
  stuff_obj->stopwield();
  MY_PLAYER->add_spell_point(- 35);
  write(NORM+CYN+capitalize(str)+" is now disarmed!\n"+NORM);
  MY_POUCH->tell_my_room(NORM+CYN+MY_NAME_CAP+" looks at "+capitalize(str)+
                      " strangely, then smirks!"+NORM);
  return 1;
}
