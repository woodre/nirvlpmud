inherit "room/room";
#include "definitions.h"

reset(arg) {
   if(!arg) {
   set_light(1);
   short_desc=("Southern Green Plains");
   long_desc=
"     The green grass plains extend to all directions.\n"+
"Small hills from bumps upon the otherwise smooth land.\n"+
"Far to the southwest, tall mountains loom in the\n"+
"horizon.  A river lies to the east, seemingly unmoving\n"+
"from this distance.  To the south, the land is dryer\n"+
"and not as green.\n";

   dest_dir=({
   CASTLEROOM+"/green12.c","west"  ,
   CASTLEROOM+"/brown1.c","south"  ,
   CASTLEROOM+"/green8.c","north"  ,
   CASTLEROOM+"/green4.c","east"  ,
            });

   items=({
   "hills","     The hills are low and gentle-sloping",
   "plains","     The plains surround you in all directions",
   "mountains","     The mountains are like black teeth on the sky",
   "land","     The land is open and curvy",
   "river","     The river is very wide and slow-moving",
   "horizon","     Mountains against sky forms the horizon",
   });
   }   }
