#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("chainmail");
set_alias("suit");
set_short(HIK+"Dukk'hu, the dark suit of chainmail"+NORM);
set_long(
"Dukku'hu is a suit worn by the winged apes of the highest ranks in\n"+
"the army. The dark chains are made from a strange material, yet it\n"+
"is know that Ashgan can create such material using her magic. The suit\n"+
"is very light and provide easy movement as well as good protection for\n"+
"the chest, abdomen, shoulders and back\n");
set_ac(4);
set_params("other|dark",0,15,0);
set_params("other|light",0,-15,0);
set_params("magical",3,0,0);
set_type("armor");  
set_weight(1);
set_value(5000);
}


