#pragma strict_types, verbose_errors

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
General Notes: A basic 50/50 heal.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Inherits
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
inherit "/obj/generic_heal.c";
inherit "/players/darkfire/obj/color";

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Includes
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#include <ansi.h>
#include "../../circus.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Initial construction of the object.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void reset(int arg) {
	::reset(arg);
	if (arg) return;
	set_name("cotton candy");
	add_alias("candy");
	set_short("A lump of crystallized " + COTTON_CANDY);

	set_long(UTIL->wrap("A " + hiw("white paper cone ")
		+ "with a sad-looking lump of crystallized sugar on it. "
		+ "Long ago it might have been " + COTTON_CANDY + ".")
		+ "\n"
	);

	set_msg("You bite off a chunk of the crystallized " + COTTON_CANDY + ".\n");
	set_msg2(" bites off a chunk of the crystallized " + COTTON_CANDY + ".\n");
	add_cmd("eat");
	add_cmd("bite");
	/* How do I make bites change to bite when it's at 1? */
	set_type("bites");
	set_heal(50,50);
	set_charges(3);
	set_stuff(6);
	set_soak(6);
	set_value(700);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Make it saveable.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
query_save_flag() {
	return 0;
}
