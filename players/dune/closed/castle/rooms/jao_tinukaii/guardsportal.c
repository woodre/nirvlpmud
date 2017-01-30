inherit "room/room";
#include "definitions.h"

int g;

reset(arg) {

   if (!present("sithi")) {
     for(g=1;g<=2;g++)
       move_object(clone_object(CASTLEMONSTER+"/sithi_knight.c"),this_object());
   }

        if(!arg) {
        set_light(1);
        short_desc="Steps of the High Priest";
        long_desc=
"     You are at the base of a long series of broad and steep steps that\n"+
"lead up to a room above.  The steps are carpeted with black moss, like\n"+
"a rug.  At each side of the steps, large torches spew columns of flame\n"+
"into the smoky air.\n";

   dest_dir=({
        CASTLEROOM+"/fountain.c","southwest"  ,
        CASTLEROOM+"/meditation.c","up"  ,
            });

   items=({
        "rug","     The rug is quite large, covering all the steps",
        "torches","     The torces are supported by metal bands",
   });
   }   }
