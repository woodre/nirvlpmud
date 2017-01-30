#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("cook",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/cook.c"), this_object());
	}*/
	
	if (arg) return;
	set_light(1);
	short_desc = CYN+"The Kitchen"+NORM;
	items = ({
		"tile","A ceramic black and white tile",
		"tiles","Black and white ceramic tiles",
		"floor","The floor is lined with black and white tiles",
		"kitchen","Behold the glorious kitchen of Hill House",
		"wall","The wall is lined with cupboards",
		"walls","The walls are lined with cupboards",
		"freezer","The 'freezer' looks as though it could be 'open'ed",
		"stainless","There is stainless steel throughout the kitchen",
		"steel","There is stainless steel throughout the kitchen",
		"island","A giant island used as a butchers block",
		"center","The middle of the kitchen",
		"butchers","A giant butchers block",
		"block","A giant butchers block, where cutting is done",
		"knife","A long, gleaming butchers knife, which seems to be out of place",
		"top","This is the top of the butchers block",
		"refrigerator","The refrigerator is stainless steel and very large",
		"oven","The oven is stainless steel and looks expensive",
		"sink","The kitchen sink is also made of stainless steel",
		"cupboards","These giant cupboards can hold a lot",
		"cupboard","This cupboard can hold lots of stuff",
		"counter","The counter is made of the same black and white ceramic tile as the floor",
		"passageway","It seems one might be able to 'open' the 'freezer'",
		"hill","This is the infamous Hill House",
		"house","This is the infamous Hill House"});
		
	long_desc =
"	Black and white checkered tiles line the floor of this marvelous\n\
kitchen.  One of the walls has a giant stainless steel walk in freezer.\n\
There is an island in the center of the kitchen that looks to be a\n\
giant butchers block.  There is a very sharp butchers knife laying on\n\
top of the block.  The refrigerator is stainless steel, as are the\n\
oven and sink.  There are various cupboards on the walls and the\n\
kitchen counter is clean, much like the rest of the house.  Rumor\n\
has it there are secret passageways hidden throughout Hill House.\n\
There may be one hidden in here!\n";
	dest_dir = ({"players/martha/clue/rooms/billiard","north",
				 "players/martha/clue/rooms/droom","west",
				 "players/martha/clue/rooms/hall","northwest"});
}
/*Need to add a secret passageway to the LOUNGE here 	*/
/*need to be able to 'open freezer'						*/
