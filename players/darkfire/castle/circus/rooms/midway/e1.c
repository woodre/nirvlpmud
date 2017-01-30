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

	set_col(4);
	set_row(0);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The " + ASPHALT2 + " path continues west and east. "+grn("Vines")+" crawl from the undergrowth "
		+ "and cross the path, making the footing treacherous. To the north you can see the backs of "
		+ "the delapidated booths lining the midway. South of you, deep in the forest, you can see the "
		+ "skeletal remains of old amusement rides, bones rising up to display their lack of flesh."
	);

	/* Add the obvious exits. */
	add_exits("e,w");
}

void
init() {
	::init();
}
