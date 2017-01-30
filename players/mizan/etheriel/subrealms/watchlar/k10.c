#include "room.h"
object thing;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
	if(!thing || !living(thing)) {
	thing=clone_object("players/mizan/etheriel/subrealms/watchlar/balek.c");
	move_object(thing, this_object());
	}
	}

ONE_EXIT("players/mizan/etheriel/subrealms/watchlar/k9.c","northeast",
	"A shadowy room",
"	This is a shadowy room, and you get the chills once you enter it.\n"+
"  There is a splendid view of the ocean from out here, through half-broken\n"+
"  panes of glass, you see the strangely barren landscape outside. On the\n"+
"  inside, like this room, It is not so barren, as you sense another being\n"+
"  is here with you.\n",
	1)
