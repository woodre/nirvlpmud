inherit "/players/darkfire/castle/circus/monsters/toy/_toy";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"

#define LABEL "bear"

reset(arg) {

	::reset(arg);

	if(arg) return;

	set_name(LABEL);

	set_short("A " + grn("moldy ") + UTIL->alternate("stuffed " 
	  + LABEL, UTIL->get_random_array_members(C_INTENSE, 2), 2) + NORM
	);

	set_long("The tattered remains of a stuffed " + LABEL 
	  + " with matted fur that smells of " + grn("mildew") 
	  + ". It is missing an eye, and " +hiw("stuffing")
	  + " oozes from a ripped seam in its belly.\n"
      + " It is wandering around the area, perhaps inhabited by an unseen spirit.\n"
    );

	set_wander(1);
	set_wander_interval(30);
	set_wander_realm(PATH_ROOMS);
}
