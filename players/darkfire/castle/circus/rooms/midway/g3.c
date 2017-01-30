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
	set_row(2);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The " + ASPHALT2 + " path widens here as it leads in three directions. "
		+ "To the north and south, the path leads you around the outside of the midway, "
		+ "and going west will take you through the ruined midway. Off to the east you see a small "
		+ "trail that leads towards a set of railroad cars with " + AREA_NAME + " painted "
		+ "on the sides."
	);
	
	add_exit(PATH_TRAIN + "a6", "east");

	/* Add the obvious exits. */
	add_exits("n,s,w");
}

void
init() {
	::init();
}
