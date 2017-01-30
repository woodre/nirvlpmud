#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("fingerless gloves");
set_alias("gloves");
set_short(HIB+"Fingerless gloves"+NORM);
set_long(
"  A pair of soft blue fingerless gloves used to add some\n"+
"protection to the hands and to provide better holding of weapons.\n"+
"Small shiny pieces of metal have been added to the back of the\n"+
"gloves for decoration\n");
set_ac(1);
set_type("gloves");  
set_weight(1);
set_value(500);
}
