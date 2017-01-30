inherit "/players/darkfire/castle/circus/monsters/ghoul/_ghoul";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
#include "../../circus.h"

#define CLOTHES UTIL->alternate("spotted jumpsuit", CH_RAINBOW, 2) + NORM

reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("clown");
	set_alt_name("clown");

	set_short("A ghoulish clown");

	set_long(UTIL->wrap("The ghoul leers at you with a ghastly grin. "
		+ "Its mouth is filled with countless, inhumanly sharp teeth the size "
		+ "of daggers. Long, gangly arms hang nearly to the ground, where the "
		+ "fingers scrape razor-sharp claws through dirt and stone alike. The clown "
		+ "crouches, ready to pounce. The " + CLOTHES + " and giant " + hiy("yellow shoes ")
		+ "would normally look ridiculous, but you don't feel like laughing.")
		+ "\n"
	);
}
