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
	set_row(0);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The " + ASPHALT2 + " path curves north and east from here, circling the midway. "
		+ "To the west you can see a rusty turnstile underneath an iron archway that somehow still stands. "
		+ "A rusty cigarette vending machine sits here, its plastic cover smashed in where it used to have "
		+ "a picture of " + yel("Joe Camel") + "."
	);

	/* Add the obvious exits. */
	add_exits("n,e");
}

void
init() {
	::init();
}
