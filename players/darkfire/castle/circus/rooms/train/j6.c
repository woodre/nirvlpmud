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

	set_col(9);
	set_row(5);

	set_short("A small clearing in the " + grn("woods"));

	set_long("After squeezing through the hole in the fence, you end up in a small clearing "
		+ "surrounded by thick woods and rolling hills. The tall trees block out most of the "
		+ "sunlight, and much of the undergrowth is damp from condensation. It smells slightly "
		+ "of rotten leaves, but a faintly acrid smell also touches your tongue, "
		+ yel("coppery") + " and sharp. To the west you can make out the bulky, square shapes of old railroad "
		+ "cars. At one time they were brightly colored, but now they are very faded. "
	);
	
	add_exits("w,e");
}

void
init() {
	::init();
}
