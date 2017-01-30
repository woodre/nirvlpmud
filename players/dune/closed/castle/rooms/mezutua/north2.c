inherit "room/room";
#include "definitions.h"

reset(arg) {
        if(!arg) {
        set_light(0);
        short_desc=("Northern Tube");
        long_desc=
"     The tunnel walls here are almost completely smooth.  No rocks\n"+
"protrude from any wall surface.  Travel here is quite easy.  \n"+
"You better enjoy it while it lasts.\n";

   dest_dir=({
        CASTLEROOM+"/north3.c","northeast"  ,
        CASTLEROOM+"/north1.c","south"  ,
            });

   items=({
        "walls","     The walls are smooth to the touch",
   });
   }   }
