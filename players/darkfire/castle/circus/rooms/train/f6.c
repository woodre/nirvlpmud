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

	set_col(5);
	set_row(5);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("You're standing on a small platform with steps leading down "
		+ "from it to the east and west, where you can see a small dirt track "
		+ "leading off through the forest. Immediately to the west you can see "
		+ "another trail intersecting this one, and farther away you can "
		+ "faintly discern some old buildings and tall poles rising from the trees "
		+ "with tattered canvas fluttering from them. Is that an old wooden roller "
		+ "coaster?"
	);
	
	add_exits("w,e");
}

void
init() {
	::init();
}
