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

	set_col(3);
	set_row(2);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The " + ASPHALT + " continues down the midway. "
		+ "From a big stall on the south side of the path you can smell the "
		+ "sickeningly delicious aroma of deep fried " + OREOS + " and " + yel("Twinkies") + ". "
		+ "Is it possible that after all these years a fryer is still working? "
		+ "To the north is a long counter covered with toy rifles. Amazingly, "	
		+ hiy("bright yellow ducks") + " still march in a line across the back of the booth."
	);

	add_exits("n,s,e,w");
}

void
init() {
	::init();
}
