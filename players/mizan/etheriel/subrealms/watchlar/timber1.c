#include "std.h"
id(str) { return str == "alskdj" || str == "timber"; }
short() { return "A fallen timber"; }
long() {
write("This timber collapsed fromthe ceiling, and has apparently been rolled\n"+
"around on the floor.\n");
}
init() {
	add_action("roll","roll");
	}
roll(str) {
	if(!str) return 0;
	if(str="timber") {
	write("You try to roll the timber, but it won't budge any further.\n");
	say((this_player()->query_name())+" tries to roll the timber.\n");
	return 1;
	}
return 0;
}
