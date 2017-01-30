inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("hejl")) {
	move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/hejl.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIR+"Mrs. Hejl's Classroom"+NORM;
	long_desc =
		"There is a pencil sharpener and a cabinet next to the door in this\n"+
		"room.  In the back of the room is a chalkboard covered with newspaper\n"+
		"clippings.  The other chalkboard has a homework assignment written on\n"+
		"it.  Just across from the door is the teacher's desk and a television\n"+
		"mounted on the wall.  The center space is filled with approximately\n"+
		"thirty student desks.\n";

items =
({
	"test",
	"test"
	});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/hallwayr1.c",	"north",
	});
}
