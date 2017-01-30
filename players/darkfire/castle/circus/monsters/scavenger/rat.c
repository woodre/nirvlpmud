inherit "/players/darkfire/castle/circus/monsters/scavenger/_scavenger";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"

#define RAT "A huge " + gry("black") + " and " + hiw("white") + " long-tailed rat with " + red("red") + " eyes.\n"

reset(arg) {

	::reset(arg);

	if(arg) return;

	set_name("rat");
	set_short("A scavenging rat");
	set_long(RAT);
}
