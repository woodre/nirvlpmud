#include <ansi.h>

id(str) { return str == "portal"; }
reset () {}
short() {
	return HIB+"A portal of light"+NORM;
}
long() {
	write("The portal seems to shift and move about the "+HIB+"blue light"+NORM+" that is pouring\n"+
"from within it. You wonder if this could be the portal from the myths.\n");
}
get() { return 0; }
query_weight() { return 0; }
query_value() { return 5000; }
