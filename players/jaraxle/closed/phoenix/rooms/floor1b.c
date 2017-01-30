/*  10/08/06 - Rumplemintz
      Moved inherit above #include and removed trailing ; in #include
*/

inherit "/players/jaraxle/room.c";
#include "/players/jaraxle/define.h"
#include "/players/jaraxle/closed/phoenix/mons/random.h"

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
   add_item("stones","Large stones laying on the ground");
   add_item("floor","The stone floor is littered with large broken stones");
   add_item("hallway","A short hallway leading around the tower stairwell");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor1a.c","back");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor1c.c","around");
   
}
