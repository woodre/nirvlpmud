#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("talisman");
set_alias("amulet");
set_short(HIG+"Emerald talisman"+NORM);
set_long(
"A peice of emerald green stone attached to a silver chain. The gods\n"+
"will protect those who wear this talisman.\n");
set_ac(1);
set_type("amulet");  
set_weight(1);
set_value(100);
}


