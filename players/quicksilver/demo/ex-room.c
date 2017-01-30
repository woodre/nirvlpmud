#include "room.h"
object punk;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();


extra_reset() {
	if(!punk || !living(punk)) {
	int a;
	while(a < 10) {
	a++;
	punk=clone_object("players/mizan/n/npunk.c");
	move_object(punk, this_object());
	}

    }
}
FOUR_EXIT("players/mizan/n/r1a.c","west",
	"players/mizan/n/r2.c","north",
	"players/mizan/n/r3.c","south",
	"players/mizan/n/r4.c","east",
	"Mudding 101",
"	Arriving in the hallway, you have an uncontrollable urge to test out\n"+
"  your new weapons... Why not? The hall continues to the north and south,\n"+
"  and a doorway to a grassy clearing is to the east.\n",
	1)
