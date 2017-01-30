inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("shinshi_male_student")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/student.c"),this_object());
}

if(!present("shinshi_female_student")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/student2.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIW+"A Hallway"+NORM;
	long_desc =
		"This long hallway has lockers up and down both sides.  The floor\n"+
		"is made up of tiles that have been waxed to a glossy shine.  It\n"+
		"is well-lit,due to the bright florescents hanging from the ceiling.\n"+
	  	"There are doorways to the north and the south, and the hallway\n"+
	  	"continues to the east.\n";

items =

({
	"lockers",
	"The blue lockers on the sides are tall and slim. Each one has it's own combination",
	});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/lobby.c",	"west",
	"/players/shinshi/areas/school/rooms/floor1/wasielewskiroom.c",	"north",
	"/players/shinshi/areas/school/rooms/floor1/hejlroom.c",	"south",
	"/players/shinshi/areas/school/rooms/floor1/hallwayr2.c",	"east",
	});
}
