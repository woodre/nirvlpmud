#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("shoes");
set_alias("boots");
set_short(HIK+"Big dark boots"+NORM);
set_long(
"  A pair of big black boots. They are made of incredibly thick\n"+
"material, yet they seem very comfotrable.\n");
set_ac(1);
set_type("boots");  
set_weight(1);
set_value(400);
}


