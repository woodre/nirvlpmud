inherit "room/room";
#include "definitions.h"

reset(arg) {
   if(!arg) {
   set_light(1);
   short_desc=("Northeastern Brown Plains");
   long_desc=
"     The green shade of grass to the north blends\n"+
"with the dryer yellow grass to the south.  The\n"+
"southern lands flatten completely, then, to the \n"+
"southwest, they rise again.  There are no trees\n"+
"nor shrubs in the flatland, it is only an open\n"+
"grassy plain.\n";

   dest_dir=({
   CASTLEROOM+"/brown4.c","west"  ,
   CASTLEROOM+"/brown2.c","south"  ,
   CASTLEROOM+"/green9.c","north"  ,
   CASTLEROOM+"/green5.c","east"  ,
            });

   items=({
   "grass","     The grass is a light greenish-yellow here",
   "lands","     The land here is sloped downward to the south",
   "flatland","     The land to the south is completely flat",
   "plain","     The plain here is multi-colored",
   });
   }   }
