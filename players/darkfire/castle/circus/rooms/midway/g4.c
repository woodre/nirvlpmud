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
	set_row(3);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The " + ASPHALT + " path narrows as it continues north and south. "
		+ "Weeds and small saplings push their way through the cracks, tripping you "
		+ "as you walk and forcing you to push them aside. A giant face with a "
		+ blk("top hat") + " lies at an awkward angle beside the path. Inside the "
		+ "gaping mouth you can see a steering wheel. It must have been some sort "
		+ "of golf cart."
	);

	add_exits("n,s");
}

void
init() {
	::init();
}
