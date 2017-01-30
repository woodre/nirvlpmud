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
	if(!present("carny"), this_object()) {
		move_object(clone_object(PATH_MONSTERS + "unique/carny_high_striker"), this_object());
	}

	if(arg) return;

	set_col(4);
	set_row(3);

	set_short(HIGH_STRIKER);

	/* Set the long description (displayed when someone looks at the room). */
	set_long("This is an open area of grass and mud surrounding the famous "
		+ "game of strength, comprised of a tall metal pole with a " 
		+ yel("copper bell") + " on top. There is a groove running up the length of it with a heavy "
		+ gry("iron weight") + " attached. At the base is a pad of heavy leather on a lever arm. "
		+ "Several long-handled mallets lean against the neighboring booths. "
		+ "It may be worth taking a shot at ringing the bell, though it looks like the "
		+ "mallet might simply rot away in your hands."
	);

	add_exits("s");
}

void
init() {
	::init();
}
