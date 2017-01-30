inherit "room/room";
#include "definitions.h"

init() {
add_action("goplace","north");
add_action("goplace","n");
::init();
}

reset(arg) {

    if(!present("sithi"))
   move_object(clone_object(CASTLEMONSTER+"/sithi_priest.c"),this_object());

        if(!arg) {
        set_light(1);
        short_desc="Side suite";
        long_desc=
"     Great postings of famous quotes and persons around the land are\n"+
"pasted on all the walls.  The room looks junky because of it, but\n"+
"it actually is well-kept.  Scrolls lie upon various desks and tables,\n"+
"no doubt these new posters will be pasted on the walls.  A\n"+
"picture of a completely naked sithiwoman lays sprawled out on one\n"+
"wall.  On a bed, a large pile of clothes are neatly folded.\n";

   dest_dir=({
        CASTLEROOM+"/upsouth.c","west"  ,
        CASTLEROOM+"/mastersuite.c","north"  ,
            });

   items=({
        "sithiwoman","     She is quite beautiful",
        "clothes","     The clothes are nothing but blue robes",
        "posters","     The posters have 1 or 2 lines of quotes on them",
        "scrolls","     The scrolls are all written in Sithi",
   });
   }   }

goplace() {
   say(TPN+" leaves into the drapes.\n");
   write("You find a secret passage behind the drapes.\n");
   move_object(TP, CASTLEROOM+"/mastersuite.c");
   return 1;
}
