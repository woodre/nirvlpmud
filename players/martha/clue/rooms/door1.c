#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("singer",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/singer.c"), this_object());
	}*/
	
	if (arg) return;
	set_light(1);
	short_desc = HIM+"The Front Door"+NORM;
	items = ({
		"foyer","The small tiled area between doors",
		"hall","The hall of Hill House",
		"yard","The front yard of Hill House",
		"aura","All you can see is fear",
		"bench","A small bench built into the wall",
		"door","A giant mahogany door",
		"tile","A floor tile, maybe black, maybe white",
		"tiles","Every other tile is black or white"});
		
	long_desc =
"	This is the foyer between the main entrance into the hall and the\n\
door out to the front yard.  A small bench is available for those who\n\
tire of standing during the wait for someone to answer the door.  The\n\
tiles are checkered, black and white, and seem to be freshly cleaned.\n\
There is an aura of fear that envelopes this tiny foyer.  Do you dare\n\
tread further into Hill House??\n";
	dest_dir = ({"players/martha/clue/rooms/hall","in",
				 "players/martha/clue/rooms/fyard","out"});
}
