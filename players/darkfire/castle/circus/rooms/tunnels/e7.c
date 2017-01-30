#pragma strict_types

#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/tunnels/_base.c";

void
reset(int arg) {
	::reset();

	if(arg) return;

	set_col(4);
	set_row(6);

	set_long_alcove();

	add_exits("n,w");
}

void
init() {
	::init();
}
