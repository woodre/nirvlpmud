#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("shield");
set_alias("shield");
set_short(HIK+"Shield of the apes"+NORM);
set_long(HIK+
"  A light shield made of a strange black material.  A painting of\n"+
"a face of an angery ape decorates the front of the round shield.\n"+
"As you look closer at the rounded shield, you notice Ashgan's name\n"+ 
"carved on the back of the shield with small letters.\n"+NORM);
set_ac(2);
set_type("shield");  
set_weight(1);
set_value(1200);
}
