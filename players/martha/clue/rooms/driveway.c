#include "ansi.h"
inherit "room/room";

	void reset (status arg) {
	if (arg) return;
	set_light(1);
	short_desc = HIY+"The Driveway"+NORM;
	items = ({
		"driveway","Freshly paved asphalt",
		"house","The infamouse Hill House",
		"air","What does air look like?",
		"cars","There are a lot of cars parked here",
		"car","This is the car of one of the guests"});
		
	long_desc =
"	The driveway of Hill House is freshly paved.  The air smells of\n\
asphalt and, is it possible, fear?  Many cars are lined up in the\n\
driveway as if there is a party of some sort going on inside.  There\n\
is still a chance to get out alive if you turn around and leave now!\n";
	dest_dir = ({"players/martha/clue/rooms/fyard","tread_on",
				 "players/martha/clue/rooms/gate","gate"});
}
