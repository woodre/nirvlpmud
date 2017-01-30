#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("peacock",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/peacock.c"), this_object());
	}*/
	
	if (arg) return;
	set_light(0);
	short_desc = MAG+"The Wine Cellar"+NORM;
	items = ({
		"rack","This is an old wine rack",
		"racks","These are old wine racks",
		"walls","The walls are white cement",
		"wall","The wall is white cement",
		"bottle","This is an old bottle of wine",
		"bottles","These are older bottles of wine",
		"room","This is the wine cellar",
		"bulb","There is not a bulb!",
		"socket","An empty socket",
		"cord","The cord is frayed and very short",
		"light","There is no light"});
		
	long_desc =
"	Racks upon racks line the walls of this smallish room.  Vintage\n\
bottles of wine lay in a few of the holes, but for the most part the\n\
racks are empty.  It is dark and there is a chill that consumes the\n\
room.  There is no bulb in the socket and it looks at though someone\n\
cut the cord to turn the light on anyway.\n";
	dest_dir = ({"players/martha/clue/rooms/basement","north"});
}
