inherit "room/room";
#include "definitions.h"

reset(arg) {

if (!present("wraith")) {
      move_object(clone_object(CASTLEMONSTER+"/wraith.c"),this_object());
      move_object(clone_object(CASTLEMONSTER+"/wraith.c"),this_object());
   }

   if(!arg) {
   set_light(0);
   short_desc=("The Caverns of Tumetai");
   long_desc=
"     The cave ends here for you.  Several smaller\n"+
"tunnels continue, but they are too small for you\n"+
"to enter.  Several chasms open up in the floor.\n"+
"You can only guess as to how deep they really\n"+
"are.\n";

   dest_dir=({
   CASTLEROOM+"/tumetai8.c","north"  ,
            });

   items=({
   "chasms","     The chasms prevent further exploration",
   "cave","     The cave ends in this large room",
   "tunnels","     The tunnels are but small cracks in the walls",
   "floor","     The floor is one big chasm",
   });
   }   }
