#include "/players/francesco/univ/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("glass");
set_alias("glass");
set_short(""+HIR+"Red"+NORM+" and "+GRN+" green"+NORM+" 3D glasses");
set_long(
   "   These glasses have one red lens and one green lens.\n"+
   "They are designed to allow the user to see hidden \n"+
   "colored patterns embedded in a text.\n");

set_ac(3);
type= "button";  
set_weight(1);
set_value(100);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

id(str) { return str == "glass" ; }
