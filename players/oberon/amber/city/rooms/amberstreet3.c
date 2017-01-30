#include "/sys/ansi.h"
#include "/sys/lib.h"
inherit "/room/room";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_light(1);
	short_desc = "The Center of Amber";
	long_desc =
		"You stand at the very center of the city of Amber. Children can be\n"+
		"seen playing in the streets, and adults are wandering the shops. To\n"+
		"the east and west, you can see all the shops along Amber Street. A\n"+
		"very large castle can be seen to the north.\n";
	items = ({
		"center","It is the center of Amber",
		"amber","The city in which you stand",
		"castle","Most likely the Amber Castle",
	});
	dest_dir = ({
		"/players/oberon/amber/city/rooms/castleway4","north",
		"/players/oberon/amber/city/rooms/amberstreet4","east",
		"/players/oberon/amber/city/rooms/amberstreet2","west",
	});
	move_object(clone_object("/players/oberon/amber/city/obj/fountain.c"), this_object());
}
