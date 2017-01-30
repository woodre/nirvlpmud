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

	set_col(7);
	set_row(3);

	set_long(get_path_description() 
		+ " To the south is a " + hiw("gaping clown's mouth") + " with painted lettering that's too faded to read."
	);

	add_exits("n,w,s");
}

void
init() {
	::init();
}
