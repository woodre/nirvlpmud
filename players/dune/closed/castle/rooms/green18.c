inherit "room/room";
#include "definitions.h"

reset(arg) {
   if(!arg) {
   set_light(1);
   short_desc=("Southwestern Green Plains");
   long_desc=
"     A patch of trees has invaded the featureless\n"+
"rolling plains.  The trees continue southward until\n"+
"the southern mountains jut from the ground in snow-\n"+
"capped peaks.  West and south, the plains become \n"+
"hills.  To the southeast, the land turns dry and\n"+
"the grass loses its green color.\n";

   dest_dir=({
   CASTLEROOM+"/hill9.c","west"  ,
   CASTLEROOM+"/hill7.c","south"  ,
   CASTLEROOM+"/green17.c","north"  ,
   CASTLEROOM+"/green16.c","east"  ,
            });

   items=({
   "trees","     The trees are coniferous, being thin and straight",
   "peaks","     The peaks are very distant and barely visible",
   "mountains","     The mountains stand tall in the horizon",
   "land","     The land is abundant with grass and trees",
   });
   }   }
