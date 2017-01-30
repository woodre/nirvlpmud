/*
  earth_elemental.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* --------------- Remember rooms --------------- */
earth_elemental() {
  int i;
  object obj, earth_elemental_obj;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str || str!="elemental") {
    write(NORM+CYN+"use: earth elemental\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_nbr_remembered_rooms() >= 70) {
    write(NORM+CYN+"You can't memorize any more rooms. "+
          "You have reached your limit.\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 40) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  obj = present("earthelemental", MY_ROOM);
  if (obj && obj->query_elemental_owner()==MY_NAME) {
    write(NORM+CYN+"You are already remembering this room  as # "+
          obj->query_room_nbr()+".\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("dust") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (dust).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("chalk") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (chalk).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("dust", 1);
  MY_POUCH->subtract_quantity("chalk", 1);
  MY_PLAYER->add_spell_point(- 50);
  earth_elemental_obj = clone_object(EARTH_ELEMENTAL);
  earth_elemental_obj->set_room_nbr(MY_POUCH->query_nbr_remembered_rooms());
  earth_elemental_obj->set_elemental_owner(MY_NAME);
  move_object(earth_elemental_obj, MY_ROOM);
  MY_POUCH->set_nbr_remembered_rooms(MY_POUCH->query_nbr_remembered_rooms()+1,
                                     earth_elemental_obj);
  write(NORM+CYN+"You are remembering this room as # "+
        earth_elemental_obj->query_room_nbr()+".\n"+NORM);
  return 1;
}
