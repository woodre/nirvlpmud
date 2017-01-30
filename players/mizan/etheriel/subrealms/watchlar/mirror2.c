#include "std.h"
object portal;
id(str) { return str == "mirror"; }
short() { return "An old cheval mirror"; }
long() { 
write("You look into the mirror, but you don't see your own reflection!\n"+
"There appears to be the face of a woman peering back at you.\n"+
"Maybe you can 'touch' the mirror and enter it.\n");
}
init()  {
	add_action("touch","touch");
	}
touch(str) {
	if(!str) return 0;
	if(str="mirror") {
	write("You touch the mirror, and are instantly absorbed into it.\n");
	write("The shard falls out behind you, and shatters completely.\n");
	portal=clone_object("players/mizan/etheriel/subrealms/watchlar/mirror.c");
	move_object(portal, environment());
	this_player()->move_player("into the mirror#players/mizan/etheriel/subrealms/watchlar/k17.c");
	destruct(this_object());
	return 1;
	}
return 0;
}
