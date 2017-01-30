#include "/sys/ansi.h"
#include "/sys/lib.h"
inherit "/room/room";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_light(1);
	short_desc = "Outside the Castle of Amber";
	long_desc =
		"Standing in front of the majestic Castle of Amber. There are huge gates\n"+
		"to the north. It looks as though a whole army can march through them. To\n"+
		"the east and west are guard shacks. To the south leads back to the City\n"+
		"of Amber.\n";
	dest_dir = ({
		"/players/oberon/amber/city/rooms/guardhouse2","east",
		"/players/oberon/amber/city/rooms/castleway2","south",
		"/players/oberon/amber/city/rooms/guardhouse1","west",
	});
	move_object(clone_object("/players/oberon/amber/city/mob/guardboss.c"), this_object());
	move_object(clone_object("/players/oberon/amber/city/mob/gateguard.c"), this_object());
	move_object(clone_object("/players/oberon/amber/city/mob/gateguard.c"), this_object());
}
