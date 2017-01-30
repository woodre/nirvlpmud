#include "room.h"
object timber;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
	if(!timber || !present(timber)) {
	timber=clone_object("players/mizan/etheriel/subrealms/watchlar/timber.c");
	move_object(timber, this_object());
	}
}

TWO_EXIT("players/mizan/etheriel/subrealms/watchlar/k1.c","south",
	"players/mizan/etheriel/subrealms/watchlar/k5.c","north",
	"Keep of Etheriel",
"	Floating into this area, you are in a long, open area, with a path\n"+
"  going north, deeper into the keep, and a path goes back out to the south.\n"+
"  Chips of plaster peeling off the walls dance slow waltzes to the rhythm\n"+
"  of the current passing slowly through these walls. Collapsed timbers and\n"+
"  debris litter the path before you.\n",
	1)

query_realm() { return "NT"; }

