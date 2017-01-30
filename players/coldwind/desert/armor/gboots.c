#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("shoes");
set_alias("boots");
set_short(HIK+"Boots of the apes"+NORM);
set_long(HIK+
"  A pair of black boots with white furs decorating the top.\n"+
"They are made from an incredibly thick material, yet they \n"+
"seem very comfotrable.\n"+NORM);
set_ac(2);
set_type("boots");  
set_weight(1);
set_value(1000);
}
