#include "/sys/ansi.h"
#include "/sys/lib.h"
inherit "/room/room";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_light(1);
	short_desc = "Along the western wall";
	long_desc =
		"Along the western wall of Amber. The road is paved with colorful\n"+
		"cobblestone. To the west is an enormous wall that seems to wrap\n"+
		"around the whole city. Sounds of the citizens can be heard from the\n"+
		"streets and shops. The street extends to the north and south.\n";
	dest_dir = ({
		"/players/oberon/amber/city/rooms/westgate","north",
		"/players/oberon/amber/city/rooms/westwall4","south",
	});
	if(random(2)) move_object(clone_object("/players/oberon/amber/city/mob/adult.c"), this_object());
	if(random(2)) move_object(clone_object("/players/oberon/amber/city/mob/kid.c"), this_object());
}
