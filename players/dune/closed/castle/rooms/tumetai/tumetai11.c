inherit "room/room";
#include "definitions.h"

reset(arg) {
   if(!arg) {
   set_light(0);
   short_desc=("The Caverns of Tumetai");
   long_desc=
"     You spelunker through the small cracks and\n"+
"larger caverns.  Stalagmites and stalagtites are\n"+
"numerous.  The walls and rock are all limestone.\n"+
"As you travel through the cave, you feel the biting\n"+
"chill of the cold air.\n";

   dest_dir=({
   CASTLEROOM+"/tumetai10.c","south"  ,
   CASTLEROOM+"/tumetai12.c","west"  ,
   CASTLEROOM+"/tumetai14.c","east"  ,
            });

   items=({
   "stalagmites","     The stalagmites rest peacefully on the floor",
   "stalagtites","     They hang from the ceiling like needles",
   "rock","     The rock is all limestone",
   "walls","     The walls bend in every direction",
   "cracks","     Several cracks are large enough to fit through",
   "caverns","     Large caverns open up from cramped spaces",
   });
   }   }