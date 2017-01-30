inherit "room/room";
#include "definitions.h"

reset(arg) {
        if(!arg) {
        set_light(1);
        short_desc="High ground path";
        long_desc=
"     The land here is quite dry and serves as a very nice change from\n"+
"all the muck and water you've had to go through.  The trees here seem taller\n"+
"and thinner.  However, as there is less water around, the patches of water\n"+
"are more clouded and mucked up than ever.\n";

   dest_dir=({
        CASTLEROOM+"/2se1.c","west"  ,
        CASTLEROOM+"/2sse1.c","south"  ,
            });

   items=({
        "water",
"     You look into the murky water, and to your surprise, you notice\n"+
"a piece of flesh poking out of the pool.  You bend down and take it out.\n"+
"The corpse is of a half-man, half-cat combination.  It looks like it\n"+
"must have been involved in a fight, with which it lost.  You scrape off the\n"+
"leeches from the body to find large teeth marks all along the chest.\n"+
"Whatever killed it was definitely not human",
        "trees","     The thin pine trees thrust upward, like spears",
   });
   }   }
