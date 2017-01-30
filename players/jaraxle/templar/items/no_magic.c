#include "/players/jaraxle/define.h"

id(str){ return str == "holy@ground"; }
query_weight() { return 1; }
get() { return 0; }
take() { return 0; }
add_property("no_magic");
