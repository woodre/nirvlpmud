
#include "/room/clean.c"

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "The Road to the Mountains  [n,se]"; }

long() {
   write("You are on the Road to the Mountains.\n");
   write("Small rocks and gravel cover much of the road.\n");
   write("     There are two obvious exits:  north and southeast\n");
}

init() {
   add_action("north","north");
   add_action("southeast","southeast");
}

north() {
   this_player()->move_player("north#players/molasar/rowan/mroad1");
   return 1;
}

southeast() {
   this_player()->move_player("southeast#players/molasar/rowan/mroad3");
   return 1;
}


