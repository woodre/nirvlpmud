#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = BLK+BOLD+"Village road (Northroad)"+NORM;
   long_desc =
   " Northroad has seen better days indeed. Potholes from\n"+
   "years of neglect and no maintenance have turned this\n"+
   "nice and beautiful road into a obstacle course. There are\n"+
   "some old run down shops to either side of the road. A\n"+
   "trail going northeast leads to the ruins of the old\n"+
   "arena, where people go to forget about their bad lives\n"+
   "and enjoy watching the lives of others end. To the east\n"+
   "you see the hotel, with some destroyed buildings on top\n"+
   "of it making the hotel seem nothing but rubble. \n";
   
   add_item("potholes","Deep holes in the road");
   add_item("shops","Old shops to the east and west");
   add_item("trail","A small path to the northeast");
   add_item("hotel","Condemed and no longer available for rent");
   add_item("hole","A dark hole you might be able to "+HIW+"enter"+NORM+"\n");
   add_item("sign","You can barely make out the word 'shop' on the sign");
   add_item("building","This looks like a huge gathering place stood here");
   add_item("brick building","This looks like a huge gathering place stood here");
   
   add_exit("/players/jaraxle/3rd/alt/rooms/northroad3.c","north");
   add_exit("/players/jaraxle/3rd/alt/rooms/northroad1.c","south");
   add_exit("/players/jaraxle/3rd/alt/rooms/magic.c","west");
}

