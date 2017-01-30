inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("hutchinson")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/hutchinson.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIR+"Mr. Hutchinson's Classroom"+NORM;
	long_desc =
		"Across from the door in this classroom is a large chalkboard. There\n"+
		"is a computer on the teacher's desk, and a table containing a box of\n"+
		"calculators and textbooks.  The room also has an overhead projector as\n"+
		"well as the usual rows of student desks.\n";

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
