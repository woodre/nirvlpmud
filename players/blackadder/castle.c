#define NAME "Blackadder"
#define DEST "room/south/sshore6"
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

id(str) { return str == "castle"; }

short() {
     return "Magnificent Castle of " + NAME;
}

long() {
    write("This is the " + short() + ".\n");
  write("Blackadder welcomes you and bids you enter and enjoy\n");
  write("his hospitality.\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
	return 0;
    call_other(this_player(),"move_player","enter#/players/blackadder/entrance");
   return 1;
}
reset(arg) {
object ob;
    if (arg)
	return;
move_object(this_object(), DEST);
/* pointless. 6.15.01 by verte */
/*
ob = clone_object("/players/blackadder/chair1");
move_object(ob,"/players/blackadder/hideaway");
*/

}
is_castle(){ return 1; }
