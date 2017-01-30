
#include "/room/clean.c"

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "The Road to the Sea  [e,w]"; }

long() {
   write("You are are the road that connects the crossroads and the\n");
   write("Silver Sea.  Far to the west you can make out the ruins\n");
   write("that was once the seaport of Drakeshore.\n");
   write("     There are two obvious exits:  east and west\n");
}

init() {
   add_action("east","east");
   add_action("west","west");
}

east() {
   this_player()->move_player("east#players/molasar/rowan/xroads");
   return 1;
}

west() {
   this_player()->move_player("west#players/molasar/rowan/sroad2");
   return 1;
}


