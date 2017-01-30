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

	set_col(0);
	set_row(7);

	set_short(TENT_ILLUSIONIST);

	set_long(get_tent_description());

	add_exits("e,s");
}

void
init() {
	::init();
}
