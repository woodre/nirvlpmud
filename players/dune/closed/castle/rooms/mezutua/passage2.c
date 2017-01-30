inherit "room/room";
#include "definitions.h"

void init() {
        write(
"     As you leave the room, a huge stone slab falls behind you and\n"+
"blocks the northern exit.\n");
::init();
}

reset(arg) {
        if(!arg) {
        set_light(0);
        short_desc=("Passageway");
        long_desc=
"       You have entered another part of the rocky tunnel.  The room is\n"+
"bare, having no stalagmites/tites, or other significant protrusions.\n";

   dest_dir=({
        CASTLEROOM+"/east1.c","south"  ,
            });
}  }
