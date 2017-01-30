#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = BLK+BOLD+"East Road"+NORM;
   long_desc =
   "  You are on a road which runs parallel to the village shore.\n"+
   "The road is covered in dust from crushed rock and gravel\n"+
   "which puffs up in a cloud of smoke upon every step.\n";
   add_item("road","The road is covered in dust");
   add_item("dust","Fine dust, possibly from nuclear destruction of the pebble covered road");
   add_item("village shore","You cannot quite see the shore from here");
   add_item("rock","Hardly noticable among the dust, you can see small rocks");
   add_item("gravel","Hardly noticable among the dust, you can see bits and pieces of gravel");
   add_exit("/players/jaraxle/3rd/alt/rooms/eastroad2.c","north");
   add_exit("/players/jaraxle/3rd/alt/rooms/road4.c","south");
}

