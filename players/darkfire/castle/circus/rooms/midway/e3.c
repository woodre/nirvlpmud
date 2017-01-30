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

	set_col(4);
	set_row(2);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The road of " + ASPHALT + " continues down the midway. "
		+ "A small steel-sided shed stands shakily on the south side of the path. It looks "
		+ "out of place, with no signs or bright colors. You catch a "
		+ "whiff of " + yel("whiskey") + " and think it might have once been a "
		+ "hiding place for adults in need of a break from their lunatic children. "
		+ "To the north is an open area of " + grn("grass") + " surrounding a classic "
		+ "test of strength game."
	);

	add_exits("n,s,e,w");
}

void
init() {
	::init();
}
