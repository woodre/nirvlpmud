#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("babysitter",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/babysitter.c"), this_object());
	}*/
	
	if (arg) return;
	set_light(1);
	short_desc = RED+"The Bedroom"+NORM;
	items = ({
		"bed","The small twin bed has no headboard",
		"wall","Dark red, the wall is free from any decorations other than border",
		"comforter","A brick red fleece comforter lays upon the bed",
		"mound","A giant pile of pillows",
		"pillows","Standard twin pillows with red cases on them",
		"floor","The floors are hardwood but mostly covered with a rug",
		"rug","The oriental rug has varying shades of red throughout it",
		"throw","The rug has varying shades of red and is oval shaped",
		"border","The border is a dark red with paisley print",
		"print","The print is red, green, brown and yellow paisley",
		"room","A young boys bedroom",
		"fixture","A brass light fixture with a shade hanging from it",
		"ceiling","The ceiling is painted white",
		"shade","The lamp shade is made of stained glass",
		"glass","The glass is stained a dark red",
		"chest","A small wooden chest to hold toys",
		"corner","The corner of the room which holds a toy chest",
		"rays","The rays of light are tinted red",
		"color","The light is colored red"});
		
	long_desc =
"	A small twin bed is pushed against the far wall.  The blanket\n\
on the bed looks like it is brand new and there is a giant mound\n\
of pillows at the top of the bed.  The floor in here is hardwood,\n\
but most of it is covered with an oriental throw rug.  The walls\n\
are a darker shade of red, bordered with a paisley print along the\n\
top of the room. A small toy chest sits in the corner of the room.\n\
The room is lit by a fixture that is hanging from the center of\n\
the ceiling.  The shade is made of stained glass and when the\n\
light is on, beautiful rays of color shine through.  Years ago,\n\
this was probably the room of a young boy.\n";
	dest_dir = ({"players/martha/clue/rooms/bed2","north",
				 "players/martha/clue/rooms/hall2","west",
				 "players/martha/clue/rooms/bed4","south"});
}
