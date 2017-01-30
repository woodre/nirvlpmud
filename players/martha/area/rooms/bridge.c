#include "ansi.h"
#define tp this_player()->query_name()
inherit "room/room";

void reset (status arg) {
	
	if (arg) return;
	set_light(1);
	short_desc = "A Bridge";
	items = ({
		"swamp","Brown, sticky molasses forms the swamp",
		"castle","A giant castle made entirely of candy",
		"bridge","The bridge is coated with candy"});
	
	long_desc =
"   This candy coated bridge leads one out of the molasses swamp\n\
and one step closer to the Kandy Castle.  Stop and take a quick\n\
taste before moving on your merry way.\n";
	dest_dir = ({"/players/martha/area/rooms/kcastle", "north",
				 "/players/martha/area/rooms/mswamp", "west"});

	add_taste("bridge","The bridge tastes sickly sweet!");
				 				}
