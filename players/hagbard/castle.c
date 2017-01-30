#define NAME "hagbard"
#define DEST "room/crop"
object ob;
object hah;



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

id(str) { return str == "atlantis";}

short() {
    return "Atlantis is to the west";

}

long() {
    write("The lost city of Atlantis is here.\n");
}
init() {
  add_action("enter", "west");
}

enter(str) {
call_other(this_player(),"move_player","west#players/hagbard/castle/entrance");
    return 1;

}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle() { return 1; }
