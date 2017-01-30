#include "room.h"
object invis;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
	invis=clone_object("/players/dragnar/rooms/invis.c");
	move_object(invis, this_object());

}

	ONE_EXIT("/room/church" , "church",
	"A Dark Hallway",
	"As you enter the room the sky turns black.\n",
	1)
