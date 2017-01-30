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

	set_col(6);
	set_row(1);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The " + ASPHALT + " path widens around a small fountain as it continues north and south. "
		+ "Weeds and small saplings push their way through the cracks, tripping you "
		+ "as you walk and forcing you to push them aside. The fountain is covered "
		+ "with thick " + grn("grape vines") + " that almost hide the shape of a leering "
		+ "clown underneath, holding a seltzer bottle that oozes " + grn("algae") + " and "
		+ "a trickle of " + blu("water") + "."
	);

	add_exits("n,s");
}

void
init() {
	::init();
}
