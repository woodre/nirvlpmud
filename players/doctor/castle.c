#define NAME "Doctor"
#define DEST "room/south/sforst20"
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

id(str) { return str == "box"; }

short() {
    return "a Blue Police Box";
}

long() {
    write("This is " + short() + ".\n");
    write("Maybe you can open it.\n");
}

init() {
  add_action("open", "open");
}

open(str) {
    if (!id(str))
	return 0;
call_other(this_player(), "move_player", "open#/players/doctor/TARDIS/control_room");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
