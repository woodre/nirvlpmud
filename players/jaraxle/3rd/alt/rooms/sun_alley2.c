#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = BLK+BOLD+"Sun alley"+NORM;
   long_desc =
   "  The arched alley comes to an abrupt end to the west with a\n"+
   "huge pile of dirt and rubble blocking any further travel\n"+
   "in that direction.  To the south old rock fields obscure\n"+
   "most of your view of dead foliage.\n";
   add_item("dirt","Mounds of old hardened dirt");
   add_item("rubble","Old stone and rubble from what looks like a fallen building");
   add_item("fields","A small stretch of land covered with huge rocks");
   add_item("foliage","Dead trees and plants");
   add_item("archway","A rotted archway of wood");
   add_item("alley","A small walkway to the west, under an old archway");
   add_exit("/players/jaraxle/3rd/alt/rooms/sun_alley.c","east");
   /*
   add_object("/players/jaraxle/3rd/alt/items/waste_enter.c");
   */
}

