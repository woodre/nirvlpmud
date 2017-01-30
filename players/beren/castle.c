#define NAME "Beren"
#define DEST "room/plane13"
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

id(str) { return str == "world"; }

short() {
    return "Rocannon's world";
}

long() {
    write ("This is the Rocannon's world!\nType 'enter world' to travel there.\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
	return 0;
     call_other (this_player (), "move_player", "into world#players/beren/Rooms/hall.c");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
