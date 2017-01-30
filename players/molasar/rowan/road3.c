

#include "/room/clean.c"

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "Roadway to the Town of Rowan  [n,e,w]"; }

long() {
   write("You are on the road which connects the crossroads and the town\n");
   write("of Rowan.  To the east lies the town, the crossroads to the west\n");
   write("A stable, where you can buy horses, lies to the north.\n");
    write("South of here is a large clearing.\n");
   write("     There are three obvious exits:  north, east, south, and west\n");
}

init() {
   add_action("south","south");
   add_action("north","north");
   add_action("east","east");
   add_action("west","west");
}

south() {
   this_player()->move_player("south#players/molasar/rowan/clearing");
   return 1;
}

north() {
   this_player()->move_player("north#players/molasar/rowan/stable");
   return 1;
}

east() {
   this_player()->move_player("east#players/molasar/rowan/w_twn_sq");
   return 1;
}

west() {
   this_player()->move_player("west#players/molasar/rowan/xroads");
   return 1;
}

