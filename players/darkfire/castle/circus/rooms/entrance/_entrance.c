#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"

/* Inherit the area base room. */
inherit "/players/darkfire/castle/circus/rooms/_circus.c";

void
reset(int arg) {
	if(arg) return;
	::reset();

	/* Set the long description (displayed when someone looks at the room). */
	set_long("The entrance room to the entrance area.");
}

void
init() {
	::init();
}

string 
path() {
	return PATH_ENTRANCE;
}
