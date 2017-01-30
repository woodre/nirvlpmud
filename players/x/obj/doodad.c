#include "../x.h"
inherit "obj/treasure";

reset(x) { if(!x) {
 mapping m;
 m = ([ "ha":"la" ]);
 write(m["bob"]+"\n");
set_short("doodad");
set_id("doodad");
set_long("doodad\nding!\n");
set_weight(1);
}
}
