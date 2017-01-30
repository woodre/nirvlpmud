#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("belt");
set_alias("blue belt");
set_short(HIB+"Blue belt"+NORM);
set_long(
"  A blue belt that can be wrapped around the waist to add more\n"+
"protection. One side of the belt looks glossy, while the other\n"+
"is dull blue with Ashgan's name sewed in dark blue letters.\n");
set_ac(1);
set_type("belt");  
set_weight(1);
set_value(500);
}
