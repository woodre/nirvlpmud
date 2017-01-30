#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Village shore"+NORM;
   long_desc =
   "  A jetty leads out to the east. To the north some\n"+
   "old broken stairs lead down to the poluted beach. A\n"+
   "road starts to the west. \n";
   add_exit("/players/jaraxle/3rd/alt/rooms/road5.c","west");
   add_exit("/players/jaraxle/3rd/alt/rooms/road7.c","east");
}

