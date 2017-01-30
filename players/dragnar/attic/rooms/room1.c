#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
}

	TWO_EXIT("players/dragnar/rooms/entrance.c" , "south",
	"/players/dragnar/rooms/room2.c" , "north",
	"An Evil Place",
	"You are walking on a path that looks to be leading to the woods\n" +
"north of you.  There also seems to be a river in the distance to the east.\n",
	1)
