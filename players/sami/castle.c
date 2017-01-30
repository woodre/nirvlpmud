#include <ansi.h>
#define NAME "Sami"
#define DEST "room/mount_pass"
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

id(str) { return str == "cavern"; }

short() {
    return "A dark "+HIR+"Cavern"+NORM+"";
}

long() {
    write("This is the " + short() + ".\n");
    write("Blood and bones surround this demonic cave. Souls try\n");
    write("relentlessly to escape, but are sucked back in by something.\n");
}

init() {
   add_action("enter", "enter");
}

enter(str) {
  if (!id(str))
    return 0; 

  this_player()->move_player("You step bravely into the cavern#players/sami/area/coinarea/r1.c");
  return 1;
}

reset(arg) {

  if (arg)
    return;

  move_object(this_object(), DEST);
}

is_castle(){ return 1; }
