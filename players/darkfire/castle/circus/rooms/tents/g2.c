#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/tents/_base.c";

void
reset(int arg) {
	::reset();

	if(arg) return;

	set_col(6);
	set_row(1);

	set_short(TENT_CLOWNS);

	set_long(get_tent_description());

	add_exits("s,e");
}

void
init() {
	::init();
}
