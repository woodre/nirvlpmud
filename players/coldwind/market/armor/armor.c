#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("chainmail");
set_alias("armor");
set_short(HIK+"Suit of dark chainmail"+NORM);
set_long(
"A dark suit made of light chainmail rings and connected together with\n"+
"tough peices of deer skin at the shoulders and abdomen. The deer skin\n"+
"is covered with plates of steel.\n"+NORM);
set_ac(3);
set_type("armor");  
set_weight(3);
set_value(900);
}


