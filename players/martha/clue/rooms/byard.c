#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("dog",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/dog.c"), this_object());
	if(!present("dog",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/dog.c"), this_object());
		}*/
	
	if (arg) return;
	set_light(1);
	short_desc = HIG+"The Back Yard"+NORM;
	items = ({
		"grass","The grass is green",
		"yard","This is the back yard",
		"tree","The only tree in the yard, a tall oak",
		"door","A beautiful mahogany door",
		"fence","A wrought iron fence",
		"patio","Red bricks make up the patio",
		"doghouse","This is a small shelter for a dog",
		"doghouses","These houses shelter the dogs from bad weather",
		"house","This is the infamous Hill House",
		"lightning","A streak of lightning flashes across the sky",
		"air","Even the air seems frightened"});
		
	long_desc =
"	Green grass makes up the back yard.  There is one solitary tree\n\
at the far end of the yard, near the fence.  There is a brick patio\n\
upon which there are two doghouses.  Lightning flashes across the sky\n\
and a loud clap of thunder that could wake the dead.  Hill House looms\n\
ahead, a feeling of unease hanging in the air.  Enter the house at your\n\
own risk!\n";
	dest_dir = ({"players/martha/clue/rooms/door2","ring_bell",
				 "players/martha/clue/rooms/fyard","around"});
}
