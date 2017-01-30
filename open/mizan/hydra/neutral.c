#include "room.h"

TWO_EXIT("open/mizan/hydra/hydrahome.c", "north",
         "open/mizan/hydra/shitland.c", "south",
         "Sandy Area",
         "This is a sandy, hydra-compatible area.\n" +
         "The south is the Land of Shit.\n", 1)

is_shit_free() { return 1; }

