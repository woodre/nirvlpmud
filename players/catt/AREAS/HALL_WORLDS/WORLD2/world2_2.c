#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
object sorceress;
if(!present("sorceress")) {
   sorceress = clone_object(NPC+"sorceress");
  move_object(sorceress, this_object());
}
}
TWO_EXIT(WORLD2+"world2","up",
         WORLD2+"world2_3","down",
         "Base of the Greytooth Tower",
  "After descending down the stairs many flights and seeing many stange\n" +
  "rooms and magical items you find yourself at the base of the tower. It\n" +
  "is gloomy and dust ridden but you can see a trail through the dust to a \n" +
  "small stair well going down. You can faintly hear many yells and screams\n", 1)
