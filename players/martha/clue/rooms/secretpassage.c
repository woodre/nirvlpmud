#include "ansi.h"
inherit "room/room";

	void reset(status arg) {
	if (arg) return;
	set_light(1);
	short_desc = HIC+"A Secret Passageway"+NORM;
	items = ({
		"torch","A burning torch",
		"wall","A dingy cement wall",
		"yard","The front yard of Hill House",
		"puddle","A small puddle of dirty water",
		"puddles","Small puddles of dirty water",
		"water","A small puddle of dirty water"});
		
	long_desc =
"	This is the secret passageway that runs between the study and the\n\
conservatory.  A torch hangs on the wall, providing the only light in\n\
this damp, musty passageway.  Puddles of water gather in random spots\n\
on the floor and one would need to be careful or they may end up with\n\
wet feet!\n";
	dest_dir = ({"players/martha/clue/rooms/study","study",
				 "players/martha/clue/rooms/conservatory","conservatory"});
}
