#include <ansi.h>
inherit "/room/room.c";

reset(arg) {
	::init(arg);
	if(arg) return;
	set_light(1);
	short_desc = "Inside the West Gate of Amber";
	long_desc =
		"Finally inside the city of Amber, the large entrance gate is to the\n"+
		"west. To the north and south lay a road that wraps around the western\n"+
		"side of the city. To the east is Amber Road. You can hear the bustle\n"+
		"of people throughout the streets.\n";
	items = ({
		"gate",
			"A large gate towers to the west.\n"+
			"It appears large enough for armies to march through",
	});
	dest_dir = ({
		"/players/oberon/amber/city/rooms/westwall2","north",
		"/players/oberon/amber/city/rooms/amberstreet1","east",
		"/players/oberon/amber/city/rooms/westwall3","south",
	});

	if(random(3) == 0)
		move_object(clone_object("/players/oberon/amber/city/mob/guardboss.c"), this_object());
	move_object(clone_object("/players/oberon/amber/city/mob/gateguard.c"), this_object());
	move_object(clone_object("/players/oberon/amber/city/mob/gateguard.c"), this_object());
}

init() {
	::init();
	add_action("open_gate","open");
}

open_gate(arg) {
	if(arg == "gate") {
		write("The western gate to the city is sealed shut.\n");
		return 1;
	}
}