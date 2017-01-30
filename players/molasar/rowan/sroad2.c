
#include "/room/clean.c"

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "The Road to the Sea  [e,sw]"; }

long() {
   write("You are on the Road to the Sea.\n");
   write("The path curves slightly to the southwest at this point.\n");
   write("     There are two obvious exits:  east and southwest\n");
}

init() {
   add_action("east","east");
   add_action("southwest","southwest");
}

east() {
   this_player()->move_player("east#players/molasar/rowan/sroad1");
   return 1;
}

southwest() {
   this_player()->move_player("southwest#players/molasar/rowan/drake/ghouse");
   return 1;
}

