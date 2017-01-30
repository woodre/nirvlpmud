inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("billings")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/billings.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIR+"Guidance Secretary's Office"+NORM;
	long_desc =
		"This office is a very small room.  There is a desk and chair, a filing\n"+
		"cabinet, and a small table crammed into the space.  A computer, an\n"+
		"inbox, and an outbox are on top of the desk, and the table is covered\n"+
		"in papers. A window behind the desk looks out on a parking lot.\n";

items =

({
	"test",
	"Test this",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/guidance.c",	"southeast",
});
}
