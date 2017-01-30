inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("iracki")) {
	move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/iracki.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIR+"Mr. Iracki's Office"+NORM;
	long_desc =
		"This office looks like some kind of violent storm struck it. The\n"+
		"drawers in the filing cabinet are all partly open, with papers and\n"+
 		"files spilling out of them and onto the floor.  Somewhere in all the\n"+
 		"mess a desk can be seen, with a computer on top of it and a chair\n"+
 		"behind it.  There are posters and pictures on the walls, some showing\n"+
 		"the Beatles, and some showing an amateur hippie band.\n";

items =

({
	"test",
	"Test this",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/guidance.c",	"southwest",
});
}
