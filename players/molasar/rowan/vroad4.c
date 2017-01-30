
#include "/room/clean.c"

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "The Road to the Valley  [n,w]"; }

long() {
   write("You are on the Road to the Valley.\n");
   write("The valley bottom lies to the north.\n");
   write("     There are two obvious exits:  north and west\n");
}

init() {
   add_action("north","north");
   add_action("west","west");
}

north() {
   this_player()->move_player("north#players/molasar/rowan/val/road1");
   return 1;
}

west() {
   this_player()->move_player("west#players/molasar/rowan/vroad3");
   return 1;
}


