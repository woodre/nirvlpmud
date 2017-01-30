#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Jetty"+NORM;
   long_desc =
   "  You are at a jetty. The waves roll with death\n"+
   "and decay from the east. A small path leads back\n"+
   "to the ruins woards the west.\n";
   add_exit("/players/jaraxle/3rd/alt/rooms/road6.c","west");
   add_exit("/players/jaraxle/3rd/alt/rooms/sea.c","east");
}

