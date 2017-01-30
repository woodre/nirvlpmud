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
ONE_EXIT("players/mizan/etheriel/subrealms/watchlar/k7.c","southeast",
	"Collapsed hallway",
"	This is the end of the hallway. The rubble makes it impossible to\n"+
"  proceed any further. Stone columns and battered furniture are scattered\n"+
"  throughout the area.\n",
	1)
