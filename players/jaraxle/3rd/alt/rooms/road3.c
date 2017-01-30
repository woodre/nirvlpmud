#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Village road"+NORM;
   long_desc =
   "A long and tired road fading east and west through\n"+
   "the village.  There is a cross road heading north\n"+
   "with what looks like an old area of small, abandoned\n"+
   "shops still holding onto life.\n";
   add_item("hole","A dark hole you might be able to "+HIW+"enter"+NORM+"\n");
   add_item("road","A long stretch of tired road");
   add_item("shops","Old broken down shops");
   add_exit("/players/jaraxle/3rd/alt/rooms/road2.c","west");
   add_exit("/players/jaraxle/3rd/alt/rooms/road4.c","east");
   add_exit("/players/jaraxle/3rd/alt/rooms/northroad1.c","north");
}

