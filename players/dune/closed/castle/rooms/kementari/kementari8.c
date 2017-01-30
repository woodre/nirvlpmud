inherit "room/room";
#include "definitions.h"

int i;

reset(arg) {

if (!present("sithi")) {
  for(i = 1; i<=2; i++) 
    move_object(clone_object(CASTLEMONSTER+"/sithi_man.c"),
    this_object());
   }

   if(!arg) {
   set_light(1);
   short_desc=("The Ruins of Kementari");
   long_desc=
"     The crevice ends in a large clearing.  Large\n"+
"boulders surround the clay ground.  The dirt is\n"+
"well trampled on here.\n";

   dest_dir=({
   CASTLEROOM+"/kementari9.c","west"  ,
   CASTLEROOM+"/kementari4.c","north"  ,
   CASTLEROOM+"/kementari11.c","south"  ,
            });

   items=({
   "clearing","     The clearing is full of 2 and 3 foot tall rocks",
   "crevice","     The crevice leads back to the main path",
   "ground","     The ground is of loose dry clay",
   "dirt","     The dirt is red clay",
   "boulders","     The boulders block off views of other areas",
   });
   }   }
