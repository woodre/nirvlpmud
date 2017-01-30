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

	set_col(0);
	set_row(2);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The " + ASPHALT + " continues in all directions. "
		+ "To the east you can follow the path between a row of collapsing midway booths. "
		+ "Through an iron archway to the west is a food court. "
		+ "Continuing north will take you around the back of the midway booths. "
		+ "To the south, a silent ferris wheel looms far above the trees, encircles by an "
		+ "obviously worse-for-wear wooden roller coaster."
	);

	add_exits("n,s,e");
}

void
init() {
	::init();
}
