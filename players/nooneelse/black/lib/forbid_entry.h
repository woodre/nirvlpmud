/*
  fly_direction.h
*/

#include "defs.h"

/* -------- Forbid entry in a direction ---------- */
forbid_entry(str) {
  object obj;

  write("Sorry, this has been ruled illegal by mythos.\n");
  return 1;

  if (!str) {
    write("You must supply the direction (spelled out.  ex: 'forbid east').\n");
    return 1;
  }
  if (MY_LEVEL< 19 || MY_GUILD_EXP < 672) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  obj = clone_object(ROOM_SEALER);
  obj->set_direction(lower_case(str));
  obj->set_owner(MY_NAME);
  move_object(obj, MY_ROOM);
  MY_FANGS->tell_my_room(
              MY_NAME_CAP+" makes a few gestures and concentrates for\n"+
              "a moment and a flaring red light springs up to the "+str+".");
  write("You make a few gestures and concentrate for a moment and a\n"+
        "flaring red light springs up to the "+str+".\n");
  return 1;
}
