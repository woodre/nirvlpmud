inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("long")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/long.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIR+"Mr. Long's Classroom"+NORM;
	long_desc =
		"There is a table at the front of this room with a milk crate on it.\n"+
		"The teacher's desk has a computer on it, and there is also an overhead\n"+
		"projector here for his use.  A bookshelf against one wall is filled\n"+
		"with books, and the walls are decorated with math formulas and a\n"+
		"multiplication table.\n";

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