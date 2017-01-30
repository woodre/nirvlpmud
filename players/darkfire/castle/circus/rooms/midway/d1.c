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
	set_row(0);

	set_long("The " + ASPHALT2 + " path continues west and east. "
		+ "You can see the rusted out husks of booths lining the midway to the north. "
		+ "The skeletons of old amusement park rides can be seen to the south, steel "
		+ "beams and thick twisted cables rise into the air. "
		+ "A small path winds its way toward them."
	);

	/* Add the obvious exits. */
	add_exits("e,w");
	add_exit(PATH_RIDES + "e8", "south");
}

void
init() {
	::init();
}
