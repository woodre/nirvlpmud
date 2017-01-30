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
   "small stairwell in the center of the room leads\n"+
   "through the middle of the tower.\n";
   add_item("tower","Made of solid stone, the tower rises high above the land");
   add_item("stairwell","A large stone stairway leading through the tower");
   add_item("stones","Large stones laying on the ground");
   add_item("floor","The stone floor is littered with large broken stones");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor3b.c","around");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor3d.c","back");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor4a.c","up");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor2a.c","down");
   
}
