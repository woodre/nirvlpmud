#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("plum",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/plum.c"), this_object());
	}*/
	
	if (arg) return;
	set_light(0);
	short_desc = BLU+"The Pantry"+NORM;
	items = ({
		"cupboard","Older metal cupboard",
		"cupboards","Older metal cupboards",
		"wall","A white cement wall",
		"walls","The walls are white cement",
		"pantry","This is where food used to be stored",
		"floor","The floor is cold, hard and dusty gray cement",
		"freezer","A large stand up freezer",
		"corner","This is the corner of the room",
		"plug","The plug to the freezer",
		"switch","This is the light switch",
		"door","The door is wooden and old"});
		
	long_desc =
"	Cupboards line the walls of the pantry.  The cement floor is cold\n\
and dusty.  A large freezer sits in one corner of the room and though\n\
it is plugged in, it is not running as the electricity does not seem\n\
to work in this part of the house.  The light switch is to the right\n\
of the door, however it does not seem to be working at this time\n";
	dest_dir = ({"players/martha/clue/rooms/basement","west"});
}
