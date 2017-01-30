#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
}
THREE_EXIT(ORC_VILLAGE+"village_2","east",
           ORC_VILLAGE+"village_6","north",
           "/room/orc_vall","south",
           "Orc Village.. village_1",
            "You are at the entrance to the orc village. To the east is the \n"+
            "guard house and the village is to the north. South leads out of\n"+
           "the village. The area around you looks a little unsafe and \n"+
           "piercing cries inside the village put you a little on edge.\n", 1)
