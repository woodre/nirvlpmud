#pragma strict_types

#include "/players/darkfire/castle/circus/circus.h"

inherit "/players/darkfire/obj/dfroom.c";

void
reset(int arg) {
	::reset();

	if(arg) return;

	set_long("d5");

	add_exit(PATH_TUNNELS + "d4","south");
}

void
init() {
	::init();
}
