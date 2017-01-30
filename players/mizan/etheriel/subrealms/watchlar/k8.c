#include "room.h"
object chand;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
	if(!chand || !present(chand)) {
	chand=clone_object("players/mizan/etheriel/subrealms/watchlar/chand.c");
	move_object(chand, this_object());
	}
}

TWO_EXIT("players/mizan/etheriel/subrealms/watchlar/k5.c","south",
	"players/mizan/etheriel/subrealms/watchlar/k9.c","up",
	"A grand spiral staircase",
"	A grand spiral staircase stands here, crafted of some kind of smooth\n"+
"  stone, and it seems to be one of the few items in the keep unaffected by\n"+
"  as much by wear and tear. Massively built, and with the remains of a \n"+
"  giant crystal chandelier in the center, it leads upwards. An archway leading\n"+
"  to the courtyard is south.\n",
	1)
