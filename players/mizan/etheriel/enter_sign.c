#include "/players/bastion/closed/color.h"
id(str) { return str == "sign"; }
	short() { return BLINK + RED + "An important-looking sign" + OFF; }
	long() {
write("				Welcome to Etheriel\n"+
"	Type 'read sign' for some important information about this area.\n"+
	"\n");
	}

init() {
	add_action("read","read");
	}

read(str) {
	if(!str) return 0;
	if(str == "sign") {
	say((this_player()->query_name())+" reads the sign.\n");
	cat("/players/mizan/etheriel/WELCOME");
	return 1;
	}
	return 0;
	}
