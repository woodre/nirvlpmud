#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("tunic");
set_alias("armor");
set_short(HIR+"Red tunic"+NORM);
set_long(HIR+
"  A heavy tunic made from adorable red fabrics. It was said\n"+
"that Ashgan could create such strange fabrics using her dark magic.\n"+NORM);
set_ac(3);
set_type("armor");  
set_weight(3);
set_value(1000);
}


