inherit "obj/armour";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
set_id("shield");
set_type("shield");
set_level(25);
set_short("A round shield");
set_long(
"This is a shield worn by the Saiyan palace guards. It looks thick enough to blo
ck good amounts of damage.\n");
}
