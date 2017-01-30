#include "room.h"
int a;
object servant;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
	if(!servant || !living(servant)) {
		while(a<8) {
		 servant=clone_object("players/mizan/etheriel/subrealms/watchlar/cservant.c");
		 move_object(servant, this_object());
	a++;
		}
	}
	}

ONE_EXIT("players/mizan/etheriel/subrealms/watchlar/k11.c","northwest",
	"Servant's Quarters",
"	You have drifted into the servant's quarters. They seem happy to see\n"+
"  you! You begin to wonder if their happiness will come at your expense...\n"+
"  There were originally more exits to this room, but all save one have been\n"+
"  blocked off.\n",
	1)
