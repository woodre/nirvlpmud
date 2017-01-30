inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("shinshi_lip_mob")) {
	move_object(clone_object("/players/shinshi/areas/coining/mobs/studentlip.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = "A slide";
	long_desc =
		"There is a giant metal slide in this part of the playground.\n"+
		"The ladder of the slide goes up to about seven feet high, and\n"+
		"the metal part of the slide goes down in a spiral.\n";

items =

({
	"slide",
	"The slide goes down in a steep drop spiral",
	"ladder",
	"Eleven stairs, when climbed, take the user to the top of the slide",
	"stairs",
	"Long, skinny bars that allow the user to climb to the top",
	"spiral",
	"It rapidly spins download in a circular pattern",
	"bars",
	"Thick metal bars spaced evenly apart creating stairs",
});

dest_dir =
({
	"/players/shinshi/areas/coining/rooms/outside2.c",	"west",
	"/players/shinshi/areas/coining/rooms/outside4.c",	"south",
});
}
