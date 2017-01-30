#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/rides/_base.c";

void
reset(int arg) {
	::reset();

	if(arg) return;

	set_col(0);
	set_row(2);

	set_short(COASTER_NAME);

	set_long(get_coaster_description());

	add_exits("n");
	add_exit(path() + "c2", "southeast");
}

void
init() {
	::init();
}
