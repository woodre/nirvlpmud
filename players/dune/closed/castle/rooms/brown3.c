inherit "room/room";
#include "definitions.h"

reset(arg) {

if (!present("hawk")) 
  move_object(clone_object(CASTLEMONSTER+"/hawk.c"),
  this_object());

   if(!arg) {
   set_light(1);
   short_desc=("Southern Flat Plains");
   long_desc=
"     The flat yellow plains continue to stretch\n"+
"its featureless body across the land.  To the\n"+
"south, the land lowers into a sandy ocean beach.\n"+
"Foothills lie to the southwest.\n";

   dest_dir=({
   CASTLEROOM+"/brown6.c","west"  ,
   CASTLEROOM+"/shore6.c","south"  ,
   CASTLEROOM+"/brown2.c","north"  ,
   CASTLEROOM+"/shore4.c","east"  ,
            });

   items=({
   "plains","     The flat plains are a kind of yellow wasteland",
   "beach","     A long sandy beach rests near the ocean",
   "ocean","     The ocean's reach seems endless",
   "foothills","     The high foothills rise sharply from the plains",
   });
   }   }
