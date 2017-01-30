#include "std.h"
id(str) { return str == "mirror"; }
short() { return "A cheval mirror"; }
long() { 
write("This is an cheval mirror, almost identical to the one you had just\n"+
"entered, but it is in excellent condition, and lovingly cared for by\n"+
"Etheriel. After all, it is one of her two possessions. It looks as if\n"+
"you can leave this plane by 'touching' it.\n");
}
init()  {
	add_action("touch","touch");
	}
touch(str) {
	if(!str) return 0;
	if(str="mirror") {
	write("You touch the mirror, and are instantly absorbed into it.\n");
	this_player()->move_player("into the mirror#players/mizan/etheriel/subrealms/watchlar/k15.c");
	return 1;
	}
return 0;
}
