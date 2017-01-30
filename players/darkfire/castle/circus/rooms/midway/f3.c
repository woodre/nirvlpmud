#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/midway/_base.c";

void
reset(int arg) {
	::reset();

	if(arg) return;

	set_col(5);
	set_row(2);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The " + ASPHALT + " runs the length of the midway. "
		+ "South you can see a small travel trailer with the door hanging off of its "
		+ "hinges. Both of its tires are flat, slashed by something awfully sharp. "
		+ "To the north you can see the dunk tank, and by the smell of it, there's "
		+ "still some water left in it after years of abandonment."
	);

	add_exits("n,s,e,w");
}

void
init() {
	::init();
}
