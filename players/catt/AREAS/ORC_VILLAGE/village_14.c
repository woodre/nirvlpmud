#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
FOUR_EXIT(ORC_VILLAGE+"village_13","west",
         ORC_VILLAGE+"village_6","south",
         ORC_VILLAGE+"village_15","east",
         ORC_VILLAGE+"village_23","north",
         "Orc Village.. village_14",
          "You are on the main road going through the village. The road \n"+
          "continues to the north and south. To the east is the entrance \n"+
          "to a small hut with a sign above the door. You think it might \n"+
          "be some sort of shop. To the west is a larger hut, also with \n"+
          "a small sign above the door. The noise coming from inside it \n"+
          "makes you think it might be a tavern of some sort.\n", 1)
