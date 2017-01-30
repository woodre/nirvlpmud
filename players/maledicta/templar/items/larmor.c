#include "/players/maledicta/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("armor");
set_alias("leather armor");
set_short("Squire's leather armor");
set_long(
"  This is a lightweight armor that offers slight protection. It is\n"+
"made of a rugged leather. The cross of the Templars can be found\n"+
"on the chest.\n");
set_ac(2);
set_type("armor");  
set_weight(1);
set_value(125);
}


