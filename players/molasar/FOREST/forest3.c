
#include "std.h"

reset(arg) {
   if(!arg)
     set_light(1);
/*
   extra_reset();
*/
}

object rope;

/* moved rope to Eforest7.c   -Eurale  4/8/97
extra_reset() {
   if(!present("rope")) {
     rope = clone_object("obj/rope");
     move_object(rope, this_object());
   }
}
*/

short() { return "A great forest"; }

long() {
   write("You are in a great forest.\n");
   write("   There are four obvious exits:  north, south, east, and west\n");
}

init() {
   add_action("north","north");
   add_action("south","south");
   add_action("east","east");
   add_action("west","west");
}

north() {
   this_player()->move_player("north#players/molasar/FOREST/forest4");
   return 1;
}

south() {
   this_player()->move_player("south#players/molasar/FOREST/forest11");
   return 1;
}

west() {
   this_player()->move_player("west#players/molasar/FOREST/forest2");
   return 1;
}

east() {
   this_player()->move_player("east#players/molasar/FOREST/forest13");
   return 1;
}

