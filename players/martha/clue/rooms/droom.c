#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("wadsworth",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/wadsworth.c"), this_object());
	}*/
	
	if (arg) return;
	set_light(1);
	short_desc = RED+"The Dining Room"+NORM;
	items = ({
		"oak","The table is made of oak",
		"table","A long beautiful polished oak dining room table",
		"room","A formal dining room",
		"chair","This chair is lined with cream colored cloth and has no arms.",
		"chairs","Cream colored cloth lined chairs that have no arms",
		"end","The end of the table",
		"placecard","Each placecard has the name of a guest",
		"china","White china plates with a flowery pattern",
		"plate","A white china plate with a flowery pattern",
		"plates","White china plates with a flowery pattern",
		"napkins","Burgundy colored cloth napkins folded into swans",
		"napkin","A burgundy colored cloth napkin shaped into a swan",
		"silverware","Salad fork, dinner fork, knife and spoon make up the silverware arrangement",
		"glasses","Beautiful crystal water glasses",
		"glass","A beautiful crystal water glass",
		"cup","A white china coffee cup with a flowery pattern",
		"cups","White china coffee cups with a flowery pattern",
		"set","The table is set for a party of seven",
		"setting","The table is set for a party of seven",
		"head","The head of the table, reserved for the host",
		"chandelier","A smaller version of the elegant hall chandelier",
		"hall","The Grand Hall of Hill House",
		"crystal","A beautiful crystal fragment hanging on the chandelier",
		"crystals","Beautiful crystal fragments hanging from the chandelier",
		"tableware","The silverware, glasses and plates make up the tableware",
		"glitter","The light from the chandelier causes the tableware to shimmer"});
				
	long_desc =
"	A beautiful polished oak table that seats eight takes up most of the\n\
formal dining room.  Armless, cloth lined chairs are positioned just so\n\
around the table, with one chair at each end for the heads of the table\n\
to sit.  The table is set for a party of seven and there are placecards\n\
on top of each china plate.  Someone has gone to great lengths to keep\n\
a semblence of order to this dinner.  Napkins and silverware are all in\n\
the proper place, along with the glasses and coffee cups.  For some odd\n\
reason, there is only one head of the table set, instead of the customary\n\
two.  A smaller version of the chandelier in the hall hangs directly\n\
above the table and light shines off the crystals, making the tableware\n\
glitter.\n";
	dest_dir = ({"players/martha/clue/rooms/hall","north",
				 "players/martha/clue/rooms/kitchen","east",
				 "players/martha/clue/rooms/study","west"});
}
