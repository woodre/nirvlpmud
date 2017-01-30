inherit "/players/darkfire/castle/circus/monsters/scavenger/_scavenger";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"

#define RACCOON "A ring-tailed raccoon with a " + gry("bandit mask") + ".\n"

reset(arg) {

	::reset(arg);

	if(arg) return;

	set_name("raccoon");
	set_short("A scavenging raccoon");
	set_long(RACCOON);
}
