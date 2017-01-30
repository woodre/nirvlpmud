inherit "room/room";
#include "definitions.h"

void init() {
        write(
"     You suddenly lose your footing and fall down a hole.\n"+
"\n"+
"     You fall, and lose your sense of gravity.\n"+
"\n"+
"\n"+
"     Bang!  You land on hard ground.\n");
::init();
}

reset(arg) {
        if(!arg) {
        set_light(0);
        short_desc=("Passageway");
        long_desc=
"     As you look around, you see a tunnel leading south.  Above you,\n"+
"an opening in the ceiling leads straight up.  Other than the hole, the\n"+
"room is an ordinary widening in the cavern.\n";

   dest_dir=({
        CASTLEROOM+"/passage2.c","south"  ,
            });

   items=({
        "hole","     You must have fallen from the hole above",
   });
   }   }
