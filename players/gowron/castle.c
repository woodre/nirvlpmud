#define NAME "Gowron"
#define DEST "room/forest1"
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

id(str) { return str == "gateway"; }

short() {
   return "A gateway to another city";
}

long() {
	write(format("This is a gateway to the town of Springfield.  By "+
	      	     "entering this gateway you will be able to visit this "+
	             "town and many of its inhabitants.  Have fun, and don't "+
	     	     "get lost :).\nBrought to you by Gowron.\n", 75));
}

init() {
  add_action("enter", "enter");
}

enter(str) {
    if(!str) return 0;
    if (!id(str))
	return 0;
    this_player()->move_player("on a road to springfield#"+
			       "players/gowron/room/entrance");
    return 1;
}

reset(arg) {
    object ob;
 
    if (arg)
	return;
    move_object(this_object(), DEST);
    ob = clone_object("players/gowron/closed/quest/questobject.c");
    move_object(ob, "/room/quest_room");
}

is_castle(){return 1;}
