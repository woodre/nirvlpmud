
#include "/room/clean.c"
reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "The Road to the Valley  [n,s]"; }

long() {
   write("You are on the Road to the Valley.\n");
   write("To the north the land slopes downward into a large rolling\n");
   write("pasture.  At the bottom you can make out the edges of the\n");
   write("Deadwest Forest.  Towards the northeast you can make out\n");
   write("a small foggy area which could only be the Hollows.\n");
   write("     There are two obvious exits:  north and south\n");
}

init() {
   add_action("north","north");
   add_action("south","south");
}

north() {
   this_player()->move_player("north#players/molasar/rowan/vroad2");
   return 1;
}

south() {
   this_player()->move_player("south#players/molasar/rowan/xroads");
   return 1;
}


