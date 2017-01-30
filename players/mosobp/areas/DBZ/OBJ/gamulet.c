inherit "obj/armour";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
set_id("amulet");
set_alias("emerald");
set_type("amulet");
set_level(10);
set_short("An Emerald Amulet");
set_long(
"This is an emerald amulet worn by Saiyans of the past to increase their power. 
 Although it no longer has that power, it still looks like it could lighten some
 damage.\n");
}
