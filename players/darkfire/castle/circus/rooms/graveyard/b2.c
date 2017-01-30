#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/graveyard/_base.c";

void reload() {
	::reload();

	add_monster_if_not_present("necromancer", NECROMANCER, 1);
}

void construct() {
	::construct();

	set_col(1);
	set_row(1);

	set_long("An ancient " + hiw("magnolia") + " tree dominates the center of the graveyard. "
		+ "The oddly shaped flowers are now discernable as numerous "
		+ hiw("bones") + ", somewhat human but distorted and twisted in their shape. "
		+ "Scattered under the heavy branches are bits of flesh and puddles of strangely colored "
		+ FLUID + " mixed with blood. It looks as if someone has been experimenting with "
		+ "the combination of toxic waste and necromantic magic."
	);

	add_exits("n,s,e,w");
}
