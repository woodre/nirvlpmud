inherit "room/room";
#include "definitions.h"

reset(arg) {
     if(!arg) {
     set_light(1);
     short_desc=("Path to Volcano");
     long_desc=
"     Gently rolling hills span the horizon to the west, ending\n"+
"at a mountain with a flattened top.  One can only guess that this\n"+
"may be a volcano.  The clouds grow darker around the volcanic peak.\n";

   dest_dir=({
     CASTLEROOM+"/outdoor1.c","north"  ,
     CASTLEROOM+"/hill2.c","east"  ,
            });

   items=({
     "hills","     The hills are treeless, being covered only with grass",
     "volcano","     The volcano is somewhat short, but very wide",
     "clouds","     The clouds seem to be ordinary rain clouds",
   });
   }   }
