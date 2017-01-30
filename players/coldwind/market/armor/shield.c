#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("buckler");
set_alias("shield");
set_short("A steel buckler");
set_long(
"A steel round buckler that can be worn in the arm from its\n"+
"leather handles. It's light and provides good protection against\n"+
"most attacks.\n");
set_ac(1);
set_type("shield");  
set_weight(1);
set_value(200);
}


