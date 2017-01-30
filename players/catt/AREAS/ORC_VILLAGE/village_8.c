#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
THREE_EXIT(ORC_VILLAGE+"village_9","east",
         ORC_VILLAGE+"village_7","west",
         ORC_VILLAGE+"village_16","north",
         "Orc Village.. village_8",
      "You are on a road going east-west in an orc village. "+
      "You see a small hut to the north. "+ORC_DESC_CRIES+" "+
      ORC_DESC_S_HEDGE+"\n", 1)
