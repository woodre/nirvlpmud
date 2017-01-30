inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = HIR+"Math Pod"+NORM;
	long_desc =
		"This large, open area contains three desks and a lot of chairs. There\n"+
		"are a couple of large posters on the wall. Math equations litter the\n"+
		"ceilings and walls. The doors to six different classrooms can\n"+
		"be seen around the room.\n";

items =

({
	"test",
	"Test this",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/hallwayr10.c",	"south",
	"/players/shinshi/areas/school/rooms/floor1/garback.c",	"garback",
	"/players/shinshi/areas/school/rooms/floor1/fulkrod.c",	"fulkrod",
	"/players/shinshi/areas/school/rooms/floor1/hutchinson.c",	"hutchinson",
	"/players/shinshi/areas/school/rooms/floor1/chamberlin.c",	"chamberlin",
	"/players/shinshi/areas/school/rooms/floor1/mateer.c",	"mateer",
	"/players/shinshi/areas/school/rooms/floor1/long.c",	"long",
});
}
