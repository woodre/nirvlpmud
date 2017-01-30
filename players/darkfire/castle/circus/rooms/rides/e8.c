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

	set_col(4);
	set_row(7);

	set_long(get_path_description());

	add_exit(PATH_MIDWAY + "d1", "north");
	add_exits("s,w");
}

void
init() {
	::init();
}
