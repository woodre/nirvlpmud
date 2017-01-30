inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = "Fix this";
	long_desc =
		"Edit this later\n";

items =

({
	"test",
	"Test this",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/FIXTHIS.c",	"fix",
});
}
