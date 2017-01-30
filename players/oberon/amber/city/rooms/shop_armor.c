#include "/sys/ansi.h"
#include "/sys/lib.h"
inherit "/room/room";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_light(1);
	short_desc = "Amber Armor Shop";
	long_desc =
		"The City of Amber's legendary Armor Shop. Known across the land for\n"+
		"it's fine craftmanship, the armors hung on the wall are some of the\n"+
		"finest around. From rings to the most exotic armors, this is the\n"+
		"perfect spot for any warrior.\n";
	items = ({
		"armors","Master craftmanship shines through on each and every armor",
		"wall","Nothing special, other than the unbelievable armors",
		"rings","Amongst the armors, there are many rings",
	});
	dest_dir = ({
		"/players/oberon/amber/city/rooms/amberstreet4","south",
	});
	move_object(clone_object("/players/oberon/amber/city/mob/shopkeeper_armor.c"), this_object());
}

init() {
	::init();
}
