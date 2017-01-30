#include "std.h"
id(str) { return str == "notice"; }
short() { return "A dev notice"; }
long() {
	write("This is a update on development notice. Type 'read notice'.\n");
	}
reset()
{
/* file doesnt exist, -Bp 24Feb99
   call_other("/players/mizan/closed/virii/barkan", "???");
*/
}

init() {
	add_action("read","read");
	}

read(str) {
	if(!str) return 0;
	if(str=="notice") {
	say((this_player()->query_name())+" reads the development notice.\n");
	cat("/players/mizan/etheriel/DEVNOTICE");
	return 1;
	}
return 0;
}
