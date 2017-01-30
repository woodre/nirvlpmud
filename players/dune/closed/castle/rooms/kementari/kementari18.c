inherit "room/room";
#include "definitions.h"

reset(arg) {
   if(!arg) {
   set_light(1);
   short_desc=("The Ruins of Kementari");
   long_desc=
"     A large split in the rock, the crevice\n"+
"zig zags every which way.  The walls are \n"+
"jagged and rough.  Where the walls meet at both\n"+
"top and bottom, a narrow floor and ceiling form.\n";

   dest_dir=({
   CASTLEROOM+"/kementari8.c","north"  ,
   CASTLEROOM+"/kementari3.c","south"  ,
            });

   items=({
   "split","     The split in the rock is the crevice",
   "crevice","     The crevice leads into the boulder itself",
   "rock","     The rock is of a large boulder",
   "walls","     The walls are the side of the boulder",
   "floor","     The floor is part of the stone boulder",
   "ceiling","     The ceiling is low and narrow",
   });
   }   }
