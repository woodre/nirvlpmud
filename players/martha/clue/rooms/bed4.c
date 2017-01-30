#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("driver","this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/driver.c"), this_object());
	}*/
	
	if (arg) return;
	set_light(0);
	short_desc = CYN+"The Bedroom"+NORM;
	items = ({
		"bedroom","An old, unused bedroom",
		"rooms","You can't see any other rooms from here",
		"floor","The floor is very dusty",
		"spot","A giant rectangular dust ring",
		"chair","A wooden backed chair",
		"corner","A chair sits in the corner",
		"room","An old, unused bedroom",
		"bed","There is not a bed here",
		"table","A small round wooden table",
		"mug","There is not a mug here right now",
		"light","The lamp is broken",
		"footprints","Size 12 footprints formed out of dust"});
		
	long_desc =
"	This bedroom is very different from the rest of the rooms in the\n\
house.  The floor is very dusty and there is a big rectangular spot\n\
on the floor where there once was a bed.  A wooden back chair sits\n\
in the corner of the room, next to it a petite table with only room\n\
enough for a coffee mug.  The light in the room seems to be broken.\n\
There are dust footprints on the floor, as if someone has been in\n\
this room recently\n";
	dest_dir = ({"players/martha/clue/rooms/bed3","north",
				 "players/martha/clue/rooms/hall2","northwest"});
}
