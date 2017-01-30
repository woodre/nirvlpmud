inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = "A Swing";
	long_desc =
     	"A metal pole, bent in two places, has been anchored into the\n"+
     	"ground here.  It looks a bit like an arch with a flat top.\n"+
     	"Chains have been used to hang a swing from it.\n";

items =

({
	"chains",
	"Chains have been bolted to the metal which attach to a plastic seat",
	"pole",
	"A large pole that is bent in two places keeps the equipment stable",
	"swing",
	"A plastic seat that is chained to the top of the pole",
	"seat",
	"A thick piece of plastic that bends",
	"ground",
	"Warm mulch covers the dirt ground",
	"mulch",
	"Ground up bark mulch covers the ground",
});

dest_dir =
({
	"/players/shinshi/areas/coining/rooms/outside3.c",	"north",
	"/players/shinshi/areas/coining/rooms/outside5.c",	"west",
});
}