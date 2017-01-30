inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = "Gymnasium Lobby";
	long_desc =
		"As you enter through the doors, you hear the squeaking of tennis\n"+
		"shoes from the floors. In front of you is a miniature hut with\n"+
		"a long line of people in front of it. To the west is the entryway\n"+
		"to the actual gymnasium where the sport events are held.\n";


items =

({
	"hut",
	"This is a small stand which sells snacks and drinks"
	});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/outside2.c",	"out",
	"/players/shinshi/areas/school/rooms/hut.c",	"hut",
	});
}