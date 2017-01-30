#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
  object demonpriest;
  int i;
  i = 0;
  if(!present("demonpriest")) {
    while(i < 2) {
     i += 1;
      demonpriest = clone_object(NPC+"TEM_demonpriest");
     move_object(demonpriest, this_object());
    }}}
ONE_EXIT(TEMPLE+"monkroom4","south",
      "Demon Lord Brakian's Temple Priest Quarters",
         "You notice a couple rows of small cots and desks. This is where\n"+
         "the priests must do there work or whatever it is they do. you \n"+
         "don't think they would be very happy if they knew you were here.\n", 1)
