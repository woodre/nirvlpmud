/*
  remember_rooms.h
*/

#include "defs.h"

/* --------------- Remember rooms --------------- */
remember_rooms() {
  int i;
  object obj, mapper_bat_obj;
  if (MY_FANGS->query_nbr_remembered_rooms() >= 70) {
    write("You can't memorize any more rooms.  You have reached your limit.\n");
    return 1;
  }
  if (MY_LEVEL < 1 || MY_GUILD_EXP < 666) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 3) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 3);
  obj = present("mapperbat", MY_ROOM);
  if (obj && obj->query_bat_owner()==MY_NAME) {
    write("You are already remembering this room  as # "+
          obj->query_room_nbr()+".\n");
    return 1;
  }
  mapper_bat_obj = clone_object(MAPPER_BAT);
  mapper_bat_obj->set_room_nbr(MY_FANGS->query_nbr_remembered_rooms());
  mapper_bat_obj->set_bat_owner(MY_NAME);
  move_object(mapper_bat_obj, MY_ROOM);
  MY_FANGS->set_nbr_remembered_rooms(MY_FANGS->query_nbr_remembered_rooms()+1,
                                     mapper_bat_obj);
  write("You are remembering this room as # "+
        mapper_bat_obj->query_room_nbr()+".\n");
  return 1;
}
