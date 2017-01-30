#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"All at sea"+NORM;
   long_desc =
   "You are swimming out at the sea.\n";
   add_object("/players/jaraxle/3rd/alt/items/pass.c");
   add_item("hole","A dark hole you might be able to "+HIW+"enter"+NORM+"\n");
   add_item("sign","You can barely make out the word 'shop' on the sign");
   add_item("building","This looks like a huge gathering place stood here");
   add_item("brick building","This looks like a huge gathering place stood here");
   
   add_exit("/players/jaraxle/3rd/alt/rooms/road7.c","west");
}

