#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("helmet");
set_alias("helm");
set_short(HIW+"Silver helm"+NORM);
set_long(
"  A big helmet made of a tough matrial and has a silver finish\n"+
"to add a shiny look. From the inside, soft cloth cover the sides\n"+
"to provide more comfort for the head.\n");
set_ac(1);
set_type("helmet");  
set_weight(1);
set_value(600);
}
