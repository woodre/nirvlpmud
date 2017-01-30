inherit "room/room";
#include "definitions.h"

reset(arg) {

   if(!present("sithi")) {
     move_object(clone_object(CASTLEMONSTER+"/sithi_knight.c"),this_object());
   }

        if(!arg) {
        set_light(1);
        short_desc="Spiral stairs";
        long_desc=
"     A thin stone spiral staircase leads up.  You can feel a gush of\n"+
"air sweep against you as you face the stairs.  It reminds you of the\n"+
"swamp air outside.  Torches line the outer walls of the staircase.\n"+
"They roar softly as the wind blows against them.\n";

   dest_dir=({
        CASTLEROOM+"/fountain.c","southeast"  ,
        CASTLEROOM+"/deck.c","up"  ,
            });
}   }
