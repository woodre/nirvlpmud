#include "/players/jaraxle/define.h"
#include "/players/jaraxle/closed/phoenix/mons/random.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   get_random_mob();
   short_desc = "Tower of the "+RED+"["+HIR+"Pho"+BLK+"e"+HIR+"nix"+NORM+RED+"]"+NORM;
   long_desc =
   "  A large forgotten tower in ruins.  Stones from\n"+
   "around the walls have crumbled to the floor.  A\n"+
   "round hallway leads around the stairwell to the\n"+
   "back side of the tower.\n";
   add_item("tower","Made of solid stone, the tower rises high above the land");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor4c.c","around");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor4a.c","back");
}

