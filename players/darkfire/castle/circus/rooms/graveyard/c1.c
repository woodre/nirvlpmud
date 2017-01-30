#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/graveyard/_base.c";

void reload() {
	::reload();

	add_tombstone();
}

void construct() {
	::construct();

	set_col(2);
	set_row(0);

	set_long(get_graveyard_description());

	add_exits("n,s,e,w");
}
