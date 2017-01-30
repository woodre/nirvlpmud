inherit "room/room";
#include "definitions.h"

int i;

reset(arg) {

        if (!present("sithi")) {
           for (i = 1; i <=4; i++) {
                move_object(clone_object(CASTLEMONSTER+"/sithi_man.c"),
                        this_object());
                }
        }

        if(!arg) {
        set_light(0);
        short_desc=("Sithi living area, west cave");
        long_desc=
"     This appears to be a Sithi living area.  A table rests in the\n"+
"middle of the room.  Cots supported by wooden frameworks are pushed\n"+
"against the wall.  A few large boulders rest in the middle of the\n"+
"room, perhaps for use as a chair.  The place is somewhat orderly,\n"+
"with a few pieces of garbage lying on the floor near the table.\n";

   dest_dir=({
        CASTLEROOM+"/hall12.c","east"  ,
            });

   items=({
        "boulders","     They are too heavy to pick up",
        "cots","     The cots serve as beds",
        "framework","     It supports a cot",
        "framework","     They support the cots",
        "table","     The table rectangular and is made of wood",
   });
   }   }
