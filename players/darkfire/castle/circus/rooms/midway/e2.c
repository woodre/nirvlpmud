#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/midway/_base.c";

void reset(int arg) {
	::reset();

	/* Clone the carny vendor who runs the joint. */
	if(!present("desi")) {
		move_object(clone_object(PATH_MONSTERS + "unique/vendor_alcohol"), this_object());
	}

	if(arg) return;

	set_col(4);
	set_row(1);

	set_short(MIDWAY_PUB);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("This area has been squeezed in between the first aid station "
		+ "and the snack shop. Someone laid down remnants of "
		+ grn("green outdoor carpeting") + " and slapped together a shaky roof made of "
		+ hiw("tin") + " nailed to flimsy lumber. A plywood bar stretches along "
		+ "the back, and a line of rusty unicycles are welded together as bar stools. "
		+ "At some point, someone added a hand-painted sign that reads " + MIDWAY_PUB + "."
	);

	add_exits("n");
}
