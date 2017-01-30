#include "/sys/ansi.h"
#include "/sys/lib.h"
inherit "/room/room";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_light(1);
	short_desc = "Amber Street";
	long_desc =
		"Amber Road is one of the main intersecting roads of Amber, thus the\n"+
		"name. This is the road that seperates the north half of the city\n"+
		"from the south. To the east is the eastern gate of the city, and\n"+
		"the sounds of merchants can be heard to the north, and west.\n";
	dest_dir = ({
		"/players/oberon/amber/city/rooms/shop_weapon","north",
		"/players/oberon/amber/city/rooms/eastgate","east",
		"/players/oberon/amber/city/rooms/amberstreet4","west",
	});
}
