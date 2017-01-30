#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("helmet");
set_alias("helm");
set_short(HIW+"Helm "+HIK+"of the apes"+NORM);
set_long(HIW+
"  A big helmet with a silver finish to add a shiny look.\n"+
"From the inside, soft cloth cover the sides to provide\n"+ 
"more comfort for the head.\n"+NORM);
set_ac(2);
set_type("helmet");  
set_weight(1);
set_value(1100);
}
