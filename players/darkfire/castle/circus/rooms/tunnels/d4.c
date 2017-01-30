#pragma strict_types

#include "/players/darkfire/castle/circus/circus.h"

inherit "/room/room.c";

void
reset(int arg) {
	::reset();

	if(!present("teddy")) {
		move_object(clone_object(PATH_MONSTERS + "bear"), this_object());
	}

	if(arg) return;

	set_long("d4");

	add_exit(PATH_TUNNELS + "d5","north");
}

void
init() {
	::init();
}
