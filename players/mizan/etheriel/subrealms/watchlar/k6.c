#include "room.h"
int a;
object beast;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
	if(!beast || !living(beast)) {
	while(a<6) {
		beast=clone_object("players/mizan/etheriel/subrealms/watchlar/maethe.c");
		move_object(beast, this_object());
		a++;
		}
	}
}
ONE_EXIT("players/mizan/etheriel/subrealms/watchlar/k5.c","southwest",
	"Room of the Maethe",
"	You have floated into a messy room, in a total stat of disarray.\n"+
"  This had once been a great library of some sort, but nearly all of the\n"+
"  works have been destroyed. A combination of time, the water, and the\n"+
"  collapsed pillars that crushed the bookshelves seem to have done it.\n",
	1)
