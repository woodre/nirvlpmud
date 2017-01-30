#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Village road"+NORM;
   long_desc =
   "  A long, soiled and beaten road going east through\n"+
   "the abandoned village. The road narrows to a festering\n"+
   "track to the west. There is a dark alley to the north.\n";
   add_item("alley","A dark alleyway to the north");
   add_item("road","A road covered in mud and dead grass");
   
   add_exit("/players/jaraxle/3rd/alt/rooms/track.c","west");
   add_exit("/players/jaraxle/3rd/alt/rooms/road2.c","east");
   add_exit("/players/jaraxle/3rd/alt/rooms/yard.c","north");
   
}

