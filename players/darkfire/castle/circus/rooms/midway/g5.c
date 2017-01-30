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

	set_col(6);
	set_row(4);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The " + ASPHALT + " of the path curves south and west from here. "
		+ "The rotting branches of a giant long dead oak tree hang low enough to make you "
		+ "duck. A bunch of "+red("rusty")+" pipes are leaned up against the trunk, nearly "
		+ "covering a huge dented " + CLOWN_HEAD + "."
	);

	add_item("head", "The clown's head is at least five feet across and covered in rust, dents, and graffiti");
	add_item("pipes", "A pile of rusty pipes lean up against the tree, making the "+UTIL->alternate("clown's head", C_BRY, 1)+NORM+" look like it's in prison.");

	add_exits("s,w");
}

void
init() {
	::init();
}
