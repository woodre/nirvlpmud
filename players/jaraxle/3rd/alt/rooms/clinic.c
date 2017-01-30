#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"The clinic"+NORM;
   long_desc =
   "  A bare room with padded walls.  Along the walls\n"+
   "rows of shackles dangle down.  The floor is solid\n"+
   "concrete and cold to the touch.\n";
   add_item("walls","Walls of thick padding");
   add_item("shackles","Iron shackles with dried blood caked around them");
   add_item("flood","The concrete floor is staned crimson from all the blood shed");
   add_exit("/players/jaraxle/3rd/alt/rooms/church.c","west");
   add_exit("/players/jaraxle/3rd/alt/rooms/track.c","southeast");
   
}

