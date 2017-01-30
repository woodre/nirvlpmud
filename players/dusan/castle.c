#include "/players/dusan/ansi.h"
#define NAME "Dusan"
#define DEST "room/south/sforst19.c"
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

id(str) { return str == "road"; }

short() {
    return ""+HIW+"Marble Road"+NORM+"";
}

long() {
    write("There are deep cracks with weeds sprouting from them in this road, \n");
    write("but it seems to have weathered the ages well.  It must have been a \n");
    write("mighty kingdom to build such a marvel.  Why don't you 'follow' the \n");
    write("'road' and see where it leads? \n");
}

init() {
  add_action("follow", "follow");
}

follow(str) {
 if(!str){write("follow what?\n"); return 1; }
 if(str == "road"){this_player()->move_player("road#players/dusan/area1/rooms/swamp1.c"); return 1; }
 write("Follow what?\n"); return 1; }


reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST); 
}
is_castle(){return 1;}
