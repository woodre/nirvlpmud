inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = "A miniature hut";
	long_desc =
		"You stand before a miniature hut with signs taped on the front of\n"+
		"it. And I'll finish the rest of this when I'm not so tired\n";

items =

({
	"empty",
	"This is empty, retard."
	});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/gymnasiumlob.c",	"exit",
	});
}
