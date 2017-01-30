inherit "room/room";
#include "definitions.h"

int i;

reset(arg) {

if (!present("orc")) {
   for(i = 1; i<=6; i++) 
      move_object(clone_object(CASTLEMONSTER+"/orc.c"),this_object());
   }

        if(!arg) {
        set_light(0);
        short_desc=("Northern Tube");
        long_desc=
"     The tunnel walls here are almost completely smooth.  No rocks\n"+
"protrude from any wall surface.  Travel here is quite easy.  \n"+
"You better enjoy it while it lasts.  To the northwest, a thick fog fills\n"+
"the tube, obscuring further vision.\n";

   dest_dir=({
        CASTLEROOM+"/smoke1.c","northwest"  ,
        CASTLEROOM+"/north3.c","southeast"  ,
            });

   items=({
        "walls","     The walls are smooth to the touch",
   });
   }   }
