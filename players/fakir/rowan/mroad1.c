
#include "/room/clean.c"

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "The Road to the Mountains  [n,s]"; }

long() {
   write("You are on the Road to the Mountains.\n");
   write("Far to the south you can make out the lone peak which marks\n");
   write("the legendary lair of the Great Dragon, Andriakas.\n");
   write("     There are two obvious exits:  north and south\n");
}

init() {
   add_action("north","north");
   add_action("south","south");
}

north() {
   this_player()->move_player("north#players/molasar/rowan/xroads");
   return 1;
}

south() {
   this_player()->move_player("south#players/molasar/rowan/mroad2");
   return 1;
}


