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

	set_col(1);
	set_row(1);

	set_short(VIDEO_ARCADE);
	
	/* Set the long description (displayed when someone looks at the room). */
	set_long("Your feet crunch in the broken glass and plastic scattered around the floor. "
		+ "As your eyes adjust to the darkness you can make out dozens of old arcade games, "
		+ "from old school originals like Skee Ball to 8-bit games like " + GALAGA + " and " 
		+ hiw("Karate ") + hir("Champ")+". "
		+ "Most of the games are clearly destroyed, with their coin bins ripped open and their "
		+ "screens smashed. It's enough to make anyone who appreciates classic games shed a tear."
	);
	
	add_exits("n");
}

void
init() {
	::init();
}
