inherit "room/room";
#include "definitions.h"

reset(arg) {

if (!present("stallion")) 
  move_object(clone_object(CASTLEMONSTER+"/horse.c"),
  this_object());

   if(!arg) {
   set_light(1);
   short_desc=("Southwestern Green Plains");
   long_desc=
"     Across the grass plains to the southwest, the\n"+
"land rises and meets the majestic mountains.  Due\n"+
"south, the land browns and becomes dry.  But here,\n"+
"the land is still rich green and fertile.  Baby\n"+
"trees stand near their makers in what is a peaceful\n"+
"setting.\n";

   dest_dir=({
   CASTLEROOM+"/green18.c","west"  ,
   CASTLEROOM+"/brown9.c","south"  ,
   CASTLEROOM+"/green15.c","north"  ,
   CASTLEROOM+"/green14.c","east"  ,
            });

   items=({
   "trees","     The trees are coniferous, being thin and straight",
   "plains","     The plains are green here, but brown to the south",
   "mountains","     The mountains stand tall in the horizon",
   "land","     The land is abundant with grass and trees",
   });
   }   }
