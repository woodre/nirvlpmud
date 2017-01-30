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
ONE_EXIT("players/mizan/etheriel/subrealms/watchlar/k1.c","east",
	"Room of the Maethe",
"	This appears to have been some storage room, but it has been reduced\n"+
"  to nothing more than a cave. The western wall has almost completely\n"+
"  collapsed, and there is no way around it. Remains of crates and storage\n"+
"  bins are scattered everywhere.\n",
	1)

query_realm() { return "NT"; }
