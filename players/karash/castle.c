#define NAME "Karash"
#define DEST "room/farmroad1"
#include <ansi.h>

/******************************************************************************
 * Program: castle.c
 * Path: /players/karash/
 * Type: castle
 * Created: September 2014 by Karash
 *
 * Purpose: This is the entrance to the Slipgate Outpost, which is the 
 *			castle area for Karash
 * 
 * History:
 *          
 ******************************************************************************/
 
 
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

id(str) { return str == "castle" || str == "outpost" || str == "slipgate outpost"; }

short() {
    return GRY+"Slipgate Outpost"+NORM;
}

long() {
    write("This area is surrounded by a wooden fence which appears to have been completed\n\
in a hurry.  There is an opening which allows you to '"+GRY+"enter"+NORM+"' the '"+GRY+"outpost"+NORM+"'.\n");
}

init() {
    add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
  return 0;
    /* write("It is not an open castle.\n"); */
	/* this_player()->move_player("into theportal#players/dragnar/WalkingDead/rooms/entrance.c") */
	this_player()->move_player("into the outpost#players/karash/Outpost/rooms/so01.c");
    return 1;
}


reset(arg) {
    if (arg)
  return;
    move_object(this_object(), DEST);
}

is_castle(){return 1;}
