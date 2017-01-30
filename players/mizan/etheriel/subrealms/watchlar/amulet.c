#include "std.h"
id(str) { return str == "amulet" || str == "amelk"; }
short() { return "A broken crystal amulet"; }
long() {
write("This is a broken crystal amulet. The level of craftsmanship is very high\n"+
"but the amulet is faded and worn, and the crystal in the middle has been\n"+
"cracked into bits.\n");
}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 240; }
