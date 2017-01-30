#include "room.h"
object statue;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
	if(!statue || !present(statue)) {
	  statue=clone_object("players/mizan/etheriel/subrealms/watchlar/ladyl.c");
	  move_object(statue, this_object());
	  }
	}

TWO_EXIT("players/mizan/etheriel/subrealms/watchlar/k11.c","south",
	"players/mizan/etheriel/subrealms/watchlar/k15.c","north",
	"A short hallway",
"	Just before you open the solid doors of the bedroom to your north,\n"+
"  something tells you not to. The voice you hear beckons you to proceed\n"+
"  further north. You feel that this is your last chance to turn back, and \n"+
"  miss out on something. It could be good, it could be bad. That is what\n"+
"  you are fighting about within your mind.\n",
	1)
