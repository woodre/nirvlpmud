inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = HIW+"A Hallway"+NORM;
	long_desc =
		"Edit this later\n";

items =

({
	"test",
	"Test this",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/hallwayr7.c",	"east",
	"/players/shinshi/areas/school/rooms/floor1/mens1.c",	"mens",
	"/players/shinshi/areas/school/rooms/floor1/womens1.c",	"womens",
});
}
