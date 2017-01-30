#include "/sys/ansi.h"
#include "/sys/lib.h"
inherit "/room/room";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_light(1);
	short_desc = "Southwest Corner of Amber";
	long_desc =
		"This is the southwest corner of the city of Amber. The city walls\n"+
		"tower above you to the west and south. Sounds of merchants can be\n"+
		"heard to the north.\n";
	dest_dir = ({
		"/players/oberon/amber/city/rooms/westwall4", "north",
		"/players/oberon/amber/city/rooms/southwall1", "east",
	});
}
