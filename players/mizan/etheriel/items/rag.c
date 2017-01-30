#include "std.h"
id(str) { return str == "rag"; }
get() { return 1; }
query_weight() { return 1; }
query_value() { return 100; }
short() { return "A wet squishy rag"; }
long() { 
write("This is a wet, squishy rag. It looks like you can wipe things with it.\n");
}
init() {
	add_action("wipe","wipe");
	}
wipe(str) {
	if(!str) return 0;
	write("You wipe the rag all over "+str+".\n");
	say((this_player()->query_name())+" wipes down "+str+" with a wet, squishy rag.\n");
	return 1;
	}
