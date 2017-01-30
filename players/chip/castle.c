#include <ansi.h>
#define NAME "Chip"
#define DEST "room/south/sforst47"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

/* Added 'apartment' id to this castle -- Rumplemintz */
id(str) { return str == "building" || str == "apartment"; }

short() {
    return ""+YEL+"An old abandoned apartment building"+NORM+"";
}

long() {
    write("It is so old and run-down, you dare not 'venture' inside.\n");
}

init() {
  add_action("venture", "venture");
}

venture(str) {
  if (!id(str))
    return 0;

  write("You venture into the apartment.  Good luck.\n");
  this_player()->move_player("into the apartment building#players/chip/room/apartment/enter.c");
  return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
