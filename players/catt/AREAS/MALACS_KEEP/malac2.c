#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
   object blackslayer;
   
   int i;
   i = 0;
   if(!present("slayer")) {
      while(i < 2) {
         i += 1;
         blackslayer = clone_object(NPC+"MK_slayer");
         move_object(blackslayer, this_object());
      }
   }
}

TWO_EXIT(MALACS_KEEP+"malac1","west",
   HALL_WORLDS+"hall1","in",
   "malac's keep", 
   "This is malac's meeting room. It is rather large. You \n" +
   "notice that this keep is set up like no other... strange.\n" +
      "Malac should be aware the black slayers are entering his\n"+
   "castle?\n", 1)



