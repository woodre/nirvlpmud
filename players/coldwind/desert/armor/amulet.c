#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("chains");
set_alias("amulet");
set_short(HIW+"Silver chains"+NORM);
set_long(
"  Shiny silver chains made of big silver rings. On a closer look,\n"+
"you notice that Ashgan's name is printed on every ring of the chains.\n"+
"They should provide some protection to the neck and shoulders.\n");
set_ac(1);
set_type("amulet");  
set_weight(1);
set_value(700);
}


