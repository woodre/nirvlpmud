inherit "room/room";
#include "definitions.h"

reset(arg) {

if (!present("thing")) 
    move_object(clone_object(CASTLEMONSTER+"/thing.c"),
    this_object());

   if(!arg) {
   set_light(0);
   short_desc=("The Caverns of Tumetai");
   long_desc=
"     The cave ends here for you.  Several smaller\n"+
"tunnels continue, but they are too small for you\n"+
"to enter.  Instead of a rock floor, this cavern\n"+
"has a deep water pool.  A slick limestone bank\n"+
"circles its hidden depths.\n";

   dest_dir=({
   CASTLEROOM+"/tumetai12.c","south"  ,
            });

   items=({
   "pool","     The pool is of black thick liquid",
   "cave","     The cave ends in this large room",
   "tunnels","     The tunnels are but small cracks in the walls",
   "bank","     The wet bank curves into the pool",
   });
   }   }
