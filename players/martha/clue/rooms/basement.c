#include "ansi.h"
inherit "room/room";

void reset(status arg) {
	if (arg) return;
	set_light(0);
	short_desc = HIG+"The Basement"+NORM;
	items = ({
		"dark","It is pitch black",
		"bottom","This is the lowest level of Hill House",
		"hill","This is the infamous Hill House",
		"house","This is the infamous Hill House",
		"darkness","It is pitch black",
		"fog","Not real fog, but fear is in the air",
		"room","This is the basement",
		"basement","This is the lowest level of Hill House",
		"mice","Smallish grey rodents",
		"mouse","A small grey mouse",
		"rodent","A small grey mouse",
		"rodents","Smallish grey rodents",
		"floor","A grey cement floor",
		"air","The air is thick and musty",
		"fuse","Your everyday fuse box",
		"box","Your everyday fuse box",
		"wall","A cement wall"});
		
	long_desc = 
"	It is damp and dank on the bottom most level of Hill House.\n\
Darkness ensues and a quiver of fear hangs like fog in the room.\n\
As far as basements go, this may be one of the creepiest ones\n\
known to man.  The chittering of mice can be heard throughout\n\
the room and there just may be larger rodents crawling around\n\
down here.  The floor is cold and the air is musty.  There is\n\
a fuse box on the wall, open and easily accessible.\n";
	dest_dir = ({"players/martha/clue/rooms/boiler","north",
				 "players/martha/clue/rooms/stairs3","up",
				 "players/martha/clue/rooms/pantry","east",
				 "players/martha/clue/rooms/winecellar","south",
				 "players/martha/clue/rooms/understairs","west"});
}