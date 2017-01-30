#define NAME "Oberon"
#define DEST "players/boltar/santaland/cavein"
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

id(str) { return str == "pattern"; }

short() {
	return "A large Pattern is drawn on the ground";
}

long() {
	write("There is a strange pattern drawn on the ground here. It appears to\n");
	write("be a single, intertwined curve, laid out in a spiderweb-like shape.\n");
	write("There is small jewel in the center of the pattern.\n");
}

init() {
	add_action("enter", "enter");
}

enter(str) {
	if (!id(str)) return 0;
	write("It is not an open castle.\n");
	return 1;
}

reset(arg) {
	if (arg) return;
	move_object(this_object(), DEST);
}

is_castle(){return 1;}
