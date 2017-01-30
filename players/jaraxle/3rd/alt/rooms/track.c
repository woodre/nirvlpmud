#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Village track"+NORM;
   long_desc =
   " A short track going into the village.  It looks\n"+
   "as though it has seen many travelers.  An abused\n"+
   "road continues to the east.  An old opening of\n"+
   "some sort aproaches the west.\n";
   add_item("track","A track made of very old and broken wood");
   add_item("road","A road stretching to the east");
   add_item("opening","Looks like an old meeting area to the west");
   
   add_exit("/players/jaraxle/3rd/alt/rooms/green.c","west");
   add_exit("/players/jaraxle/3rd/alt/rooms/road1.c","east");
   add_exit("/players/jaraxle/3rd/alt/rooms/clinic.c","northwest");
   
}

