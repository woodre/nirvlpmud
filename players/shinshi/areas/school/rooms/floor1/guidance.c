inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = HIW+"Guidance Office"+NORM;
	long_desc =
		"There is a desk and two chairs in the center of this room.  A computer\n"+
		"sits on top of the desk, as well as a calendar showing today's date.\n"+
		"Just to the side of the door there is a large bulletin board.  There\n"+
		"is a cabinet along one wall, and three doors leading out of this room\n"+
		"to what look like small offices.\n";

items =

({
	"test",
	"Test this",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/hallwayr2.c",	"south",
	"/players/shinshi/areas/school/rooms/floor1/guidancesec.c",	"northwest",
	"/players/shinshi/areas/school/rooms/floor1/guidance1.c",	"north",
	"/players/shinshi/areas/school/rooms/floor1/guidance2.c",	"northeast",
});
}
