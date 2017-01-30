inherit "room/room";
#include "definitions.h"

reset(arg) {

if (!present("rabbit")) 
  move_object(clone_object(CASTLEMONSTER+"/rabbit.c"),
  this_object());

   if(!arg) {
   set_light(1);
   short_desc=("Northwestern Green Plains");
   long_desc=
"     Here the plains continue to stretch along\n"+
"the foothills to the south and west. Past the\n"+
"foothills, tall mountains meet the horizon.\n";

   dest_dir=({
   CASTLEROOM+"/hill10.c","west"  ,
   CASTLEROOM+"/hill9.c","south"  ,
   CASTLEROOM+"/green17.c","east"  ,
            });

   items=({
   "foothills","     The foothills slope steeply",
   "plains","     The plains extend mainly east and west here",
   "mountains","     The mountains stand tall in the horizon",
   "forest","     The forest is huge and very dense",
   });
   }   }
