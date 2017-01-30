inherit "room/room";
#include "definitions.h"

reset(arg) {
        if(!arg) {
        set_light(0);
        short_desc=("Whirlpool");
        long_desc=
"     You have entered an area where the waters churn and rotate\n"+
"in a huge whirlpool.  Swimming on the outer edges of the pool\n"+
"is impossible, yet a calm spot in the center of the swirling\n"+
"waters provides stable positioning.  With some difficulty, you\n"+
"manage to swim to the calm spot.  However, you are completely\n"+
"disoriented in doing so.  You have lost all sense of direction.\n";

   dest_dir=({
        CASTLEROOM+"/sealord.c","north"  ,
        CASTLEROOM+"/water11.c","northeast"  ,
        CASTLEROOM+"/water9.c","northwest"  ,
        CASTLEROOM+"/water8.c","west"  ,
        CASTLEROOM+"/water10.c","southwest"  ,
        CASTLEROOM+"/water12.c","south"  ,
            });

   items=({
        "whirlpool",
"     The cause of the churning waters is unknown.  Certainly no\n"+
"natural event can cause the waters to rotate like this.  Perhaps\n"+
"there is a degree of magic involved",
        "center",
"     The center of the churning waters can fit many human-sized\n"+
"creatures.  It is remarkably calm",
   });
   }   }
