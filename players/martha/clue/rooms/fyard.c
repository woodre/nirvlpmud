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
	short_desc = GRN+"The Front Yard"+NORM;
	items = ({
		"grass","The grass is green",
		"yard","This is the front yard",
		"tree","The only tree in the yard, a weeping willow",
		"gate","A tall, wrought iron gate",
		"driveway","A paved driveway with many cars lined up",
		"door","A beautiful mahogany door",
		"patio","Red bricks make up the patio",
		"doghouse","This is a small shelter for a dog",
		"doghouses","These houses shelter the dogs from bad weather",
		"house","This is the infamous Hill House",
		"lightning","A streak of lightning flashes across the sky",
		"air","Even the air seems frightened"});
		
	long_desc =
"	Green grass makes up the front yard.  There is one solitary tree\n\
at the beginning of the yard, near the gate.  There is a brick patio\n\
upon which there are two doghouses.  The driveway leads from the gate\n\
up to the front door of Hill House.  Lightning flashes and a loud clap\n\
of thunder that could wake the dead reverberates in the sky.  Hill House\n\
looms ahead, a feeling of unease hanging in the air.  Enter the house\n\
at your own risk!\n";
	dest_dir = ({"players/martha/clue/rooms/door1","ring_bell",
				 "players/martha/clue/rooms/byard","around",
				 "players/martha/clue/rooms/driveway","run_away"});
}
