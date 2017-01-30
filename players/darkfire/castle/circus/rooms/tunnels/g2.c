#pragma strict_types

#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/tunnels/_base.c";

void
reset(int arg) {
	::reset();

	if(arg) return;

	set_col(6);
	set_row(1);

	set_long_bend();

	add_exits("n,w");
}

void
init() {
	::init();
}
