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
	set_row(0);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The " + ASPHALT + " of the path curves north and west from here. "
		+ "A shelter is here, made to look like a pterodactyl with its wings "
		+ "outspread to protect you from the rain. The wings are now just skeletons, "
		+ "lacking the canvas that used to provide the protective membranes. So much "
		+ "for shelter from the weather."
	);

	/* Add the obvious exits. */
	add_exits("n,w");
}

void
init() {
	::init();
}
