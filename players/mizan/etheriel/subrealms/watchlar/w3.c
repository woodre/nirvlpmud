#include "room.h"
object gate;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
	if(!gate || !present(gate)) {
	gate = clone_object("players/mizan/etheriel/subrealms/watchlar/gate.c");
	move_object(gate, this_object());
	}
}

ONE_EXIT("players/mizan/etheriel/subrealms/watchlar/w4.c","south",
	"Ocean of Etheriel",
"	Forcing yourself down, you suddenly realize that you are underwater!\n"+
"  Duh! You hopelessly try to reach the surface again, but to no avail...\n"+
"  You inhale water.. it fills your lungs.. you panic.. your entire life\n"+
"  passes before your eyes, but suddenly, you realize... that you are \n"+
"  indeed breathing water? Like divine intervention of some sort, it happens.\n"+
"  However it is a totally different thing, and requires some timing, but\n"+
"  you are getting used to it.\n",
	1)
