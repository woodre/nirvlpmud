#define NAME "Catacomb"
#define DEST "room/south/sforst8"
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

id(str) { return str == "cave"; }

short() {
    return "The forgotten cave";
}

long() {
    write("A dark cave.  Forgotten for centuries and now it has resurfaced\n");
    write("to claim the lives of a new crop of adventurers.  Noone knows\n");
    write("what kind of horrors await those who enter.  Perhaps you could\n");
    write("'enter' it to see these horrors for yourself?\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
	return 0;
    write("You enter the forgotten cave.\n");

    this_player()->move_player("into the cave#players/catacomb/cave.c");
    return 1;
}
reset(arg) 
{
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
