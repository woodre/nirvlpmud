#include "/players/bastion/closed/color.h"
#include "std.h"
id(str) { return str == "rose"; }

object person;
short() { return RED + "A lustrous red rose"+ OFF; }
long() {
write("  You gaze into the rose, and smile... Doesn't it feel good\n"+
"  to know that someone out there cares about you?\n\n"+
"\n");
	}
get() { return 1; }
