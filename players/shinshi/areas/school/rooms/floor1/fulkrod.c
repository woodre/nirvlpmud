inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("fulkrod")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/fulkrod.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIR+"Mrs. Fulkrod's Classroom"+NORM;
	long_desc =
		"The teacher's desk in this room is just to the side of the door.\n"+
		"There are folders on it, each labeled with a name.  Across from the\n"+
		"door is a cabinet full of crayons and other supplies.  There are two\n"+
		"computers in this room, as well as a television on a wall mount.  The\n"+
		"entire room is as neat as a pin.\n";

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
