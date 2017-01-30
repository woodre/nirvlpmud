inherit "room/room";
#include "definitions.h"

reset(arg) {

if (!present("darkshadow")) {
      move_object(clone_object(CASTLEMONSTER+"/darkshadow.c"),this_object());
      move_object(clone_object(CASTLEMONSTER+"/darkshadow.c"),this_object());
   }

        if(!arg) {
        set_light(0);
        short_desc=("Room of skulls");
        long_desc=
"     You see a long hallway, 10' wide and 80' long.  On either side of\n"+
"the hallway, the walls are filled with long rows of wooden shelves\n"+
"containing skulls of every shape and description.  Every inch of the\n"+
"shelf space is filled, and a small plaque is set on the shelf\n"+
"below each skull.  Further down the hall, you see a stairway going down.\n";

   dest_dir=({
        CASTLEROOM+"/stairs2.c","stairway"  ,
        CASTLEROOM+"/stairs1.c","up"  ,
            });

   items=({
        "plaques","     The plaques are of unreadable Sithi writing",
   });
   }   }
