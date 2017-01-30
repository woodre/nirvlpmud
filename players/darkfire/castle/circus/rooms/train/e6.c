#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/train/_base.c";

void
reset(int arg) {
	::reset();

	if(arg) return;

	set_col(4);
	set_row(5);

	set_long(
		"You've reached an intersection of two trails, somewhere near the center of the abandoned train. "
		+ "To the east it looks like there's room to squeeze onto the platform between train cars. The path "
		+ "looks like it continues in that direction. To the west the track continues through the forest. "
		+ "A gravel path leads north and south alongside the line of faded, but brightly painted boxcars."
	);
	
	add_exits("n,s,w,e");
}

void
init() {
	::init();
}
