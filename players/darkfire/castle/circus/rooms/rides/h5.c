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

	set_col(7);
	set_row(4);

	set_long(get_path_description() 
		+ " To the north is an archway made of two giant wooden swords leading to a carousel."
	);

	add_exits("n,s,w");
}

void
init() {
	::init();
}
