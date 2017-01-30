
#include "/room/clean.c"

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "The Road to the Valley  [n,s]"; }

long() {
   write("You are on the Road to the Valley.\n");
   write("The road starts to slope downward to a large degree.\n");
   write("     There are two obvious exits:  north and south\n");
}

init() {
   add_action("north","north");
   add_action("south","south");
}

north() {
   this_player()->move_player("north#players/molasar/rowan/vroad3");
   return 1;
}

south() {
   this_player()->move_player("south#players/molasar/rowan/vroad1");
   return 1;
}


