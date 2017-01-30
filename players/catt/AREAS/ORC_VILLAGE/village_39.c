#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
THREE_EXIT(ORC_VILLAGE+"village_38","west",
         ORC_VILLAGE+"village_45","north",
         ORC_VILLAGE+"village_40","east",
         "Orc Village.. village_39",
      ORC_DESC_TEMP_BALCONY+" Everything around you is "+
      "carved in black marble with a style you would not "+
      "normally associate with orc craftsman. You feel "+
      "raw magical power flowing through the stone work. "+
      "An inscription has been carved above the temple "+
      "entrance in a cruel looking language that you "+
      "cannot read. You can no longer hear the sounds "+
      "of the village far below you and a deafening silence "+
      "permeates the environment of the balcony. \n", 1)
