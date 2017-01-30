#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/midway/_base.c";

void
reset(int arg) {
	int i;

	::reset();

	/* Clone the carny vendor who runs the joint. */
	if(!present("carny")) {
		move_object(clone_object(PATH_MONSTERS + "unique/carny_ring_toss"), this_object());
	}

	if(arg) return;

	/* Run the stuff that should happen only on first instantiation of the room. */
	set_col(1);
	set_row(3);

	set_short(RING_TOSS);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("This used to be a ring toss game. There are " + hiw("plastic ") + hig("rings") + " scattered "
		+ "all over the floor and piled up in the corners of the booth. Behind the "
		+ "collapsing wooden counter are packing crates covered with " + grn("green bottles") + " and "
		+ "more than a little broken glass. The missing bottles certainly make the game harder "
		+ "but it might be worth a try."
	);

	add_exits("s");
}

void
init() {
	::init();
}
