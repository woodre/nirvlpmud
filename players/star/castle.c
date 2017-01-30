#define NAME "Star"
#define DEST "room/south/sforst9"
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

id(str) { return str == "hole"; }

short() {
    return "A Swirling Black Hole";
}

long() {
    write("This is a black hole that will suck you right out of this world if you\n");
    write("dare to enter it.\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
	return 0;
    write("You enter the black hole and are sucked into some kind of bubble in\n");
    write("space.\n");
    this_player()->move_player("into the black hole#/players/star/bubble.c");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
    load_it();
}
is_castle(){return 1;}

load_it(){
   clone_object("players/star/closed/stardust.c");
}
