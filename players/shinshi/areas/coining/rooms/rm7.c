inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = "Little Girls Room";
	long_desc =
		"This is a small room that has been painted all pink. Little flowers\n"+
		"have been painted on the top of the walls to give a little bit more\n"+
		"color to the room. On one wall are the sinks and across from them\n"+
		"are bathroom stalls, also painted pink.  The room is brightly lit,\n"+
		"and looks to be kept nice and clean for the children.\n";
		
items =

({
	"flowers", "Yellow painted daffodils are on the top of the walls",
	"walls", "The four walls of the room have been painted pink",
	"color", "Pink, yellow, and green are the main colors to the room",
	"sinks", "White sinks are lowered closer to the ground for easy access",
	"row", "A row of sinks",
	"stalls", "Toilets surrounded by pink stall walls",
	"toilets", "White toilets used by many different girls",	
});

dest_dir =
({
	"/players/shinshi/areas/coining/rooms/rm3.c",	"east",
});
}
