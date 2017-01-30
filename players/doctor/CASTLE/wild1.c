#include "/room/room.h"

#undef EXTRA_RESET
#define EXTRA_RESET no_castle_flag = 1;

TWO_EXIT("/players/doctor/CASTLE/hump", "east",
	 "/players/doctor/CASTLE/forest1", "west",
	 "Generic wilderness",
	 "You are in the generic wilderness outside the generic village.\n" +
	 "There is a big generic forest to the west.\n", 1)
