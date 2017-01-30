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
	if(!present("carny"), this_object()) {
		move_object(clone_object(PATH_MONSTERS + "unique/carny_dart_throw"), this_object());
	}

	if(arg) return;

	set_col(2);
	set_row(3);

	set_short(DART_TOSS);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("This used to be a dart throwing game, judging by the back wall. It's covered "
		+ "with " + hiy("gold stars") + " and in the center of each star a "
		+ BALLOON + " is fastened. Almost all of them are sad and wrinkly, but "
		+ "there are a few that have miraculously stayed inflated. It might be "
		+ "possible to find a few darts to play with."
	);

	add_exits("s");
}

void
init() {
	::init();
}
