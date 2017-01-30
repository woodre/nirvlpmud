inherit "room/room";
#include "definitions.h"

reset(arg) {
   if(!arg) {
   set_light(1);
   short_desc=("Eastern Green Plains");
   long_desc=
"     The green plains continue to the north and south.\n"+
"To the east, a river flows southward.  On the other\n"+
"side of the river, you see wet swampland.\n"+
"An ancient stone bridge crosses the river.\n";

   dest_dir=({
   CASTLEROOM+"/green8.c","west"  ,
   CASTLEROOM+"/green4.c","south"  ,
   CASTLEROOM+"/swampentrance.c","bridge"  ,
   CASTLEROOM+"/green2.c","north"  ,
         });

   items=({
   "plains","     The plains stretch for miles",
   "bridge","     The beautiful ivy-covered bridge stands undisturbed",
   "river","     This is a wide river, uncrossable from here",
   "swampland","     You see the edge of a vast swamp",
        });
   }   }
