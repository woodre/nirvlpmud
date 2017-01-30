inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("mclaughlin")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/mclaughlin.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIW+"The Main Office"+NORM;
	long_desc =
		"Just inside the door to this office there is a row of uncomfortable\n"+
		"chairs.  Opposite the chairs is a desk for the secretary.  On one side\n"+
		"of the office is a closed door with a small plaque identifying it as\n"+
		"the principal's office.  Across from it there are two doors with vice\n"+
		"principal plaques, also closed.\n";

items =

({
	"test",
	"Test this",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/hallwayr10.c",	"north",
});
}

query_no_fight(){ return 1; }