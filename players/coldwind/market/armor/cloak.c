#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("cloak");
set_alias("misc");
set_short(HIB+"Blue cloak"+NORM);
set_long(
"A short blue cloak that would go a little under your lower\n"+
"back. It has silver designs on the shoulders and all around\n"+
"the sides. You wonder how it looks on you!\n");
set_ac(1);
set_type("misc");  
set_weight(1);
set_value(100);
}


