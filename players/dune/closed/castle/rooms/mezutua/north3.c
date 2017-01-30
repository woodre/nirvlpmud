inherit "room/room";
#include "definitions.h"

reset(arg) {
        if(!arg) {
        set_light(0);
        short_desc=("Northern Tube");
        long_desc=
"     The tunnel walls here are almost completely smooth.  No rocks\n"+
"protrude from any wall surface.  Travel here is quite easy.  \n"+
"You better enjoy it while it lasts.  Off to the northeast, a stone bridge\n"+
"crosses over what seems to be a red glow.  It is quite hot in that\n"+
"direction.  Isn't this volcano supposed to be inactive.\n";

   dest_dir=({
        CASTLEROOM+"/north4.c","northwest"  ,
        CASTLEROOM+"/north2.c","southwest"  ,
        CASTLEROOM+"/bridge.c","northeast"  ,
            });

   items=({
        "walls","     The walls are smooth to the touch",
   });
   }   }
