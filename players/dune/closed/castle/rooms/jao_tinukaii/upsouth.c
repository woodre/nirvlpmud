inherit "room/room";
#include "definitions.h"

reset(arg) {
        if(!arg) {
        set_light(1);
        short_desc="Southern hallway";
        long_desc=
"     The stone hallway curves into a spiral, blocking off the views from\n"+
"the other rooms.  The ceiling, floor, and side walls are all made of\n"+
"white stone.  The torch light casts a dark yellow-orange color across\n"+
"the room though.  Shadows dance around the walls in the flickering light.\n";

   dest_dir=({
        CASTLEROOM+"/upmain.c","north"  ,
        CASTLEROOM+"/sidesuite.c","east"  ,
            });

   items=({
        "torches","     The torches seem well tended",
   });
   }   }
