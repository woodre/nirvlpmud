inherit "room/room";
#include "definitions.h"

reset(arg) {
   if(!arg) {
   set_light(1);
   short_desc=("Northern Green Plains");
   long_desc=
"     From here, the grasslands stretch endlessly.\n"+
"Occassionally, a wild dandelion breaks the monotony\n"+
"of the green sea.  There are no trees in sight.  Far\n"+
"to the southwest, dark mountains line the horizon.\n";

   dest_dir=({
   CASTLEROOM+"/green15.c","west"  ,
   CASTLEROOM+"/green14.c","south"  ,
   CASTLEROOM+"/green11.c","east"  ,
            });

   items=({
   "dandelion","     These small flowers grow in yellow and gold",
   "dandelions","     These small flowers grow in yellow and gold",
   "grasslands","     The grass plains surround you for miles",
   "mountains","     The mountains are like black teeth on the sky",
   "horizon","     Mountains against sky forms the horizon",
   });
   }   }
