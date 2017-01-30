inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("mateer")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/mateer.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIR+"Mrs. Mateer's Classroom"+NORM;
	long_desc =
		"This room has math formulas and a multiplication table on the walls.\n"+
		"There is a cart containing an overhead projector, stacks of books, and\n"+
		"a box of calculators.  The center of the room is full of student\n"+
		"desks.  The teacher's desk has a computer sitting on it for her use.\n";

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
