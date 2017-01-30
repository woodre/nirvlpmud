#include "ansi.h"
inherit "room/room";

void reset (status arg) {
	if (arg) return;
	set_light(1);
	short_desc = "A Road";
	items = ({
		"castle","The always dreary Licorice Castle",
		"house","A two story house made entirely of peanut brittle",
		"road","A candy paved road"});
		
	long_desc =
"   The road leads away from the dreariness of the Licorice Castle\n\
and towards the sweet smelling Peanut Brittle House. The mood starts\n\
to lift the closer you get to the great Kandy Castle.\n";
	dest_dir = ({"players/martha/area/rooms/lcastle", "northeast",
				 "players/martha/area/rooms/road","east",
				 "players/martha/area/rooms/pbhouse", "west"});
}
