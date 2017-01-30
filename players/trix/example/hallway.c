#include "room.h"
object punk, raver;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
	punk = clone_object("players/mizan/beasties/punk.c");
	move_object(punk, this_object());
	punk = clone_object("players/mizan/beasties/punk.c");
	move_object(punk, this_object());
	raver = clone_object("players/mizan/beasties/raver.c");
	move_object(raver, this_object());
	}

THREE_EXIT("players/mizan/watchlar/wa10.c","out",
	"players/mizan/watchlar/wa10b.c","northeast",
	"players/mizan/watchlar/wa10c.c","northwest",
	"23 Tangermunde",
"	Stumbling into this hall, you smell a funny smoke, and it takes a\n"+
"  while for you to adjust to the darkness. There are two stairways before you\n"+
"  that will take you to the dancefloor above. The music coming from above is\n"+
"  definitely not soft stuff. Your virgin ears are not adjusting too well to the\n"+
"  potentially brick-shattering beat called techno.\n",
	1)
