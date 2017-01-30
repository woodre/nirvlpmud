inherit "/players/darkfire/castle/circus/monsters/scavenger/_scavenger";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"

#define CAT "A scrawny " + gry("grey tabby cat") + " with a " + hiw("white-tipped") + " tail and paws.\n"

reset(arg) {

	::reset(arg);

	if(arg) return;

	set_name("cat");
	set_short("A scavenging cat");
	set_long(CAT);
}
