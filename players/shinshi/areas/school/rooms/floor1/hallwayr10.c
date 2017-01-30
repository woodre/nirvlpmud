inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = HIW+"A Hallway"+NORM;
	long_desc =
		"This hallway has large bricks carefully cemented together to\n"+
		"form the white walls. The bricks have been painted white, many\n"+
		"different times. The paint is starting to chip away from the\n"+
		"lack of a good painting in awhile.To the north is the math pod,\n"+
		"to the east is the lobby, to the south is the main office, and\n"+
		"to the west, the hallway continues.\n";

items =

({
	"test",
	"Test this",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/hallwayr9.c",	"east",
	"/players/shinshi/areas/school/rooms/floor1/office.c",	"south",
	"/players/shinshi/areas/school/rooms/floor1/mathpod.c",	"north",
	"/players/shinshi/areas/school/rooms/floor1/hallwayr11.c",	"west",
});
}
