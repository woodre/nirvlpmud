inherit "room/room";
#include "definitions.h"

reset(arg) {

if (!present("darkshadow")) {
      move_object(clone_object(CASTLEMONSTER+"/darkshadow.c"),this_object());
   }

   if(!arg) {
   set_light(0);
   short_desc=("The Ruins of Hikehikayo");
   long_desc=
"     The cave gently curves into the hillside.\n"+
"The dimensions of the cave stay relatively the same.\n"+
"Along the walls, tiny sparkles of light catch your\n"+
"eye.  You can only wonder what causes it.\n";

   dest_dir=({
   CASTLEROOM+"/hikehikayo3.c","south"  ,
   CASTLEROOM+"/hikehikayo1.c","north"  ,
            });

   items=({
   "walls","     The walls are smoothened and polished",
   "sparkles","     The sparkles seem to come from tiny gems",
   "cave","     The cave is gently curving, with no dips or climbs",
   });
   }   }
