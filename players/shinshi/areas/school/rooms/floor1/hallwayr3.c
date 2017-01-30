inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = HIW+"A Hallway"+NORM;
	long_desc =
		"This long hallway is very well lit due to the flouescent lights\n"+
		"hanging from the ceiling.  The floor is made up of tiles that have been\n"+
		"waxed to a glossy shine. There is a window in this section of the hallway\n";

items =

({
	"window",
	"There is a window in this section of the hallway that looks into the nurse's office",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/hallwayr2.c",	"north",
	"/players/shinshi/areas/school/rooms/floor1/hallwayr4.c",	"south",
	"/players/shinshi/areas/school/rooms/floor1/nurse.c",	"east",
});
}
