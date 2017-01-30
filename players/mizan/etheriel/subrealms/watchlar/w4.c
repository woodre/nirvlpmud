#include "room.h"
object rock;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
	if(!rock || !present(rock)) {
	rock=clone_object("players/mizan/etheriel/subrealms/watchlar/rock.c");
	move_object(rock, this_object());
	}
}

TWO_EXIT("players/mizan/etheriel/subrealms/watchlar/w3.c","north",
	"players/mizan/etheriel/ROOMS/lunar.c","fall",
	"A Sheer Drop",
"	Drifting south, you come upon what looks like a bottomless chasm.\n"+
"  strangely, you see what looks like light at the bottom. You know what\n"+
"  they say about light at the end of a tunnel, now... Although it looks\n"+
"  to be a rather nasty drop, you have a gut feeling that this indeed\n"+
"  seems to be the way out.\n",
	1)
