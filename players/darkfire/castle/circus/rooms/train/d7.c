#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/train/_base.c";

void
reset(int arg) {
	::reset();

	if(arg) return;

	set_col(3);
	set_row(6);

	set_long(get_path1_description());
	
	add_exits("w,s");
}

void
init() {
	::init();
}
