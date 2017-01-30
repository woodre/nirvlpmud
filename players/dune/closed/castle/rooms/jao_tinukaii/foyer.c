inherit "room/room";
#include "definitions.h"

reset(arg) {
        if(!arg) {
        set_light(1);
        short_desc="Foyer";
        long_desc=
"     You have entered a well-kept foyer.  A stairway leads up and\n"+
"a hallway goes north.  The foyer is rather large.  The floor is bare\n"+
"white stone, but not cold.  A strange heat warms this whole\n"+
"place.  Torches and sunlight shining through holes in the ceiling\n"+
"provide the light source.\n";

   dest_dir=({
        CASTLEROOM+"/room3.c","north"  ,
        CASTLEROOM+"/tstart.c","south"  ,
        CASTLEROOM+"/upmain.c","up"  ,
            });

   items=({
        "floor","     A floor of granite or shale, perhaps marble",
   });
   }   }
