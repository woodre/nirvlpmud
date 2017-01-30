#include "/sys/ansi.h"
#include "/sys/lib.h"
inherit "/room/room";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_light(1);
	short_desc = "Northwest Corner of Amber";
	long_desc =
		"This is the northwest corner of the city of Amber. The city walls\n"+
		"tower above you to the west and north. Sounds of merchants can be\n"+
		"heard to the south.\n";
	dest_dir = ({
		"/players/oberon/amber/city/rooms/northwall1", "east",
		"/players/oberon/amber/city/rooms/westwall1", "south",
	});
	move_object(clone_object("/players/oberon/amber/city/mob/lunatic.c"), this_object());
}
