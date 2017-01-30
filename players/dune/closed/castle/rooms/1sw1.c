inherit "room/room";
#include "definitions.h"

reset(arg) {
        if(!arg) {
        set_light(1);
        short_desc="Mossy tree path";
        long_desc=
"     The trees here are covered with long drooping moss. The water\n"+
"pools are somewhat clearer, but still mainly opaque. The mist here\n"+
"is quite thick. It does not rise high enough to reach some of the\n"+
"higher water pools and land patches though. Travelling through this\n"+
"area of the swamp has been quite uneventful, and you take this time\n"+
"to catch in the smells and sights of the swamp.\n";

   dest_dir=({
        CASTLEROOM+"/sroad1.c","northeast"  ,
        CASTLEROOM+"/1sw2.c","southwest"  ,
            });

   items=({
        "mist","     It swirls with the air currents you make",
        "moss",
"     You look at the long curtains of moss and notice a slight\n"+
"discoloration on one of its hangings.  You step closer, and realize\n"+
"it can be nothing but blood.  You also notice some drops of blood\n"+
"coming from the southwest",
        "trees","     The trees seem normal as ever",
   });
   }   }
