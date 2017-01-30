inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = "Monkey Bars";
	long_desc =
		"The monkey bars are a true display of strength. The object to this\n"+
		"specific playground equipment is to hold onto the bars from one side\n"+
		"and move your way to the other side using just your arms. It is\n"+
		"constructed of large red poles built into the ground, using smaller\n"+
		"poles to connect the two sides together.\n";

items =

({
	"bars",
	"Large red bars connect the equipment together",
	"poles",
	"Large red poles go deep into the ground, making the equipment stable",
	"monkey bars",
	"The monkey bars metal glistens in the sun",
	"equipment",
	"Many different pieces of playground equipment litter the area",
	"ground",
	"The ground is covered in mulch",
	"mulch",
	"Chopped up tree bark litters the ground",
});

dest_dir =
({
	"/players/shinshi/areas/coining/rooms/outside1.c",	"west",
	"/players/shinshi/areas/coining/rooms/outside3.c",	"east",
});
}
