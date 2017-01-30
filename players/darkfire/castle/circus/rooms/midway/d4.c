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
		move_object(clone_object(PATH_MONSTERS + "unique/carny_duck_hunt"), this_object());
	}

	if(arg) return;

	set_col(3);
	set_row(3);

	set_short(DUCK_HUNT);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("This dilapidated shooting game is somehow still running, though "
		+ "the " + hiy("ducks") + " are not the nice clean things they used to be, but " 
		+ "look as if they've gone a few rounds with a kickboxer. Still, as they march "
		+ "around their little track in fits and starts it might be fun to grab one of "
		+ "the rusty toy air guns off of the counter and plink a few."
	);
	
	add_exits("s");
}

void
init() {
	::init();
}
