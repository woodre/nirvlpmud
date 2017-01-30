#include "ansi.h"
inherit "room/room";

	void reset(status arg) {
	if (arg) return;
	set_light(1);
	short_desc = HIK+"The Stairway"+NORM;
	items = ({
		"landing","A small area between two stairwells",
		"stairwell","Thirteen carpeted steps leading up or down, depending where you look from",
		"stairwells","Each stairwell has thirteen carpeted steps",
		"second","The second floor is a little darker than the first",
		"main","The main hall is well lit",
		"floor","The floor is carpeted",
		"hall","The Grand Hall of Hill House",
		"single","One bulb",
		"bulb","One bulb hanging from the ceiling",
		"ceiling","The ceiling is high and painted white",
		"string","One lonely sting dangling from the bulb base",
		"light","The light is bright when turned on and dark when turned off"});
		
	long_desc =
"	This is the landing between two stairwells.  You can either venture\n\
up to the second floor or go back down to the main hall of Hill House.\n\
There is one single bulb hanging from the ceiling with a solitary string\n\
that turns the light on and off.\n";
	dest_dir = ({"players/martha/clue/rooms/hall","down",
			     "players/martha/clue/rooms/hall2","up"});
}
	