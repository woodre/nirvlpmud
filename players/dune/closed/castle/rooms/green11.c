inherit "room/room";
#include "definitions.h"

reset(arg) {
   if(!arg) {
   set_light(1);
   short_desc=(" Middle Green Plains");
   long_desc=
"     From here, the grasslands stretch endlessly.\n"+
"Occassionally, a wild dandelion breaks the monotony\n"+
"of the green sea.  There are no trees in sight.  Far\n"+
"to the southwest, dark mountains line the horizon.\n"+
"A beautiful white-blue shrine stands alone in the plains.\n";

   dest_dir=({
   CASTLEROOM+"/green13.c","west"  ,
   CASTLEROOM+"/green12.c","south"  ,
   CASTLEROOM+"/green10.c","north"  ,
   CASTLEROOM+"/green8.c","east"  ,
   CASTLEROOM+"/moonshrine.c","shrine"  ,
            });

   items=({
   "dandelion","     These small flowers grow in yellow and gold",
   "dandelions","     These small flowers grow in yellow and gold",
   "grasslands","     The grass plains surround you for miles",
   "mountains","     The mountains are like black teeth on the sky",
   "horizon","     Mountains against sky forms the horizon",
   "shrine","     The beautiful blue-white Moon Shrine stands before you",
   });
 }   }
