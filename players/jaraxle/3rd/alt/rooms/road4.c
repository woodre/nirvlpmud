#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Road"+NORM;
   long_desc =
   "  You are on a road going out of the village. Eastroad\n"+
   "runs north from here along the eastern perimeter of the\n"+
   "ruins, and to the south you see a dead field with dust\n"+
   "devils sending dirt and sand everywhere.  The main road\n"+
   "runs towards the shore to the east, and into the ruins\n"+
   "to the west.\n";
   add_item("ruins","Deserted and mostly demolished buildings");
   add_exit("/players/jaraxle/3rd/alt/rooms/road3.c","west");
   add_exit("/players/jaraxle/3rd/alt/rooms/road5.c","east");
   add_exit("/players/jaraxle/3rd/alt/rooms/eastroad1.c","north");
}

