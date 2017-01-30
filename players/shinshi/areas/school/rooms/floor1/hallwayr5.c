inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = HIW+"A Hallway"+NORM;
	long_desc =
		"This long hallway has lockers up and down both sides.  The floor\n"+
		"is made up of tiles that have been waxed to a glossy shine.  It\n"+
		"is well-lit,due to the bright florescents hanging from the ceiling.\n";

items =

({
	"test",
	"Test this",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/lobby.c",	"south",
	"/players/shinshi/areas/school/rooms/floor1/hallwayr6.c",	"north",
});
}
