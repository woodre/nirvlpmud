#include "/players/jaraxle/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("helm");
set_alias("helmet");
set_short("Great helm");
set_long(
"  A steel helm with a nose guard shaped like the Templar cross. It\n"+
"is lightweight and seems resistant to most attacks.\n");
set_ac(1);
set_type("helmet");  
set_weight(1);
set_value(250);
 
}

