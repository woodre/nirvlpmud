#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
init(){
   ::init();
   add_action("block","west");
   add_action("block","w");
}
block(){
   write("As you try to cross the bridge, a plank gives way.\n");
   write("\tYou think twice about crossing, you should go back.\n");
   return 1;}

inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Humpbacked bridge"+NORM;
   long_desc =
   " An old humpbacked bridge reaching into the plains\n"+
   "to the west.  The bridge is missing planks and\n"+
   "looks dangerously weak.\n";
   add_item("bridge","Rotted wood planks cover a creek with no water");
   add_item("creek","Long evaporated, the creek bed is cracked dry");
   add_exit("/players/jaraxle/3rd/alt/rooms/hump.c","west");
   add_exit("/players/jaraxle/3rd/alt/rooms/green.c","east");
   
}

