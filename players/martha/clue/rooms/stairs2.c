#include "ansi.h"
inherit "room/room";

	void reset(status arg) {
	if (arg) return;
	set_light(1);
	short_desc = HIW+"The Stairway"+NORM;
	items = ({
		"landing","A small area between two stairwells",
		"stairwell","Thirteen carpeted steps leading up or down, depending where you look from",
		"stairwells","Each stairwell has thirteen carpeted steps",
		"attic","The attic is a little darker than the second floor",
		"second","The second floor seems to have more light",
		"floor","The floor is carpeted",
		"hall","The second floor hall of Hill House",
		"single","One bulb",
		"bulb","One bulb hanging from the ceiling",
		"ceiling","The ceiling is high and painted white",
		"string","One lonely sting dangling from the bulb base",
		"light","The light is bright when turned on and dark when turned off"});
		
	long_desc =
"	This is the landing between two stairwells.  You can either venture\n\
up to the attic or go back down to the second floor hall of Hill House.\n\
There is one single bulb hanging from the ceiling with a solitary string\n\
that turns the light on and off.\n";
	dest_dir = ({"players/martha/clue/rooms/hall2","down",
			     "players/martha/clue/rooms/attic","up"});
}
	