#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("belt");
set_alias("belt of the apes");
set_short(HIB+"Belt "+HIK+"of the apes"+NORM);
set_long(HIB+
"  A blue belt that can be wrapped around the waist for protection.\n"+ 
"One side of the belt looks glossy, while the other is dull blue with \n"+
"Ashgan's name sewed in dark blue letters.\n"+NORM);
set_ac(2);
set_type("belt");  
set_weight(1);
set_value(1250);
}
