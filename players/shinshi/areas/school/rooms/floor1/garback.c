inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("garback")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/garback.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIR+"Mrs. Garback's Classroom"+NORM;
	long_desc =
		"There are four rows of desks in this classroom, and at the end of each\n"+
		"row are Spanish books.  A computer sits on the teacher's desk, and\n"+
		"there is also an overhead projector for her use.  On the walls there\n"+
		"are posters of the Spanish Alphabet and the Spanish color names.\n";

items =

({
	"test",
	"Test this",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/mathpod.c",	"out",
});
}
