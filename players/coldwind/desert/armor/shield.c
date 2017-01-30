#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("shield");
set_alias("shield");
set_short(HIK+"Dark rounded shield"+NORM);
set_long(
"  A dull black shield made of a strange material. It was said that\n"+
"Ashgan could create such a strange substance using her dark magic.\n"+
"As you look closer at the rounded shield, you notice Ashgan's name\n"+ 
"carved on the back of the shield with small letters.\n");
set_ac(1);
set_type("shield");  
set_weight(1);
set_value(500);
}
