#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("escort",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/escort.c"), this_object());
	}*/
	
	if (arg) return;
	set_light(1);
	short_desc = GRN+"The Bedroom"+NORM;
	items = ({
		"bed","A brass headboard frames the top of this double bed",
		"wall","Light green, the wall is free from any decorations other than border",
		"comforter","A light green fleece comforter lays upon the bed",
		"mound","A giant pile of pillows",
		"pillows","Standard twin pillows with green cases on them",
		"floor","The floors are hardwood but mostly covered with a rug",
		"rug","The oriental rug has varying shades of green throughout it",
		"throw","The rug has varying shades of green and is oval shaped",
		"border","The border is a darker green with paisley print",
		"print","The print is blue, green, brown and yellow paisley",
		"chest","A beautiful cedar hope chest",
		"key","A small silver key",
		"lock","A regular lock with a key sticking out of it",
		"room","A young womans bedroom",
		"fixture","A brass light fixture with a shade hanging from it",
		"ceiling","The ceiling is painted white",
		"shade","The lamp shade is made of stained glass",
		"glass","The glass is stained a dark green",
		"rays","The rays of light are tinted green",
		"color","The light is colored green"});
		
	long_desc =
"	A double bed is pushed against the far wall.  The comforter on\n\
the bed looks freshly washed and there is a giant mound of pillows\n\
at the top of the bed.  The floor in here is hardwood, but most of\n\
it is covered with an oriental throw rug.  The walls are a lighter\n\
shade of green, bordered with a paisley print all along the top of\n\
the room.  A hope chest sits at the end of the bed, a key sticking\n\
out of the lock.  The room is lit by a fixture that is hanging from\n\
the center of the ceiling.  The shade is made of stained glass and\n\
when the light is on, beautiful rays of color shine through.  Years\n\
ago, this was probably the room of a young woman.\n";
	dest_dir = ({"players/martha/clue/rooms/hall2","southwest",
				 "players/martha/clue/rooms/bed1","west",
				 "players/martha/clue/rooms/bed3","south"});
}
