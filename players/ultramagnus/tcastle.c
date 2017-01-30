#define NAME "Ultramagnus"
#define DEST "room/vill_shore2"
#include "room.h"
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

id(str) { return str == "south"; }

short() {
   return "There is a Beautiful Purple Aura coming from the south" ;
}

long() {
    write("This is the " + short() + ".\n");
    write(NAME + " is a rather new wizard, but it is an amazing castle\n");
    write("just the same. However, the gates are closed.\n");
    write("But Will Be opened very soon.....!!!!...\n");
}

init() {
    add_action("south","south");
}

south(str) {
    call_other(this_player(),"move_player", "south#players/ultramagnus/hall.c");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
