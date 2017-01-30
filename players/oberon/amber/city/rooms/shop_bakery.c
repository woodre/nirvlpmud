#include "/sys/ansi.h"
#include "/sys/lib.h"
inherit "/room/room";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_light(1);
	short_desc = "Amber Bakery";
	long_desc =
		"As you enter the shop, an immediate wall of strange food aromas\n"+
		"smashes into you. There are plants everywhere, as well as cooking\n"+
		"implements, and even chemistry sets everywhere. This shop has\n"+
		"everything a foodsmith could want!\n";
	items = ({
		"shop","The shop surrounds you, and protects you from the horrors of life",
		"plants","Various food based plants",
	});
	dest_dir = ({
		"/players/oberon/amber/city/rooms/amberstreet2","north",
	});
	move_object(clone_object("/players/oberon/amber/city/mob/shopkeeper_food.c"), this_object());
}
