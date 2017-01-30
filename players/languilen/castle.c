#include "/players/languilen/closed/ansi.h"
#define NAME "Languilen"
#define DEST "room/ruin"
#define MOD "/players/languilen/module.c"
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

id(str) { return str == "doorway" || str == "door"; }

short() {
    return "A Shimmering Blue "+HIB+"Doorway"+NORM;
}

long() { write(
"    Thin tendrils of charged particles glide across the surface of\n\
this two dimensional rectangle that hangs in the air about a foot above\n\
the ground.  It is about the size and shape of a door but it has no\n\
depth, so from the side it can not be seen.  The object looks out of\n\
place here and is not a natural phenomenon.  A bold adventurer might\n\
attempt to enter it.\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
    if (!id(str)) {
        notify_fail("Are you trying to enter the doorway?\n");
	return 0;
    }
    write("You step through the doorway.\n");
    this_player()->move_player("doorway#"+MOD);
    return 1;
}

reset(arg) {
    if (arg) return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}

