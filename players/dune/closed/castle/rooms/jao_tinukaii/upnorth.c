inherit "room/room";
#include "definitions.h"

reset(arg) {

if (!present("wraith")) {
      move_object(clone_object(CASTLEMONSTER+"/wraith.c"),this_object());
   }

        if(!arg) {
        set_light(1);
        short_desc="Northern hallway";
        long_desc=
"     The hallway here is completely bare except for several torches that\n"+
"line the walls.  The ceiling, floor, and side walls are all made of\n"+
"white stone.  The torch light casts a dark yellow-orange color across\n"+
"the room though.  Eerie shadows dance with the flickering light.\n";

   dest_dir=({
        CASTLEROOM+"/upmain.c","south"  ,
        CASTLEROOM+"/mastersuite.c","east"  ,
            });

   items=({
        "torches","     The torches seem well tended",
   });
   }   }
