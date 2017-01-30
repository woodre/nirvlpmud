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
	set_name("popcorn");
	add_alias("corn");
	set_short("A bag of stale " + POPCORN);

	set_long(UTIL->wrap("A " + UTIL->alternate("red and white", CH_RW, 1) + NORM
		+ " paper bag full of stale " + POPCORN + ".")
		+ "\n"
	);

	set_msg("You eat a handful of the stale "+POPCORN+".\n");
	set_msg2(" eats a handful of the stale "+POPCORN+".\n");
	add_cmd("eat");
	/* How do I make handfuls change to handful when it's at 1? */
	set_type("handfuls");
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
