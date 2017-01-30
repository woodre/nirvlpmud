inherit "room/room";
#include "definitions.h"

void init() {
        add_action("taste","taste");
::init();
}

reset(arg) {
        if(!arg) {
        set_light(1);
        short_desc=("Underground Sea Cave");
        long_desc=
"     You swim in the cool waters of an underground sea cave.  The depth\n"+
"increases rapidly as you swim away from the shore.  Long strands of\n"+
"seaweed float atop the waters.  Small cracks in the ceiling above\n"+
"shed light upon the waters.  Near the cracks, you can see mussels\n"+
"and sea anemone cling together in large clumps.  Tiny drops of water\n"+
"fall through these cracks, making the illusion of rainfall in slow motion.\n"+
"The water is strangely buoyant, for you surely would drown if it were not.\n"+
"The sea completely encircles you, and continues far into the distance.\n"+
"There is no sign as to where the source of the water comes from.\n";

   dest_dir=({
        CASTLEROOM+"/water11.c","north"  ,
        CASTLEROOM+"/whirlpool.c","northeast"  ,
            });

   items=({
        "cracks","     The cracks let light in from the outside",
        "water","     The water is slightly turbulent",
        "ceiling","     The ceiling has cracks in it",
        "rainfall","     Drops of water drip from stalagtites",
        "stalagtites","     They form upside down spears",
        "sea anemone","     The anemone form beautiful patterns",
        "anemone","     The anemone form beautiful patterns",
        "mussels","     The mussels compete for space with the anemone",
        "sea","     The sea is completely underground here",
   });
   }   }

int taste (string str) {
        write("The sea water tastes very salty.\n");
        return 1;
        }   
