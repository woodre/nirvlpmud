inherit "obj/armour";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
set_id("combat");
set_type("boots");
set_level(20);
set_short("Combat Boots");
set_long(
"These are the combat boots worn by the Saiyans as they ravaged through planets 
and pillaged villages.\n");
}
