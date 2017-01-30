#include "/players/data/ansi.h"
#define NAME "Data"
#define DEST "room/south/sforst3"
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

id(str) { return str == "castle"; }

short() {
    return "Castle of " + NAME;
}

long() {
    write("You have just steped through the vortex. Looking back you see the\n");
    write("of your world. Looking ahead, you imediately feel the ancient powers\n");
	write("of the wizards of the past. As you look around you see different \n");
	write("openings, perhaps one will lead out out of this limbo.\n");
}

init() {
    add_action("enter"); add_verb("enter");
}

enter(str) {
    if (!id(str))
	return 0;
    write("It is not an open castle.\n");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
