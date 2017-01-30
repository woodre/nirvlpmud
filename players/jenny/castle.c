#define NAME "Jenny"
#define DEST "room/plane11"
#include "/players/jenny/define.h"
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

id(str) { return str == "portal"; }

short() {
#include "/players/jenny/randomcolors.h"
return BOLD+""+x+"A "+y+"Strange "+z+"Portal"+NORM; }


long() {
    write(BOLD+"This strange looking portal was left here by the evil"+NORM+"\n");
    write(BOLD+"wizard Jenny.  The brave adventurer could enter it."+NORM+"\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
        return 0;
    TP->move_player("through the portal#players/jenny/areaentrance.c");
    return 1;
}

reset(arg) {
    if (arg)
        return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
