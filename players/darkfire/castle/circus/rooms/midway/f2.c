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

	set_col(5);
	set_row(1);

	set_short(FIRST_AID);
	
	/* Set the long description (displayed when someone looks at the room). */
	set_long("This is a small camper trailer strewn with old packages and boxes. "
		+ "A red container on the wall is marked with a biohazard symbol, and above "
		+ "that is a large " + red("red metal cabinet") + " with a " + hiw("white cross") + " on it. "
		+ "It might be possible to scavenge through the debris and find some medical supplies, "
		+ "especially if you are an inexperienced adventurer."
	);

	add_exits("n");
}

void
init() {
	::init();
}
