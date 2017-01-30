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
ONE_EXIT("players/mizan/etheriel/subrealms/watchlar/k3.c","northwest",
	"Blue Bell Knoll",
"	You enter what seems to be a small enclosed courtyard. The walls\n"+
"  are not very high here, and all around you, they seem to form steppes.\n"+
"  Curious mounds of a blackened material jut out around this area, and when\n"+
"  you stumble upon one, you realize that it used to be a tree stump!\n",
	1)
