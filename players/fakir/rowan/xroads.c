
#include "/room/clean.c"

reset(arg) {
   if(!arg)
     set_light(1);
}

id(str) { return str == "sign"; }

short() { return "The Crossroads  [n,s,e,w]"; }

long(str) {
   if(str == "sign") {
     write("The sign is basically a large wooden pole with planks pointing\n");
     write("in the directions of the roads.\n");
     write("NORTH ==>  The Hollows and Deadwood Forest\n");
     write("SOUTH ==>  The Elkhorn Mountains\n");
     write("WEST  ==>  The Silver Sea and the seaport of Drakeshore\n");
     write("EAST  ==>  The Town of Rowan\n");
     return 1;
   }
   write("You have reached the Crossroads, the point where roads from\n");
   write("all over the realm meet.  It turns out the intersection is\n");
   write("actually one large circle with roadways going off in the\n");
   write("cardinal directions.\n");
   write("     There are four obvious exits:  north, south, east, and west\n");
   write("There is a large sign here.\n");
}

init() {
   add_action("north","north");
   add_action("south","south");
   add_action("east","east");
   add_action("west","west");
}

north() {
  write("A recent storm has felled trees and scattered debris along the\n");
  write("road making it impassable for the time being.\n");
  return 1;
   this_player()->move_player("north#players/molasar/rowan/vroad1");
   return 1;
}

south() {
   this_player()->move_player("south#players/molasar/rowan/mroad1");
   return 1;
}

east() {
   this_player()->move_player("east#players/molasar/rowan/road3");
   return 1;
}

west() {
   this_player()->move_player("west#players/molasar/rowan/sroad1");
   return 1;
}

