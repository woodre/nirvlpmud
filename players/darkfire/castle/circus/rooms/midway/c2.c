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
		move_object(clone_object(PATH_MONSTERS + "unique/vendor_shop"), this_object());
	}

	if(arg) return;

	set_col(2);
	set_row(1);

	set_short(SHOP_NAME);
	
	/* Set the long description (displayed when someone looks at the room). */
	set_long("This large booth is lined with dusty shelves. Judging by the tattered packages and "
		+ BROKEN_GLASS + " containing bits of balloons and clown faces, this was surely a "
		+ "souvenir shop. You can make out the gutted remains of stuffed " + blu("bears") + ", " + grn("frogs")
		+ ", and " + hiw("unicorns") + " among the ruins. Deflated balloons lay like shed snakeskins "
		+ "along the counter top."
	);
	
	add_exits("n");
}

void
init() {
	::init();
}
