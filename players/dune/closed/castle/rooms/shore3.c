inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if (!present("billy")) 
    move_object(clone_object(CASTLEMONSTER+"/buckding.c"),
      this_object());

   if(!arg) {
   set_light(1);
   short_desc=("Ocean Shore");
   long_desc=
"     The white sand beach stretches for miles along\n"+
"the coast.  Driftwood and seaweed lay sprawled about.\n"+
"Colorful tiny rocks rest upon the sand.  Waves roll \n"+
"along the shore and die further up the beach.  Past \n"+
"the waves, a giant ocean spans into the horizon.\n"+
"Opposite the ocean, the land rises to green plains\n"+
"in the north and yellow plains in the west.\n";

   dest_dir=({
   CASTLEROOM+"/brown2.c","west"  ,
   CASTLEROOM+"/shore2.c","east"  ,
   CASTLEROOM+"/shore4.c","south"  ,
   CASTLEROOM+"/green5.c","north"  ,
            });

   items=({
   "sand","     The sand is thin and white",
   "yellow plains","     The yellow plains are of dirt and dried grass",
   "green plains","     The green plains are abundant with grass",
   "plains","     The plains are a mixture of yellow and green",
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
