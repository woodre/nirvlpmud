#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("gloves");
set_short(HIB+"Gloves"+HIK+" of the apes"+NORM);
set_long(HIB+
"  A pair of soft blue fingerless gloves. Small shiny pieces\n"+
"of metal have been added to the back sides of the gloves for\n"+
"decoration\n"+NORM);
set_ac(2);
set_type("gloves");
set_weight(1);
set_value(1000);
}
