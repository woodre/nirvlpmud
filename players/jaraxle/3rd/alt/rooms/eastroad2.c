#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = BLK+BOLD+"East Road"+NORM;
   long_desc =
   "  The east road continues to run along the village shore here\n"+
   "just off the shoreline of the beach down below.  Rotting dead\n"+
   "trees stand lifeless along the sides of the road.\n";
   add_item("road","The east road is covered in dust and cracked everywhere");
   add_item("shoreline","You can see water meeting the beach at the village shore");
   add_item("village shore","A desolate beach where water meets dark sand");
   add_item("trees","Dark black trees that have no sign of life");
   add_exit("/players/jaraxle/3rd/alt/rooms/eastroad3.c","north");
   add_exit("/players/jaraxle/3rd/alt/rooms/eastroad1.c","south");
}

