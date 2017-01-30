inherit "/players/darkfire/castle/circus/monsters/scavenger/_scavenger";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"

#define POSSUM "A " + hiw("ghostly white") + " possum with a long " + hir("pink") + " tail.\n"

reset(arg) {

	::reset(arg);

	if(arg) return;

	set_name("possum");
	set_short("A scavenging possum");
	set_long(POSSUM);
}
