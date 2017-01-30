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
	set_row(2);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("A road of " + ASPHALT + " runs the length of the midway. "
		+ "South you can see a booth with rotten wooden siding and a faded sign that "
		+ "says " + VIDEO_ARCADE + ". The booth's former door leans against the opening, unhinged. "
		+ "To the north is another booth with a long counter covered with " + hig("bright green bottles") + ". "
	);

	add_exits("n,s,e,w");
}

void
init() {
	::init();
}
