#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("scarlet",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/scarlet.c"), this_object());
	}*/
	
	if (arg) return;
	set_light(1);
	short_desc = BLU+"The Lounge"+NORM;
	items = ({
		"lounge","The lounge is candlelit and quiet",
		"brown","Brown is the color of the leather couches",
		"leather","Leather is what the brown couches are made of",
		"couch","This is a brown leather couch",
		"couches","These are brown leather couches",
		"outer","This is an outer wall of the room",
		"inner","This is the inner wall of the room",
		"wall","This is a wall in the lounge",
		"walls","The walls are very plain and painted a medium shade of green",
		"phonograph","An old fashioned recording device",
		"table","A small table that can hold something",
		"corner","This corner is furnished with a small table",
		"fireplace","The fireplace is made of bricks. One could possibly 'move' a 'brick' if needed",
		"room","This is the lounge",
		"rooms","You can't see other rooms from here",
		"carpeting","The carpeting is dark green, but looks black",
		"floor","The floor is carpeted",
		"lamp","This floor lamp appears to be broken",
		"candle","This white candle is lit",
		"candles","These white candles are all lit",
		"shadows","Shadows play tricks on your mind",
		"minds","Only you can visualize your own mind",
		"passageway","There seems to be a 'brick' you can 'move' here",
		"hill","This is the infamous Hill House",
		"house","This is the infamous Hill House"});
		
	long_desc =
"	The lounge is furnished with two brown leather couches, one on\n\
each outer wall of the room.  There is a phonograph sitting on a\n\
table in the corner between the two couches.  A fireplace is built\n\
into the inner wall of the room.  There is dark carpeting on the\n\
floor and a floor lamp in one corner, but it seems to be off right\n\
now.  Candles light this room tonight and shadows dance across the\n\
floor and walls, playing tricks on the minds of those who enter.\n\
Rumor has it there are secret passageways hidden in various rooms\n\
of Hill House. Is it possible that the lounge is one of those rooms?\n";
	dest_dir = ({"players/martha/clue/rooms/library","south",
				 "players/martha/clue/rooms/hall","southeast",
				 "players/martha/clue/rooms/ballroom","east"});
}
/*THERE NEEDS TO BE A SECRET PASSAGEWAY TO THE KITCHEN*/
/* you need to be able to 'move' 'brick'              */