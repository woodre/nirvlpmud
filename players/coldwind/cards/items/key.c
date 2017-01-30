#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("belt");
set_alias("misc");
set_short(HIB+"Blue belt"+NORM);
set_long(HIB+
"A blue belt that can be wrapped around the waist to add more protection.\n"+ 
"One side of the belt looks glossy, while the other is dull blue with \n"+
"Ashgan's name sewed in dark blue letters.\n"+NORM);
set_ac(1);
set_type("misc");  
set_weight(1);
set_value(500);
}
