#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";
#include "/players/jaraxle/3rd/alt/mobs/random.h"

reset(arg) {
   if(arg) return;
   set_light(0);
   add_property("PK");
   add_property("NT");
   get_random_mob();
   short_desc = BLK+BOLD+"Wastelands "+NORM+RED+"3031"+NORM;
   long_desc =
   "  You are in an entrance to what seems like a large stretch\n"+
   "of baron waste.  The ground is a lifeless dark grey with long\n"+
   "empty cracks splitting across the land like lightning.\n";
   add_item("grass","Nasty crab grass; rotten, and dying.");
   add_exit("/players/jaraxle/3rd/alt/rooms/church.c","north");
   add_exit("/players/jaraxle/3rd/alt/rooms/track.c","east");
   add_object("/players/jaraxle/3rd/alt/items/dispenser.c");
}

