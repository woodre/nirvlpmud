inherit "/players/darkfire/castle/circus/monsters/scavenger/_scavenger";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"

#define DOG "A big dirty " + hiw("white") + " dog with long legs, torn ears, and " + hir("blood") + " on his muzzle.\n"

reset(arg) {

	::reset(arg);

	if(arg) return;

	set_name("dog");
	set_short("A scavenging dog");
	set_long(DOG);
}
