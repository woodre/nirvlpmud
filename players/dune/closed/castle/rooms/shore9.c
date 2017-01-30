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
"To the west, the land rises into foothills and\n"+
"eventually into mountains.\n";

   dest_dir=({
   CASTLEROOM+"/hill5.c","west"  ,
   CASTLEROOM+"/shore8.c","north"  ,
            });

   items=({
   "sand","     The sand is thin and white",
   "beach","     The beach is rather narrow",
   "foothills","     The foothills rise steeply from the shore",
   "mountains","     Tall snow-capped mountains tower over the hills",
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
