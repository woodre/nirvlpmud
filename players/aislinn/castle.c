#define NAME "aislinn"
#define DEST "room/wild1"
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

id(str) { return str == "gate"; }

short() {
  return "To the north is a wrought iron gate";
}

long() {
  write("An elegant wrought iron gate spans a brick road leading north.\n");
  write("A small placque is set at eye level on the right side.  If you\n");
  write("read the placque, it says:  The Avalon Sports Complex and \n");
  write("Athletic Facility.  Visitors are welcome.\n");
  write("   \n");
}


init() {
  add_action("enter", "enter");
  add_action("north", "north");
  add_action("n", "n");
}

enter(str) {
    if (!id())
       return 0;
    call_other(this_player(),"move_player","north#players/aislinn/road1");
    return 1;
}
 
north() {
    call_other(this_player(),"move_player","north#players/aislinn/road1");
    return 1;
}
 
n() {
    call_other(this_player(),"move_player","north#players/aislinn/road1");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){ return 1; }
