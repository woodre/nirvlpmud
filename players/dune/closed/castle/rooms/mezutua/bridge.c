inherit "room/room";
#include "definitions.h"

reset(arg) {
        if(!arg) {
        set_light(1);
        short_desc=("Bridge across Stream of Magma");
        long_desc=
"     Before you a well-made stone bridge crosses a stream of oozing\n"+
"magma.  Set upon the side rails of the bridge, several stone skulls\n"+
"stare straight at you.  Though they look only like carvings, they turn\n"+
"their heads as you walk past them.  Some strange magic is about...  \n";

   dest_dir=({
        CASTLEROOM+"/spout3.c","southeast" ,
        CASTLEROOM+"/north3.c","southwest"  ,
            });

   items=({
        "bridge","     The seems sturdy enough to trust",
        "words","     The rails are made of stone, like the bridge",
        "skulls","     The skulls are all of elves",
        "stream","     The stream oozes underneath at a slow pace",
   });
   }   }
