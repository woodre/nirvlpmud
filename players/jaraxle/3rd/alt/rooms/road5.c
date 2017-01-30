#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Road"+NORM;
   long_desc =
"  You are on a road going out of the ruins. To\n"+
"the east the road is less visible as it leads\n"+
"down to the poluted shore. To the west lies the\n"+
"ruined city.\n";

   add_item("shore","A scent of pollution can be smelled from the east");
   add_exit("/players/jaraxle/3rd/alt/rooms/road4.c","west");
   add_exit("/players/jaraxle/3rd/alt/rooms/road6.c","east");
}

