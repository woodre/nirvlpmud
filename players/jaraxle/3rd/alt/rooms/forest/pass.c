#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Wall of Passage"+NORM;
   long_desc =
   " Before you is a Great Wall of Mist.  Behind you is the sea,\n"+
   "before you- who knows.  'Pass' beyond the wall if you dare.\n";
   add_item("wall","A large wall of mist");
   add_item("mist","A large wall of mist");
   add_item("wall of mist","A large wall of mist");
   
   add_exit("/players/jaraxle/3rd/alt/rooms/forest/clearing.c","pass");
   add_exit("/players/jaraxle/3rd/alt/rooms/sea.c","west");
   
}

