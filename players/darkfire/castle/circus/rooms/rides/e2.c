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
	set_row(1);

	set_short(FUNHOUSE_NAME);

	set_long(get_funhouse_description());

	add_exits("n,s");
}

void
init() {
	::init();
}
