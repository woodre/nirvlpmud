#include "/players/mosobp/ansi.h"
#define NAME "Mosobp"
#define DEST "room/farmroad3"
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

id(str) { return str == "ship" || str == "spaceship" ;}

short() {
    return ""+HIK+"A Spaceship"+NORM+"";
}

long() {
  write("Perhaps this spaceship can take you to another planet if you enter it.\n");
}

init() {
   add_action("enter","enter");
}

enter(str) {
    if (!id(str))
notify_fail("Enter what?\n");
this_player()->move_player("enter the spaceship#players/mosobp/areas/TEMPLE/rooms/ship.c");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
