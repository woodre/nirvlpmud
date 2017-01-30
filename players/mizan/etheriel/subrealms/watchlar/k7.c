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
TWO_EXIT("players/mizan/etheriel/subrealms/watchlar/k5.c","east",
	"players/mizan/etheriel/subrealms/watchlar/k7a.c","northwest",
	"Room of the Maethe",
"	You arrive in a dark hallway, and it appears that there is something,\n"+
"  rather, something pluralized in the room with you. The hallway is collapsed\n"+
"  in some portions, but it continues to the northwest. The path to the \n"+
"  east takes you back to the main hall.\n",
	1)
