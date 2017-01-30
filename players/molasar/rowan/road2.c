
#include "/room/clean.c"

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "Roadway to the City of Rowan  [e,w]"; }

long() {
   write("You are on the main roadway to the City of Rowan.\n");
   write("The dusty road that comes from the east changes into a stone\n");
   write("path at this point.  You can see a large statue in the middle\n");
   write("of the town square to the west.\n");
   write("   There are two obvious exits:  east and west\n");
}

init() {
   add_action("east","east");
   add_action("west","west");
}

east() {
   this_player()->move_player("east, away from the town square"+
       "#players/molasar/rowan/road1");
   return 1;
}

west() {
  this_player()->move_player("down the stone path for the town square"+
      "#players/molasar/rowan/e_twn_sq");
  return 1;
}

