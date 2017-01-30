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
	set_row(4);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The " + ASPHALT2 + " path curves south and east from here, circling the midway. "
		+ "To the west you can see a rusty turnstile underneath an iron archway that somehow still stands. "
		+ "An old fortune-telling machine lies on its side here. Its glass has long been shattered, "
		+ "and the sharp shards are stained with " + hir("blood") + ". A ticket still protrudes from the "
		+ "slot in the front. The fortune teller itself is missing."
	);

	add_exits("s,e");
}

void
init() {
	::init();
}
