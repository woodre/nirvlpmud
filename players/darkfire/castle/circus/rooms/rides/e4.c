#pragma strict_types

#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/rides/_base.c";

void
reset(int arg) {
	::reset();

	if(arg) return;

	set_col(4);
	set_row(3);

	set_long(get_path_description() 
		+ " To the south is a gaping clown's mouth with painted lettering that's too faded to read."
		+ " To the west you can see a huge wooden roller coaster, the gates to which are laying on the ground."
	);
	
	add_exits("n,s,e,w");
}

void
init() {
	::init();
}
