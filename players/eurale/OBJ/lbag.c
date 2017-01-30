/*
  large leather bag
*/

#include "/players/eurale/closed/ansi.h"
inherit "obj/container";

reset(arg) {
  ::reset(arg);

short_desc = GRY+"large leather pocket"+NORM;
long_desc=
  "A large leather pocket with a wide shoulder strap.\n";

value = 100;
max_weight = 21;
local_weight = 0;
set_weight(1);
}

can_put_and_get() { return 1; }

get() { return 1; }

id(str) { return (
		str == "pocket" ||
		str == "leather pocket");
}

query_save_flag() { return 1; }
