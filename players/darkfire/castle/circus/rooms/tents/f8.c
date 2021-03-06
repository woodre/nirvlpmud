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

	set_col(5);
	set_row(7);

	set_long(get_path_description());

	add_exits("s");
}

void
init() {
	::init();
}
