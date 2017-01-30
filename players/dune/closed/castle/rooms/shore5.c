inherit "room/room";
#include "definitions.h"

reset(arg) {

if (!present("seagull")) 
  move_object(clone_object(CASTLEMONSTER+"/seagull.c"),
  this_object());

   if(!arg) {
   set_light(1);
   short_desc=("Ocean Shore");
   long_desc=
"     The white sand beach stretches for miles along\n"+
"the coast.  Driftwood and seaweed lay sprawled about.\n"+
"Colorful tiny rocks rest upon the sand.  Waves roll \n"+
"along the shore and die further up the beach.  Past \n"+
"the waves, a giant ocean spans into the horizon.\n";

   dest_dir=({
   CASTLEROOM+"/shore6.c","east"  ,
   CASTLEROOM+"/shore4.c","north"  ,
            });

   items=({
   "sand","     The sand is thin and white",
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
