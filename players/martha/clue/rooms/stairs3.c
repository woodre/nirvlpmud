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
		"basement","The basement is a darker than the main hall",
		"main","The main hall is well lit",
		"hall","The main hall is well lit",
		"floor","The floor is carpeted",
		"single","One bulb",
		"bulb","One bulb hanging from the ceiling",
		"ceiling","The ceiling is high and painted white",
		"string","One lonely sting dangling from the bulb base",
		"light","The light is bright when turned on and dark when turned off"});
		
	long_desc =
"	This is the landing between two stairwells.  You can either venture\n\
back up to the main hall of Hill House or go down into the basement.\n\
There is one single bulb hanging from the ceiling with a solitary string\n\
that turns the light on and off.\n";
	dest_dir = ({"players/martha/clue/rooms/basement","down",
			     "players/martha/clue/rooms/hall","up"});
}
	