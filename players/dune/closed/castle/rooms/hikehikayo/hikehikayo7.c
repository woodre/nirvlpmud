inherit "room/room";
#include "definitions.h"

reset(arg) {
   if(!arg) {
   set_light(0);
   short_desc=("The Ruins of Hikehikayo");
   long_desc=
"     The cave gently curves into the hillside.\n"+
"The dimensions of the cave stay relatively the same.\n"+
"Along the walls, tiny sparkles of light catch your\n"+
"eye.  You can only wonder what causes it.\n";

   dest_dir=({
   CASTLEROOM+"/hikehikayo6.c","south"  ,
            });

   items=({
   "entrance","     The entrance is like a hole in the hill",
   "ceiling","     The ceiling is smooth, almost man-made",
   "walls","     The walls have nicks on them, as if smoothed by man",
   "floor","     The floor looks well trampled on",
   "plains","     The foothills lower into vast green plains",
   });
   }   }
