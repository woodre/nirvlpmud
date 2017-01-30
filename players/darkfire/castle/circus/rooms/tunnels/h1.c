#pragma strict_types

#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/tunnels/_base.c";

void
reset(int arg) {
	::reset();

	if(arg) return;

	set_col(7);
	set_row(0);

	set_long_bend();

	add_exits("n,w");
	add_exit(PATH_RIDES + "c6", "rides");
}

void
init() {
	::init();
}
