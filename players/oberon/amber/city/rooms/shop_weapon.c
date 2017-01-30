#include "/sys/ansi.h"
#include "/sys/lib.h"
inherit "/room/room";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_light(1);
	short_desc = "Amber Weapon Shop";
	long_desc =
		"The City of Amber's legendary Weapon Shop. Known across the land for\n"+
		"it's fine craftmanship, the weapons hung on the wall are some of the\n"+
		"finest around. From swords to the most exotic weapons, this is the\n"+
		"perfect spot for any warrior.\n";
	items = ({
		"weapons","Master craftmanship shines through on each and every weapon",
		"wall","Nothing special, other than the unbelievable weapons",
		"swords","Amongst the weapons, there are many swords",
	});
	dest_dir = ({
		"/players/oberon/amber/city/rooms/amberstreet5","south",
	});
	move_object(clone_object("/players/oberon/amber/city/mob/shopkeeper_weapon.c"), this_object());
}

init() {
	::init();
}
