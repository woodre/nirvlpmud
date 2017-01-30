inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("shinshi_key_mob")) {
	move_object(clone_object("/players/shinshi/areas/coining/mobs/studentkey.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = "Little Boys Room";
	long_desc =
		"This is a small room that has been painted all white.  Along one\n"+
		"wall there is a row of sinks, and opposite those are the bathroom\n"+
		"stalls and urinals.  The room is brightly lit, and appears to be\n"+
		"kept nice and clean for the children.\n";

items =

({
	"sinks", "White sinks lowered closer to the ground",
	"row", "A row of sinks",
	"bathroom stalls", "Toilets surrounded by white stall walls",
	"stalls", "Toilets surrounded by white stall walls",
	"urinals", "White toilets that allow little boys to stand up and pee",
});

dest_dir =
({
	"/players/shinshi/areas/coining/rooms/rm3.c",	"west",
});
}
