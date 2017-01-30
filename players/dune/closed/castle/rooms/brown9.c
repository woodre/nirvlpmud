inherit "room/room";
#include "definitions.h"

reset(arg) {
   if(!arg) {
   set_light(1);
   short_desc=("Northwestern Brown Plains");
   long_desc=
"     The land here has turned yellow with dryness.\n"+
"No trees nor shrubs grow, only grass.  To the north,\n"+
"the land becomes wet again and turns green.\n"+
"Southward, foothills rise into the mountains.  A large\n"+
"expanse of flat plains lies southeast.\n";

   dest_dir=({
   CASTLEROOM+"/hill7.c","west"  ,
   CASTLEROOM+"/hill6.c","south"  ,
   CASTLEROOM+"/green16.c","north"  ,
   CASTLEROOM+"/brown8.c","east"  ,
            });

   items=({
   "grass","     The grass is a mottled brownish-yellow",
   "land","     The land to the north is green and wetter",
   "foothills","     The hills gently rise to great heights",
   "plains","     The plains here roll in gentle bumps",
   "mountains","     The mountains tower above the hills",
   });
   }   }
