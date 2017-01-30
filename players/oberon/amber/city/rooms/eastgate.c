#include <ansi.h>
inherit "/room/room.c";

reset(arg) {
	::init(arg);
	if(arg) return;
	set_light(1);
	short_desc = "Inside the East Gate of Amber";
	long_desc =
		"Finally inside the city of Amber, the large entrance gate is to the\n"+
		"east. To the north and south lay a road that wraps around the eastern\n"+
		"side of the city. To the west is Amber Road. You can hear the bustle\n"+
		"of people throughout the streets.\n";
	items = ({
		"gate",
			"A large gate towers to the east.\n"+
			"It appears large enough for armies to march through",
	});
	dest_dir = ({
		"/players/oberon/amber/city/rooms/eastwall2","north",
		"/players/oberon/amber/city/rooms/eastwall3","south",
		"/players/oberon/amber/city/rooms/amberstreet5","west",
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
		write("The eastern gate to the city is sealed shut.\n");
		return 1;
	}
}