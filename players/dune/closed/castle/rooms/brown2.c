inherit "room/room";
#include "definitions.h"

reset(arg) {
   if(!arg) {
   set_light(1);
   short_desc=("Northern Flat Plains");
   long_desc=
"     Scattered about the flat plains lie a rocky\n"+
"crag.  White stone rocks jut out from the ground\n"+
"to create a dense rock jungle.\n";

   dest_dir=({
   CASTLEROOM+"/brown5.c","west"  ,
   CASTLEROOM+"/brown3.c","south"  ,
   CASTLEROOM+"/brown1.c","north"  ,
   CASTLEROOM+"/shore3.c","east"  ,
            });

   items=({
   "plains","     The grass is a mottled brownish-yellow",
   "crevices","     The crevices lead to dark holes",
   "cracks","     The cracks are wide enough to fit through",
   "jungle","     You see a jungle of rocks",
   "rocks","     The rocks are large white stone boulders",
   "crag","     The crag is very wide and high",
   });
   }   }
