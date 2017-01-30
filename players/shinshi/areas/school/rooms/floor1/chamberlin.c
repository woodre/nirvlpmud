inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("chamberlin")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/chamberlin.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIR+"Mrs. Chamberlin's Classroom"+NORM;
	long_desc =
		"The walls in this room are decorated with a multiplication table and\n"+
		"math formulas.  There is a cabinet for supplies, as well as a\n"+
		"bookshelf full of algebra and geometry books.  The teacher's desk has\n"+
		"a computer on it, and the rest of the space is taken up with the\n"+
		"student desks.\n";

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
