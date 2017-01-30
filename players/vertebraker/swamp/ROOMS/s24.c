#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg); 
   set_long(
"     Lush vegetation and rich green plants spring up on all sides of\n"+
"you, and the swamp seems to go on endlessly without a hope in sight.\n"+
"You can hear the sounds of life and of the inhabitants of the swamp\n"+
"all around you.\n");
   add_item("vegetation","Strong vines and trees");
   add_smell("main","You smell the swamp waters.");
   add_listen("main","You can hear the sounds of life all around you.");  
   add_touch("vines","It feels cold and strong.");
   add_item("vines","Dark green, twisted vines");
   add_item("trees","Large trees that are full of life and soaked with moisture");
   add_smell("stench","You smell the swamp waters.");
   add_item("bog","The murky waters slosh over your skin");
   add_exit(ROOMS+"s7","east");
   add_exit(ROOMS+"s23","west");
   add_exit(ROOMS+"s46","north");
}
