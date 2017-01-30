#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("hat");
set_alias("witch hat");
set_short(HIK+"Witch hat"+NORM);
set_long(HIK+
"  A big black hat that looks really odd to wear. You notice\n"+ 
"nothing special about it but the odor. It stinks!!\n"+NORM);
set_ac(1);
set_params("other|poison",0,15,0);
set_type("helmet");  
set_weight(1);
set_value(300);
}


