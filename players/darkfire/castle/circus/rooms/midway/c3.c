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

	set_col(2);
	set_row(2);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The " + ASPHALT + " continues down the midway. "
		+ "South of you is a large booth lined with shelves covered with tattered packages and "
		+ "shreds of polyester filling. To the north is a long counter. Behind it you "
		+ "can make out a wall covered with wrinkled, deflated balloons in " + MYRIAD_COLORS + ". "
	);

	add_exits("n,s,e,w");
}

void
init() {
	::init();
}
