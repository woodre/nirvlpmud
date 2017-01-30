#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Village road (Northroad)"+NORM;
   long_desc =
   "You can barely make out Northroad as debris litters the ground.\n"+
   "Towards the east you see a old run down bank, the door hanging\n"+
   "by the hindges. On the ground next to the door you see the\n"+
   "skeleton of some dead guard. Towards the northwest you see a\n"+
   "giant heap which used to be known as the clothing shop. To the\n"+
   "northeast you see The Grand Hotel which has been condembed due\n"+
   "to safty issues.\n";
   
   add_item("debris","Paper, dirty stones, and trash");
   add_item("bank","An old run down building");
   add_item("door","The bank door barely hanging on");
   add_item("skeleton","A skeleton which has been aged, and picked clean of meat");
   add_item("hotel","Condemed and no longer available for rent");
   
   
   add_exit("/players/jaraxle/3rd/alt/rooms/smithy.c","west");
   add_exit("/players/jaraxle/3rd/alt/rooms/bank.c","east");
   add_exit("/players/jaraxle/3rd/alt/rooms/road3.c","south");
   add_exit("/players/jaraxle/3rd/alt/rooms/northroad2.c","north");
}

