#include "ansi.h"
inherit "room/room";

reset(arg) {
	if(!present("Mustard",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/mustard.c"), this_object());
	}
	
	if (arg) return;
	set_light(1);
	short_desc = HIY+"The Ballroom"+NORM;
	items = ({
		"light","Bright and brilliant this light blinds you",
		"door","A beautiful mahogany door",
		"ballroom","The Grand Ballroom of Hill House",
		"wooden","Old and wooden, this floor shines",
		"floor","The old wooden floor shines and looks brand new",
		"curtain","A long mauve scalloped curtain that flow from ceiling to floor",
		"curtains","Long mauce scalloped curtains that flow from ceiling to floor",
		"window","A beautiful paned window that is so clean you can see your own reflection",
		"windows","These windows are so clean you can see your own reflection",
		"yard","The freshly mowed back yard goes on and on",
		"back","The back yard looks freshly mowed and goes on quite a distance",
		"crystal","The crystal in the chandelier sparkles and glistens",
		"spinning","This chandelier not only sparkles, but it spins as well",
		"chandelier","Hundreds of crystal fragments form this beautiful, sparkling chandelier",
		"center","The middle of the room where the chandelier hangs",
		"room","Bright, sparkling, and clean, this is the ballroom",
		"rainbow","Colorful trails of light that bounce off the crystal",
		"trail","A colorful trail of rainbow light that bounces off the crystal",
		"trails","Colorful trails of rainbow light that bounce off the crystal",
		"brass","Shined brass candle sconces hang on the wall",
		"candle","A white tapered candle with a dancing flame",
		"candles","White tapered candles with dancing flames",
		"sconce","A beautiful brass candle holder",
		"sconces","Beautiful brass candle holders",
		"walls","Cream colored walls adorned with sconces",
		"wall","A cream colored wall",
		"shadows","Shadows created by the candles that are lit on the wall",
		"shadow","A long shadow cast by the candle on the wall",
		"phonograph","An old fashioned recording device",
		"corner","The corner is shadowed by the phonograph"});
			
	long_desc =
"	Blinding bright light escapes as the door to the Grand Ballroom is\n\
opened.  Decades of dancing have not worn the old wooden floor, which\n\
is polished and appears to be newly installed.  Long, cascading curtains\n\
cover windows that look out into the never-ending back yard.  A spinning\n\
crystal chandelier hangs in the center of the room and casts rainbow\n\
trails of light throughout the room.  Brass candle sconces hang from\n\
the wall with glowing white candles that cast shadows on the floor.\n\
An old fashioned phonograph sits in one corner and looks as though\n\
it has been used recently.  The room is spotless and sparkling, it\n\
has definitely been cleaned very recently.\n";
	dest_dir = ({"players/martha/clue/rooms/hall","south",
				 "players/martha/clue/rooms/conservatory","east",
				 "players/martha/clue/rooms/lounge","west"});
}
