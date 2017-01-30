#include "/players/jamila/ansi.h"
#define NAME "Jamila"
#define DEST "room/farmroad3"
#define tp this_player()

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

id(str) { return str == "sponge"; }

short() {
    return ""+HIY+"A Giant Sponge"+NORM+"";
}

long() {
    write(short()+" that you desperately want to touch!\n");
}

init() {
  add_action("enter", "touch");
}

enter(str) {
    if (!id(str))
	return 0;
    this_player()->move_player("sucked into the sponge#players/jamila/sponge");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
