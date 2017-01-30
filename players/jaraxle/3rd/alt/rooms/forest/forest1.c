#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = BLK+BOLD+"Haunted Ways"+NORM;
   long_desc =
   "  You are at an open place south of the church.\n"+
   "The grass in the area which stopped growing ages\n"+
   "ago is brown, and mushy.\n";
   add_item("grass","Nasty crab grass; rotten, and dying.");
   add_exit("/players/jaraxle/3rd/alt/rooms/forest/forest1e.c","east");
   add_exit("/players/jaraxle/3rd/alt/rooms/forest/forest1w.c","west");
   add_exit("/players/jaraxle/3rd/alt/rooms/forest/forest2.c","north");
   add_exit("/players/jaraxle/3rd/alt/rooms/sea.c","pass");
}

