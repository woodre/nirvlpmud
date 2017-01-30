#include "std.h"

id(str)
{
    if (str == "ruin")
	return 1;
    else
	return 0;
}

FOUR_EXIT("/players/doctor/CASTLE/plain4", "south",
	  "/players/doctor/CASTLE/plain8", "north",
	  "/players/doctor/CASTLE/plain9", "east",
	  "/players/doctor/CASTLE/plain3", "west",
	  "Generic ruin",
	  "A very old looking generic ruin. There is no generic roof, and no generic door.\n",
	  1)
