
/*
 * Main Intersection
 * Lots of guards here
 */

#include "/players/molasar/rowan/room/exit.h"

reset(arg) {
   if(!arg)
     set_light(0);
   extra_reset();
}

extra_reset() {
   object guard, mage;
   int i;
   if(!present("mage")) {
      mage = clone_object("players/molasar/rowan/monsters/d_mage");
      move_object(mage, this_object());
   }
   if(!present("guard")) {
     i = 0;
     while(i < 3) {
       guard = clone_object("players/molasar/rowan/monsters/d_guard");
       move_object(guard, this_object());
       i += 1;
     }
   }
}

short() { return "Intersection of tunnels"; }

long() {
   write("You are at an intersection of passages.\n");
   write("A cool breeze is coming from the tunnel which slopes\n");
   write("upward to the north.  Two more tunnels go off to\n");
   write("the east and west.\n");
   write("     There are three obvious exits:  up, east, and west\n");
}

init() {
   add_exit("up","/players/molasar/rowan/mtn/under4");
   add_exit("east","/players/molasar/rowan/mtn/eunder1");
   add_exit("west","/players/molasar/rowan/mtn/wunder1");
}

move() {
  string verb;

  verb = query_verb();
  if(verb == "up") {
    this_player()->move_player("up#players/molasar/rowan/mtn/under4");
    return 1;
  }
  if(verb == "east") {
    if(present("dragonman")) {
      write("The dragonman blocks your way.\n");
      return 1;
    }
    this_player()->move_player("east#players/molasar/rowan/mtn/eunder1");
    return 1;
  }
  if(verb == "west") {
    if(present("dragonman")) {
      write("The dragonman blocks your way.\n");
      return 1;
    }
    this_player()->move_player("west#players/molasar/rowan/mtn/wunder1");
    return 1;
  }
}


