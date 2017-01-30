#include "/players/tallos/ansi.h"
#define NAME "Lacar"
#define DEST "room/ravine"
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
    return ""+HIM+"Castle of Unycorns"+NORM+"";
}
long() { write("This is the "+HIM+"Castle of Unycorns"+NORM+".\n");
   write("It is a magical place of wonder and excitement. Perhaps you\n");
   write("should 'enter'.\n");
    } 

init() {
    add_action("enter"); add_verb("enter");
}
enter() {
  string str2;
  str2= "/players/lacar/area/park/rooms/unicornpark1.c";
  move_object(this_player(),"/players/lacar/area/park/rooms/unicornpark1.c");
  command("look",this_player());
  return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
