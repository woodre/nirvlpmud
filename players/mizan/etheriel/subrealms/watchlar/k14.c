#include "room.h"
object beast;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
	if(!beast || !living(beast)) {
	beast=clone_object("players/mizan/etheriel/subrealms/watchlar/shadowspawn.c");
	move_object(beast, this_object());
		}
	}

ONE_EXIT("players/mizan/etheriel/subrealms/watchlar/k11.c","east",
	"A quiet study",
"	Upon arriving here, you inhale something. You cough and spit it out.\n"+
"  what looks to be a small yellow blob was actually once a piece of parchment.\n"+
"  This was once a study, and the remains of books are scattered about the\n"+
"  floor. The pages have long since disintegrated, leaving a foul yellow\n"+
"  murk on the floor, and when you disturb the shelves, you unsettle more\n"+
"  of the stuff. You sigh, and wish that you could have been able to salvage\n"+
"  just one of the books to see what this place was like..\n",
	1)

