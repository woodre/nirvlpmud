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
TWO_EXIT("players/mizan/etheriel/subrealms/watchlar/k1.c","west",
	"players/mizan/etheriel/subrealms/watchlar/k3a.c","southeast",
	"Room of the Maethe",
"	The wall has completely crumbled here, and you can see the ocean\n"+
"  in its deep indigo glory. Gentle currents sweep you and glide you across\n"+
"  the ruins of the wall. You notice that there are creatures around you,\n"+
"  and the wall reforms to the southeast.\n",
	1)

query_realm() { return "NT"; }
