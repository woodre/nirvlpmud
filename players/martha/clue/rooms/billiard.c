#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("yvette",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/yvette.c"), this_object());
	}*/
	
	if (arg) return;
	set_light(1);
	short_desc = HIB+"The Billiard Room"+NORM;
	items = ({
		"billiard","Cues, balls and a table make up this game",
		"table","A standard billiard table, complete with balls and a triangle",
		"center","The center of the room holds a billiard table",
		"room","The room is dimly lit and thick with smoke",
		"corner","The corner of the room",
		"bar","The wet bar has various liquors, especially cognac",
		"cognac","Darkish alcohol fills this bottle",
		"leather","Brown and new looking leather",
		"chairs","Brown and new looking leather chairs",
		"chair","This chair is made of brown leather and looks new",
		"crescent","The chairs are formed in a half moon shape",
		"rack","A wooden rack made to hold billiard cues",
		"cue","A long, tubular shaped stick used to strike the ball in the game of billiards",
		"cues","Long sticks used to strike the balls in the game of billiards",
		"wall","The wall is a medium shade of blue",
		"walls","The walls are a medium shade of blue",
		"square","A small blue colored chalk square",
		"chalk","A small blue colored square of chalk",
		"ledge","The ledge of the billiard table, dusty with chalk",
		"ledges","The ledges of the billiard table have chalk on them",
		"handprint","This handprint looks like it was made by a woman",
		"air","The air is thick with smoke",
		"smoke","Cigarette smoke fills the air"});
		
	long_desc =
"	A billiard table sits in the center of the dimly lit room.  In one\n\
corner is a wet bar stocked with cognac.  Brown leather chairs form a\n\
crescent in another corner.  There is a rack with billiard cues hanging\n\
on one of the walls.  The billiard table has various balls scattered\n\
around it as though a game had recently been interrupted.  Small\n\
squares of chalk sit on the ledges of the table and one of the ledges\n\
has a dusting of chalk in the shape of a handprint. The air is thick\n\
with smoke and smells of cigarettes.\n";
	dest_dir = ({"players/martha/clue/rooms/conservatory","north",
				 "players/martha/clue/rooms/hall","west",
				 "players/martha/clue/rooms/kitchen","south"});
}
