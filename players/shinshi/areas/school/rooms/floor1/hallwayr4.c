inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = HIW+"A Hallway"+NORM;
	long_desc =
		"This long hallway is very well lit due to the flouescent lights hanging\n"+
		"from the ceiling.  The floor is made up of tiles that have been waxed\n"+
		"to a glossy shine. The hallway continues north, there is a door to the\n"+
		"east, and a door that leads to the outside.\n";

items =

({
	"test",
	"Test this",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/hallwayr3.c",	"north",
	"/players/shinshi/areas/school/rooms/floor1/copyroom.c",	"east",
	"/players/shinshi/areas/school/rooms/entrance.c",	"out",
});
}
