inherit "room/room";
#include "definitions.h"

reset(arg) {
        if(!arg) {
        set_light(1);
        short_desc="Top of stairway";
        long_desc=
"     Benches and chairs lay at the top of the stairs.  Leafless plants\n"+
"grow in clay pots.  A thick rug lies upon the floor.  Two large vases\n"+
"sit at the each corner of a table next to a wall.  A mirror hangs over\n"+
"the table.  From the lounge area, a hallway leads north and south.\n";

   dest_dir=({
        CASTLEROOM+"/upnorth.c","north"  ,
        CASTLEROOM+"/upsouth.c","south"  ,
        CASTLEROOM+"/foyer.c","down"  ,
            });

   items=({
        "vases",
"     The vases seem to have various patterns upon them.  One pattern that\n"+
"stands out is a large picture of three horns surrounded by fire",
        "rug","     The rug is made of wicker",
        "mirror","     You take a moment to straighten your hair",
        "benches","     The benches are made of white stone",
        "pots","     The pots are made of clay",
        "plants","     These plants seem strangely wilted",
        "chairs","     The chairs are made of copper",
   });
   }   }
