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
	if(!present("vendor"), this_object()) {
		move_object(clone_object(PATH_MONSTERS + "unique/vendor_snacks"), this_object());
	}

	if(arg) return;

	set_col(3);
	set_row(1);

	set_short(SNACK_SHACK);
	
	/* Set the long description (displayed when someone looks at the room). */
	set_long("A neon sign hanging over the formica counter somehow "
		+ "still flickers dimly after all this time. Although most of this booth "
		+ "is rotted and crumbling wood, the cooking area and countertops are still "
		+ "relatively sturdy since they are constructed from " + hiw("stainless steel") + ". "
		+ "Is it your imagination or do you smell the scent of hot cooking grease. "
		+ "Perhaps you can try to order food..."
	);
	
	add_exits("n");
}

void
init() {
	::init();
}
