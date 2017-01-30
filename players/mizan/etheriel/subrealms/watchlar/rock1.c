#include "std.h"
id(str) { return str == "alskdj" || str == "rock"; }
short() { return "A rock"; }
long() {
write("This is an ordinary looking rock. It's kind of big, though. \n"+
"Maybe you can 'push' it.\n");
}
init() {
	add_action("push","push");
	}
push(str) {
	if(!str) return 0;
	if(str="rock") {
	write("You push the rock. It moves.\n");
	say((this_player()->query_name())+" pushes the rock, and watches it move.\n");
	return 1;
	}
return 0;
}
