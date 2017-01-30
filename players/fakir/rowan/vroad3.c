
#include "/room/clean.c"

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "The Road to the Valley  [s,e]"; }

long() {
   write("You are on the Road to the Valley.\n");
   write("The land drops off suddenly preventing any travelling\n");
   write("to the north.\n");
   write("     There are two obvious exits:  south and east\n");
}

init() {
   add_action("east","east");
   add_action("south","south");
}

east() {
   this_player()->move_player("east#players/molasar/rowan/vroad4");
   return 1;
}

south() {
   this_player()->move_player("south#players/molasar/rowan/vroad2");
   return 1;
}


