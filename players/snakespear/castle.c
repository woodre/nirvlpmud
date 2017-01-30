#include "/players/snakespear/closed/ansi.h"
#define NAME "Snakespear"
#define DEST "room/south/sforst1"
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

id(str) { return str == "castle" || str == "archway"; }

short() {
   return (GRY+"A "+HIG+"Mi"+GRY+"st"+HIG+"y "+GRY+"Ar"+HIG+"chw"+GRY+"ay"+NORM);
}

long() {
    write("This is " + short() + ".\n\n");
    write("  This simple archway seems very magical, yet it's very ordinary\n"+
          "There seems to be mist flowing fluently out of the arch, then\n"+
          "vanishing into the atmosphere.  The mist is a swirling mixture\n"+
          "of greys and greens.  What lays inside the archway?  Should you\n"+
          "try to enter it and see what's to be seen?\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
    if (!str) {
        write("Enter what?\n");
        return 0; }
    if (str == "archway") {
	call_other(this_player(),"move_player","Archway#players/snakespear/tools/hub.c");
        return 1; }
    else {
      notify_fail("Enter what?\n");
      return 0;
    }
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
    clone_object("/players/snakespear/tools/airose.c");
    clone_object("/players/snakespear/tools/arose.c");


}
is_castle(){return 1;}
