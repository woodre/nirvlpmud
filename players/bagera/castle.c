#define NAME "Bagera"
#define DEST "room/forest4"
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

id(str) { return str == "jungle"; }

short() {
    return "Bagera's Jungle";
}

long() {
    write("This is a dense jungle full of adventure and fun.\n");
    write("type 'enter jungle' to explore.\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
   if(!str || str != "jungle") {
      write("Enter what?\n");
      return 1;
   }
   call_other(this_player(), "move_player", 
             "enter#players/bagera/jungle/entrance");
   return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
