#include "std.h"
id(str) { return str == "sword" || str == "scabbard" || str == "berenyi"; }
get() { return 1; }
query_weight() { return 4; }
query_value() { return 10000; }
short() { return "A sword in a locked scabbard"; }
long() {
write("This sword is locked in its scabbard. It appears to be some kind of\n"+
"magical lock, and there is an inscription on the hilt that can be read.\n");
}
init() {
	add_action("read","read");
	}
read(str) {
	if(!str) return 0;
	if(str!="inscription") return 0;
	if(str="inscription") {
	write("The inscription reads: 'I belong to Etheriel'.\n");
	return 1;
	}
return 0;
}
