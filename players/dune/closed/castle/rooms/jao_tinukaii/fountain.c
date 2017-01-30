inherit "room/room";
#include "definitions.h"

void init() {
        add_action("drink","drink");
::init();
}

reset(arg) {

if (!present("darkshadow")) {
      move_object(clone_object(CASTLEMONSTER+"/darkshadow.c"),this_object());
      move_object(clone_object(CASTLEMONSTER+"/darkshadow.c"),this_object());
   }

        if(!arg) {
        set_light(1);
        short_desc="Fountain";
        long_desc=
"     You have reached the northern-most area of the main hall.\n"+
"A pool of black water lies in a circular stone structure.  You\n"+
"can see your reflection in the blackness of the pool.  Off to\n"+
"the northwest, a spiral staircase leads up.  To the northeast,\n"+
"you can see the edge of many black carpeted steps.  The entry\n"+
"way blocks off the rest of your view.\n";

   dest_dir=({
        CASTLEROOM+"/room2.c","south"  ,
        CASTLEROOM+"/spiral_stairs.c","northwest"  ,
        CASTLEROOM+"/guardsportal.c","northeast"  ,
            });

   items=({
        "pool","     The brackish pool is filthy black",
   });
   }   }


int drink(string str) {
        write("You drink from the filth, and feel horrible.\n");
        return 1;
}
