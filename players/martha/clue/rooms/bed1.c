#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("white",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/white"), this_object());
	}*/
	
	if (arg) return;
	set_light(1);
	short_desc = BLU+"The Bedroom"+NORM;
	items = ({
		"poster","This is a queen sized four poster bed",
		"bed","This is a queen sized four poster bed",
		"walls","The walls are painted a pale blue",
		"wall","The wall is pale blue",
		"canopy","The long canopy flows down below the mattress",
		"post","The fluted posts are finished in warm mahogany and hold the canopies",
		"stool","The step stool is finished in mahogany",
		"window","The large window offers a view of the backyard",
		"curtain","The curtain is blue and white gingham",
		"curtains","The curtains are blue and white gingham with ruffles",
		"floor","The floor is carpeted with a light blue shag",
		"shag","The carpet is shaggy and light blue",
		"sconce","The sconce is antiqued and holds a white candle",
		"sconces","The sconces are antiqued and hold white candles",
		"vase","The crystal vase is filled with daisies",
		"daisies","The originally white daisies have been dyed light blue",
		"chest","The chest is finished in a rich antique cherry",
		"box","A box of tissues",
		"tissues","A box of tissues",
		"table","A bedside table that matches the step stool"});				
		
	long_desc =
"	There is a four poster bed queen sized bed in the middle of one of\n\
the walls.  The detachable canopy rests on fluted posts, finished in\n\
warm mahogany.  There is a small step stool to the side of the bed to\n\
assist one in climbing up into the bed.  There is a large window that\n\
looks out into the vast backyard.  The window is framed with blue and\n\
white gingham ruffled curtains.  The floor is carpeted with a light\n\
blue shag.  Antiqued sconces adorn the pale blue wall.  A vase filled\n\
with daisies sits upon a rich antique cherry finished chest.  A box of\n\
tissues rests on top of the bedside table.\n";
	dest_dir = ({"players/martha/clue/rooms/hall2","south",
				 "players/martha/clue/rooms/bed2","east",
				 "players/martha/clue/rooms/lounge2","west"});
}
