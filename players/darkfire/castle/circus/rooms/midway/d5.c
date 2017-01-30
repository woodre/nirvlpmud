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

	set_col(3);
	set_row(4);

	set_long("The "+gry("asphalt")+" path continues west and east, though the roots of ancient oaks "
		+ "have nearly reclaimed the terrain. " + GRAFFITI + " covers a pair of " 
		+ gry("50 gallon drums") + " that have been used for trash fires at some point. Rusted husks of booths "
		+ "line the midway to the south. "
		+ "The skeletons of old circus tents can be seen through the thick trees. A small path winds "
		+ "its way north toward them."
	);

	/* Add the obvious exits. */
	add_exits("e,w");
	add_exit(PATH_TENTS + "d1", "north");
}

void
init() {
	::init();
}
