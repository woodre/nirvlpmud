#include "ansi.h"
inherit "room/room";

reset(arg) {
	if(!present("gloppy",this_object())) {
		move_object(clone_object("/players/martha/area/mobs/gloppy"), this_object());
	}

	if (arg) return;
	set_light(1);
	short_desc = YEL+"Molasses Swamp"+NORM;
	items = ({
		"molasses","Gooey and sticky, this brown stuff is like mud",
		"shadow","A molasses mass that could possibly be alive",
		"swamp","Dark, sticky masses create a giant swamp",
		"spewing","A rain of molasses falls down on the land",	
		"fountain","A spout of molasses flowing heavily",
		"geyser","Cascading molasses flowing heavily",	
		"masses","Masses of molasses, oh my"});
		
	long_desc = 
"   Gooey, sticky brown molasses slowly oozes around your feet, making\n\
it difficult for you to move very fast.  Mammoth molasses masses hover\n\
above you.  A fountain of dark molasses is spewing into the air like a \n\
colossus geyser.\n";
	dest_dir = ({"players/martha/area/rooms/bridge", "east",
				 "players/martha/area/rooms/icsea", "west"});
}
