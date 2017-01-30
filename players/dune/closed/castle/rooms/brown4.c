inherit "room/room";
#include "definitions.h"

int i;

reset(arg) {

if (!present("buffalo")) {
  for(i = 1; i<=3; i++) 
    move_object(clone_object(CASTLEMONSTER+"/buffalo.c"),
    TO); }

   if(!arg) {
   set_light(1);
   short_desc=("Northern Brown Plains");
   long_desc=
"     The green shade of grass to the north blends\n"+
"with the dryer yellow grass to the south.  The\n"+
"southern lands flatten completely, then, to the \n"+
"southwest, they rise again.  There are no trees\n"+
"nor shrubs in the flatland, it is only an open\n"+
"grassy plain.\n";

   dest_dir=({
   CASTLEROOM+"/brown8.c","west"  ,
   CASTLEROOM+"/brown5.c","south"  ,
   CASTLEROOM+"/green12.c","north"  ,
   CASTLEROOM+"/brown1.c","east"  ,
            });

   items=({
   "grass","     The grass is a light greenish-yellow here",
   "lands","     The land here is sloped downward to the south",
   "flatland","     The land to the south is completely flat",
   "plain","     The plain here is multi-colored",
   });
   }   }
