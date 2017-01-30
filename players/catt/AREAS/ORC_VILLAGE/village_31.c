#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
THREE_EXIT(ORC_VILLAGE+"village_30","west",
         ORC_VILLAGE+"village_32","east",
         ORC_VILLAGE+"village_23","south",
         "Orc Village.. village_31",
          "The path ends here. To the west is a weapons and armour smithy. \n"+
          "Directly to the east you see a small clearing with a large stone \n"+
          "in the middle of it. To the north you see the immense wall of the \n"+
          "structure. South is back to the main roadway. Other than the \n"+
          "smithy this area does not look well used. You see clutter and \n"+
          "trash strewn all over the ground. The structure still makes you uneasy.\n", 1)
