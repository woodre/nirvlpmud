
#include "/room/clean.c"

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "Roadway to the City of Rowan  [e,w]"; }

long() {
 write("You are on the main roadway to the City of Rowan.\n");
 write("Many footsteps and carts have rolled along this path creating\n");
 write("numerous ruts and ditches making your footing precarious at times.\n");
 write("You can see the town square off a distance to the west while\n");
 write("the entrance to sunalley lies east.\n");
 write("   There are two obvious exits:  east and west\n");
}

init() {
   add_action("west","west");
   add_action("east","east");
}

west() {
   this_player()->move_player("west, towards the town square"+
       "#players/molasar/rowan/road2");
   return 1;
}

east() {
   this_player()->move_player("Rowan and heads for Sunalley#room/sunalley2");
   return 1;
}

