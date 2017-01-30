inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("petrey")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/petrey.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIR+"Mr. Petrey's Office"+NORM;
	long_desc =
		"There is a desk and chair in the middle of this small office. Papers\n"+
		"are scattered everywhere, including newspapers with the same man\n"+
		"featured in most of the pictures.  A framed picture on the desk shows\n"+
		"rows of football players.\n";

items =

({
	"desk",
	"A large, wooden desk for the teacher",
	"chair",
	"A large, padded, black hair used by the teacher",
	"papers",
	"Physical forms, team statistics, etc",
	"newspapers",
	"The article dates back to 1964 and is about Ronald Petrey",
	"picture",
	"Five rows of football players. The winning team of 2008",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/hallwayr6.c",	"east",
});
}
