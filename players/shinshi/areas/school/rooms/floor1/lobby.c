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
	short_desc = "High School lobby";
	long_desc =
		"This is the entrance to the high school.  There are stairs just to the\n"+
		"right, heading up to the second floor.  Straight ahead, the hallway\n"+
		"leads farther into the school.  A few students can be seen here and there\n"+
		"in the hall, either lost, or not caring if they are late for class.\n";

items =

({
	"stairs",
	"The stairs are currently roped off, blocking the way to the upper floor",
	});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/outside1.c",	"out",
	"/players/shinshi/areas/school/rooms/floor1/hallwayr1.c",	"east",
	"/players/shinshi/areas/school/rooms/floor1/hallwayr5.c",	"north",
	"/players/shinshi/areas/school/rooms/floor1/hallwayr9.c",	"west",
	"/players/shinshi/areas/school/rooms/stairs1.c",	"up",
	});
}

init()
{
	::init();
	
	add_action("up", "up");
}

up()
{
	write("The stairs are currently roped off, preventing access.\n");
	return 1;
}