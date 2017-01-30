#define NAME "Kevlar"
#define DEST "room/forest10"
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

id(str) { return str == "warehouse"; }

short() {
    return "A large warehouse";
}

long() {
    write("You are standing in front of a large warehouse.\n");
    write("The construction appears to be rather new, however there\n");
    write("seems to be no action going on inside or out. A steel walk-in\n");
    write("door stands before you, with the word ENTRANCE stenciled in red\n");
    write("paint on it. Unfortunately, there is a large padlock on the\n");
    write("door, so entry is impossible at this time.\n");
}

init() {
    add_action("enter"); add_verb("enter");
}

enter(str) {
    if (!id(str))
	return 0;
    write("The door is locked. Can't you see the padlock?\n");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
