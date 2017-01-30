#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Village green"+NORM;
   long_desc =
   "  You are at an open place south of the church.\n"+
   "The grass in the area which stopped growing ages\n"+
   "ago is brown, and mushy.\n";
   add_item("grass","Nasty crab grass; rotten, and dying.");
   add_exit("/players/jaraxle/3rd/alt/rooms/church.c","north");
   add_exit("/players/jaraxle/3rd/alt/rooms/hump.c","west");
   add_exit("/players/jaraxle/3rd/alt/rooms/track.c","east");
add_object("/players/jaraxle/3rd/alt/items/dispenser.c");
}

