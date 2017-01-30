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
	set_row(1);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The " + ASPHALT +  " continues north and south from here. "
		+ "To the east you can see a line of collapsing midway booths. To the west is "
		+ "a tall chain link fence topped with razor wire. "
		+ "To the north you can see an intersection in the asphalt path. "
		+ "In the opposite direction a silent ferris wheel looms far above the trees."
	);

	add_exits("n,s");
}

void
init() {
	::init();
}
