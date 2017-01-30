#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("crown");
set_alias("helmet");
set_short(HIY+"Golden Crown"+NORM);
set_long(
"A heavy crown made of gold and decorated with a red ruby that \n"+
"is taking the shape of a heart. King of the hearts was wearing\n"+
"this crown at some point.\n"+NORM);
set_ac(1);
set_type("helmet");  
set_weight(2);
set_value(800);
}
