inherit "room/room";
#include "definitions.h"

reset(arg) {
   if(!arg) {
   set_light(1);
   short_desc=("Southeastern Green Plains");
   long_desc=
"     The land here is flat.  Small bushes and weeds grow\n"+
"abundantly.  To the south and east, a long sandy beach\n"+
"ends into the crashing waves of a large ocean.  Northward,\n"+
"the land rises to more grassy plains.\n";

   dest_dir=({
   CASTLEROOM+"/brown1.c","west"  ,
   CASTLEROOM+"/shore3.c","south"  ,
   CASTLEROOM+"/green4.c","north"  ,
   CASTLEROOM+"/shore1.c","east"  ,
            });

   items=({
   "weeds","     The weeds are short and small",
   "waves","     The waves mark the beginning of an infinite ocean",
   "plains","     The plains slope upward from here",
   "beach","     The beach is long and thin",
   "land","     The land has no hills or mounds",
   "ocean","     The ocean spans for miles, having no end",
   "bushes","     Several dull green bushes dot the ground",
        });
   }   }
