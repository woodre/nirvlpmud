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

	set_col(2);
	set_row(7);

	set_short(MINE_NAME);

	set_long(get_mine_description());

	add_exits("e,w");
}

void
init() {
	::init();
}
