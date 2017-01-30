inherit "room/room";
#include "definitions.h"

int i;

reset(arg) {

if (!present("rabbit")) {
  for(i = 1; i<=3; i++) 
    move_object(clone_object(CASTLEMONSTER+"/rabbit.c"),
    this_object());
   }

   if(!arg) {
   set_light(1);
   short_desc=("Middle Green Plains");
   long_desc=
"     The green grass plains extend to all directions.\n"+
"Small hills from bumps upon the otherwise smooth land.\n"+
"Far to the southwest, tall mountains loom in the\n"+
"horizon.  A river lies to the east, seemingly unmoving\n"+
"from this distance.\n";

   dest_dir=({
   CASTLEROOM+"/green11.c","west"  ,
   CASTLEROOM+"/green9.c","south"  ,
   CASTLEROOM+"/green7.c","north"  ,
   CASTLEROOM+"/green3.c","east"  ,
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
