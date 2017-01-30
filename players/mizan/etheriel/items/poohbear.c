#include "std.h"
id(str) { return str == "bear" || str == "pooh" || str == "poohbear" || str == "winnie"; }
get() { return 1; }
query_weight() { return 1; }
query_value() { return 55; }
short() { return "A pooh bear"; }
long() {
write("This is a stuffed Winnie the Pooh bear. It looks like it needs to\n"+
"be hugged.\n");
}
init() {
	add_action("hug","hug");
	}
hug(str) {
	if(!str) return 0;
	if(str == "pooh" || str == "bear" || str == "poohbear" || str == "winnie" ) {
	write("You hug a pooh bear, and you feel like it is smiling back at you.\n");
	say((this_player()->query_name())+" squeezes a stuffed Pooh bear very tightly while making\n"+"funny gurgling noises.\n");
	return 1;
	}
return 0;
}
