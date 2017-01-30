inherit "room/room";
#include "definitions.h"

int i;

reset(arg) {

if (!present("cave munchkin")) {
  for(i = 1; i<=12; i++) 
    move_object(clone_object(CASTLEMONSTER+"/munchkin.c"),
    this_object());
   }

   if(!arg) {   
   set_light(0);
   short_desc=("The Caverns of Tumetai");
   long_desc=
"     The cave ends here for you.  Several smaller\n"+
"tunnels continue, but they are too small for you\n"+
"to enter.  Along the walls and floor, strange\n"+
"limestone formations look like tiny cities.\n";

   dest_dir=({
   CASTLEROOM+"/tumetai4.c","east"  ,
            });

   items=({
   "tunnels","     The tunnels are but small cracks in the walls",
   "cave","     The cave ends in this large room",
   "formations","     The formations look exactly like tiny cities",
   "walls","     The walls bend in every direction",
   "floor","     The floor is covered with the tiny cities",
   "cities","     The cities must be perhaps munchkin-made",
   });
   }   }
