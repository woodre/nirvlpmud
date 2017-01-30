#include "/sys/ansi.h"
#include "/sys/lib.h"
inherit "/room/room";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_light(1);
	short_desc = "Information Center";
	long_desc =
		"Maps and brochures. Everywhere. The shopkeeper here seems to be in over\n"+
		"his head in information. There is barely a space on the wall that is\n"+
		"visible, with maps posted on every square inch. His desk is stacked with\n"+
		"maps, as well as brochures. If one were looking for information, they\n"+
		"certainly came to the right spot.\n";
	items = ({
		"maps","They are everywhere. It would be harder not to look at them",
		"brochures","They are everywhere. It would be harder not to look at them",
		"wall","You find an empty spot on the wall near... No, that's another paper",
		"desk","As far as can be seen, it could just be a giant stack of papers",
	});
	dest_dir = ({
		"/players/oberon/amber/city/rooms/southgate","south",
	});
	move_object(clone_object("/players/oberon/amber/city/mob/shopkeeper_info.c"), this_object());
}

init() {
	::init();
}
