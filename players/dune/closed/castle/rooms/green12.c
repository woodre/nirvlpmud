inherit "room/room";
#include "definitions.h"

reset(arg) {


if (!present("darkshadow")) {
      move_object(clone_object(CASTLEMONSTER+"/darkshadow.c"),this_object());
   }

   if(!arg) {
   set_light(1);
   short_desc=("Southern Green Plains");
   long_desc=
"     From here, the grasslands stretch endlessly.\n"+
"Occassionally, a wild dandelion breaks the monotony\n"+
"of the green sea.  There are no trees in sight.  Far\n"+
"to the southwest, dark mountains line the horizon.\n"+
"To the south, the land becomes dry and loses its\n"+
"green color.\n";

   dest_dir=({
   CASTLEROOM+"/green14.c","west"  ,
   CASTLEROOM+"/brown4.c","south"  ,
   CASTLEROOM+"/green11.c","north"  ,
   CASTLEROOM+"/green9.c","east"  ,
            });

   items=({
   "dandelion","     These small flowers grow in yellow and gold",
   "dandelions","     These small flowers grow in yellow and gold",
   "grasslands","     The grass plains surround you for miles",
   "mountains","     The mountains are like black teeth on the sky",
   "horizon","     Mountains against sky forms the horizon",
   });
   }   }
