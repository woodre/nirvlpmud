inherit "room/room";
#include "definitions.h"

reset(arg) {

if (!present("darkshadow")) {
      move_object(clone_object(CASTLEMONSTER+"/darkshadow.c"),this_object());
   }

   if(!arg) {
   set_light(1);
   short_desc=("The Ruins of Kementari");
   long_desc=
"     The crag path winds through, under, and over\n"+
"several boulders.  The ground you walk upon is\n"+
"dry and dusty, devoid of vegetation.  Each new\n"+
"turn looks the same as the one before.  A wide\n"+
"crevice between two boulders leads north.\n";

   dest_dir=({
   CASTLEROOM+"/kementari2.c","west"  ,
   CASTLEROOM+"/kementari9.c","south"  ,
   CASTLEROOM+"/kementari18.c","north"  ,
   CASTLEROOM+"/kementari4.c","east"  ,
            });

   items=({
   "path","     The crags have many pathways for exploration",
   "boulders","     Huge boulders tower above and around you",
   "ground","     The ground is of loose dry clay",
   "crevice","     The crevice path leads through the gap",
   });
   }   }
