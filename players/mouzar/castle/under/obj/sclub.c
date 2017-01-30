#include "/obj/ansi.h"
inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("leg bone");
set_alias("bone");
set_short(WHT+"Leg Bone"+NORM);
set_long(
"This is the lower leg bone from some poor person.  You might\n"
+ "beable to use it as a club.\n");
set_value(400);
set_weight(3);
set_class(10);
}
