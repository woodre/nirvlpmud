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

	set_col(6);
	set_row(5);

	set_long(get_path1_description()
		+ " To the west you see a spot where you can squeeze between two train cars by jumping onto the platform between them."
	);
	
	add_exits("w,e");
}

void
init() {
	::init();
}
