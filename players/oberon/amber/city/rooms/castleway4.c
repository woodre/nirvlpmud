#include "/sys/ansi.h"
#include "/sys/lib.h"
inherit "/room/room";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_light(1);
	short_desc = "Castle Way";
	long_desc =
		"You stand on one of the main roads of Amber. Castle Way leads from the\n"+
		"center of Amber all the way to the castle. The road itself is not much\n"+
		"to look at. The ground is covered in simple cobblestone, with buildings\n"+
		"lining it to the east and west. The Castle of Amber can be seen to the\n"+
		"north. South leads back to the Center of Amber.\n";
	dest_dir = ({
		"/players/oberon/amber/city/rooms/castleway3","north",
		"/players/oberon/amber/city/rooms/amberstreet3","south",
	});
}
