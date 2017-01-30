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

	set_col(1);
	set_row(4);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The " + ASPHALT + " continues east and west from here. "
		+ "A pair of " + hig("giant ferns") + " overhang the path, dripping water on you. "
		+ "The path is slick with " + grn("moss") + ", and it grows across the rotted wooden roofs of "
		+ "the old midway booths to the south. Through the trees to the north you can see "
		+ "the tattered remains of old tents."
	);

	add_exits("e,w");
}

void
init() {
	::init();
}
