#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
  object gloves, weapon;
/* Removed due to gloves not working. Catt 01-05-04
  if(!present("gloves")) {
   gloves = clone_object(MAGICAL+"frostgloves");
  move_object(gloves, this_object());
                         }
*/
  if(!present("thorn")) {
   weapon = clone_object(WPN+"thorn");
  move_object(weapon, this_object());
                        }
  }
ONE_EXIT(MOUNT+"mount_peak","peak",
         "mount_alcove",
      "A small alcove on the peak of the mountain. Here you find\n"+
      "some very potent artifacts. Use them carefully, for in the \n"+
      "hands of one capable they are very powerful.\n", 1)
