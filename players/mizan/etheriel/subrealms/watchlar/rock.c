#include "std.h"
id(str) { return str == "rock"; }
short() { return "A rock"; }
long() {
write("This is an ordinary looking rock. It's kind of big, though. \n"+
"Maybe you can 'push' it.\n");
}
init() {
	add_action("push","push");
	}
push(str) {
	object gold, rock;
	if(!str) return 0;
	if(str="rock") {
	write("You struggle, and push the rock over, and find something!\n");
	say((this_player()->query_name())+" pushes a rock.\n");
	rock=clone_object("players/mizan/etheriel/subrealms/watchlar/rock1.c");
  move_object(rock, environment(this_player()));
	gold=clone_object("players/mizan/etheriel/items/beano-fgn.c");
   move_object(gold, environment(this_player()));
	destruct(this_object());
	return 1;
}
return 0;
}
