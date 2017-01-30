inherit "room/room";
#include "definitions.h"

int i;

reset(arg) {

        if (!present("lord"))
                move_object(clone_object(CASTLEMONSTER+"/avera_lord.c"),
                this_object());
        if (!present("knight")) {
              for (i = 1; i<=5;i++)
                move_object(clone_object(CASTLEMONSTER+"/sithi_knight.c"),
                this_object());
                }

        if(!arg) {
        set_light(0);
        short_desc=("Sithi Lord's Cavern");
        long_desc=
"     You enter a large but warm alcove in the underground cave.  The alcove\n"+
"is large enough to be considered a cavern.  The sandy floor gradually\n"+
"slopes downward into the water and, at the opposite end, upward into\n"+
"an area with smooth rock walls.  Torches align the surrounding walls,\n"+
"giving you the impression that whatever lives here must be considered\n"+
"quite important.\n";

   dest_dir=({
        CASTLEROOM+"/whirlpool.c","lake"  ,
            });

   items=({
        "floor","     The sand is thickly layered upon the floor",
        "sand","     The sand is a fine yellow powder",
        "cave","     The cave extends off into the unkown",
        "alcove",
"     This must be the living place of a local resident.  Whatever\n"+
"the resident is, it must be very big",
   });
   }   }
