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
	short_desc = "Fix this";
	long_desc =
		"The copy room is just plain white.  It is full of all the things\n"+
		"needed to produce the paperwork needed for a high school. There is a\n"+
		"copy machine in here, as well as a table with fax machines and paper\n"+
		"shredders.  The table also holds staplers, hole punchers, and staple\n"+
		"removers. There is also a snack machine containing all kinds of junk\n"+
		"food.\n";
items =

({
	"test",
	"Test this",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/hallwayr4.c",	"west",
});
}
