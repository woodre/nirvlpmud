#include "ansi.h"
inherit "room/room";

    void reset(status arg) {
	if (arg) return;
    set_light(1);
    short_desc = "A Road";
    items = ({
	    "trees","A row of gloomy looking trees",
	    "road","A candy paved road",
	    "mountains","Large mountains loom overhead",
	    "darkness","It is too dark to see anything of interest"});
	    
	long_desc = 
"The road leads out of the Gumdrop Mountains and into a gloomier\n\
part of Candy Land.  While there are very few trees in this area,\n\
darkness ensues.  A feeling of unease shrouds this part of the\n\
land because it is so dreary while the rest of the land is cheery.\n";
	dest_dir = ({"players/martha/area/rooms/gpass", "south",
				 "players/martha/area/rooms/gmtn2", "southeast",
				 "players/martha/area/rooms/road2", "west",
				 "players/martha/area/rooms/lcastle", "northwest"});
}
	