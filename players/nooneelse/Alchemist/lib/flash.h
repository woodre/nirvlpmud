/*
  flash.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- flash - sneak out of the room ---------- */
detect_disease(str) {
  string *exits;
  int i, exit_nbr;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 20) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("sulfur") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (sulfur).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("fire fly") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (fire fly).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  if (!str) {
    write(NORM+CYN+"You must supply an exit/direction from this area.\n"+NORM);
    return 1;
  }
  exits=MY_ROOM->query_dest_dir();
  exit_nbr=-1;
  for (i=1; i<sizeof(exits); i++) {
    if (str==exits[i]) {
	  exit_nbr=i;
	  break;
    }
  }
  if (exit_nbr<0) {
    write(NORM+CYN+"There is no such exit/direction from this area ("+str+").\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("sulfur", 1);
  MY_POUCH->subtract_quantity("fire fly", 1);
  MY_PLAYER->add_spell_point(- 50);
  write(NORM+CYN+"You throw a vial to the ground. There is a bright flash!\n"+
        "You slip out of the room to the "+str+".\n"+NORM);
  MY_POUCH->tell_my_room(NORM+CYN+MY_NAME_CAP+
                      " throws a vial to the ground. There is a bright flash!\n"+
                      "When it clears, you see that "+MY_NAME_CAP+" is gone!\n"+NORM);
  move_object(MY_PLAYER, exits[exit_nbr-1]);
  return 1;
}
