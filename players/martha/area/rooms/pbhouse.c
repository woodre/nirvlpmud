#include "ansi.h"
inherit "room/room";

reset(arg) {
	if(!present("gnut",this_object())) {
		move_object (clone_object("players/martha/area/mobs/gnut"),this_object());
	}
	
	if(arg) return;
	set_light(1);
	short_desc = YEL+"Peanut Brittle House"+NORM;
	items = ({
		"peanut","Shiny and slick peanut brittle",
		"brittle","Shiny and slick peanut brittle",
		"yard","The yard is garnished with various nuts and flowers",
		"home","This is the home of Gramma Nut",
		"basket","A basket large enough to hold a pound of nuts",
		"flowerbed","Flowers with peanuts in the center line the bed",
		"flowers","Flowers with peanuts in the center"});
		
	long_desc =
"   Two stories of slick, shiny peanut brittle make the home of Gramma\n\
Nut.  Peanut flowers grow all around the yard.  Sometimes Gramma Nut\n\
can be seen gathering the nuts in a large basket, which is on the\n\
ground near a flowerbed.\n";
	dest_dir = ({"players/martha/area/rooms/rtrail", "south",
				 "players/martha/area/rooms/road2", "east",
				 "players/martha/area/rooms/lwoods", "north"});
}
		