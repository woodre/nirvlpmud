#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

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
   add_object("/players/jaraxle/3rd/alt/wastes/items/sign.c");
   add_exit("/players/jaraxle/3rd/alt/wastes/rooms/room1.c","north");
   add_exit("/players/jaraxle/3rd/alt/wastes/rooms/shop.c","south");
   add_exit("/players/jaraxle/3rd/alt/wastes/rooms/shop.c","back");
}

