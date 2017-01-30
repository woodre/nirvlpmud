#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/rides/_base.c";

void
reset(int arg) {
	::reset();

	if(arg) return;

	set_col(6);
	set_row(6);

	set_short(CAROUSEL_NAME);
	
	set_long("You are in the very center of the carousel. "
		+ "You are surrounded by wheels and rusty pipes and cables all "
		+ "connected to the old engine that used to drive this carousel. "
		+ "Someone could turn this mild ride into a chaotic disaster if "
		+ "they made just the wrong (right?) adjustments to the controls."
	);

	add_exits("n,s,e,w");
}

void
init() {
	::init();
}
