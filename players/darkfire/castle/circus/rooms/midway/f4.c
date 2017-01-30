#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/midway/_base.c";

void
reset(int arg) {

	::reset();

	/* Clone the carny vendor who runs the joint. */
	if(!present("carny"), this_object()) {
		move_object(clone_object(PATH_MONSTERS + "unique/carny_dunk_tank"), this_object());
	}

	if(arg) return;

	set_col(5);
	set_row(3);

	set_short(DUNK_TANK);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("Shreds of " + UTIL->alternate("striped canvas", CH_BY, 1) + NORM + " wall in this area. "
		+ "Sitting against the back wall is a " + gry("metal tank") + " about three feet deep and "
		+ "filled with " + grn("green water") + " that smells like dead rat soup. "
		+ "There is a small wooden seat suspended over it where surely at one time a clown sat "
		+ "taunting passersby until they paid to throw baseballs at the " + red("red") + " bullseye "
		+ "target, dumping the mouthy clown into the water."
	);

	add_exits("s");
}

void
init() {
	::init();
}
