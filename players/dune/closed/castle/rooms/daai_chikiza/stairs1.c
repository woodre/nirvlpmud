inherit "room/room";
#include "definitions.h"

reset(arg) {
        if(!arg) {
        set_light(0);
        short_desc=("Stairs going down");
        long_desc=
"     A dusty stairway descends into the cave.  No torches align the\n"+
"cavern walls.  A thin layer of damp dirt lies upon the stairs.\n"+
"A cool wind blows from further down the stairs.\n";

   dest_dir=({
        CASTLEROOM+"/daientrance.c","up"  ,
        CASTLEROOM+"/skulls.c","down"  ,
            });

   items=({
        "dirt","     The dirt is moist, wetted by an unknown reason",
   });
   }   }
