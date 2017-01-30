#define NAME "Traff"
#define DEST "room/eastroad3"
#include "/players/traff/closed/ansi.h"
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

id(str) { return str =="delnoch" || str == "pass" || str == "delnoch pass"; }

short() {
     return "Delnoch Pass";
}

long() {
     write("A long, narrow pass between plains and mountains.\n");
     write("The lush green country side looks inviting.\n");
     write("Why don't you enter the pass and see what's there?\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
	return 0;
call_other(this_player(),"move_player","enter#players/traff/delnoch/town/dmain.c");
  if(!find_player("traff")) {return 1;}
  tell_object(find_player("traff"),HIC+"[]"+"  "+
  BLU+capitalize(this_player()->query_real_name())+NORM+": has entered Delnoch.\n");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
