inherit "room/room";
#include "definitions.h"

reset(arg) {
   if(!arg) {
   set_light(1);
   short_desc=("Ocean Shore");
   long_desc=
"     The white sand beach stretches for miles along\n"+
"the coast.  Driftwood and seaweed lay sprawled about.\n"+
"Colorful tiny rocks rest upon the sand.  Waves roll \n"+
"along the shore and die further up the beach.  Past \n"+
"the waves, a giant ocean spans into the horizon.\n"+
"In the north and west, the land rises and becomes\n"+
"flat yellow plains.\n";

   dest_dir=({
   CASTLEROOM+"/brown7.c","west"  ,
   CASTLEROOM+"/shore7.c","south"  ,
   CASTLEROOM+"/brown3.c","north"  ,
            });

   items=({
   "sand","     The sand is thin and white",
   "plains","     The yellow plains are of dirt and dried grass",
   "beach","     The beach is rather narrow",
   "ocean","     A beautiful ocean lies before you",
   "coast","     The pretty coast is long and thin",
   "driftwood","     Driftwood rests in heaps",
   "seaweed","     Seaweed lies upon the sand",
   "rocks","     The rocks are small but multi-colored",
   "waves","     The waves are rough here",
   "shore","     The ocean shore is a beautiful marine setting",
   "horizon","     The horizon meets the ocean",
   });
   }   }
