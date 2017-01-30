inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("buxton")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/buxton.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIR+"Mrs. Buxton's Office"+NORM;
	long_desc =
		"There is a large desk in this room, with a chair behind it.  In front\n"+
		"of the desk are two other chairs for people to sit in while speaking\n"+
		"with the guidance counselor.  On the desk there is a computer and an\n"+
		"electronic picture frame.  There is also a bookcase here, full of\n"+
		"counseling books.  There are small notes on both the desk and the\n"+
		"door.\n";

items =

({
	"test",
	"Test this",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/guidance.c",	"south",
});
}
