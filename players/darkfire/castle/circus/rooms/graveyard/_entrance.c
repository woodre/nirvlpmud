#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

inherit "/players/darkfire/castle/circus/rooms/graveyard/_base.c";

void construct() {
	::construct();

	/* Set the long description (displayed when someone looks at the room). */
	set_long("Through the thickly overgrown bushes you can see a small "
		+ hiw("white fence") + " with a gate in it to the north. Behind the gate is an open "
		+ "grassy area with several mounds of dirt and tombstones. It's a "
		+ "graveyard! At the center of the graveyard is a huge magnolia tree "
		+ "with strange long white flowers or fruit hanging from it."
	);

	/* Add the obvious exits. */
	add_exit(path() + "b1", "north");
	add_exit(PATH_TRAIN + "f11", "boxcar");
}
