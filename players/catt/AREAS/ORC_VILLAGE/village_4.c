#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
THREE_EXIT(ORC_VILLAGE+"village_12","north",
         ORC_VILLAGE+"village_3","west",
         ORC_VILLAGE+"village_5","east",
         "Orc Village.. village_4",
      "You are in the western part of the village. To the "+
      "north is a hut. The road continues to the east and "+
      "west. "+ORC_DESC_SCREAMS+" "+ORC_DESC_S_HEDGE+" \n", 1)
