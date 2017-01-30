#include <ansi.h>
inherit "/room/room.c";

reset(arg) {
	::init(arg);
	if(arg) return;
	set_light(1);
	short_desc = "Inside the North Gate of Amber";
	long_desc =
		"Finally inside the city of Amber, the large entrance gate is to the\n"+
		"north. To the east and west lay a road that wraps around the northern\n"+
		"side of the city. To the north appears to be a large castle. South of\n"+
		"here leads back to the city. You can hear the bustle of people throughout\n"+
		"the streets.\n";
	items = ({
		"gate",
			"A large gate towers to the north.\n"+
			"It appears large enough for armies to march through",
	});
	dest_dir = ({
		"/players/oberon/amber/city/rooms/castleway2","north",
		"/players/oberon/amber/city/rooms/northwall3","east",
		"/players/oberon/amber/city/rooms/castleway3","south",
		"/players/oberon/amber/city/rooms/northwall2","west",
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