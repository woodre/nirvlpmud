inherit "room/room";
#include "definitions.h"

reset(arg) {
   if(!arg) {
   set_light(1);
   short_desc=("The Ruins of Kementari");
   long_desc=
"     The crag path winds through, under, and over\n"+
"several boulders.  The ground you walk upon is\n"+
"dry and dusty, devoid of vegetation.  Each new\n"+
"turn looks the same as the one before.\n";

   dest_dir=({
   CASTLEROOM+"/kementari6.c","north"  ,
   CASTLEROOM+"/kementari16.c","south"  ,
            });

   items=({
   "path","     The crags have many pathways for exploration",
   "boulders","     Huge boulders tower above and around you",
   "ground","     The ground is of loose dry clay",
   });
   }   }
