#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("chain");
set_alias("amulet");
set_short(HIW+"Chain "+HIK+"of the apes"+NORM);
set_long(HIW+
"  A shiny silver chain made of big silver rings. On a closer look,\n"+
"you notice that Ashgan's name is printed on every ring of the chains.\n"+
"They should provide good protection to the neck and shoulders.\n"+NORM);
set_ac(2);
set_type("amulet");  
set_weight(1);
set_value(1400);
}



