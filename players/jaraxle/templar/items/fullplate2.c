#include "/players/jaraxle/ansi.h"
inherit "obj/armor";
reset(arg) {
set_name("armor");
set_alias("fullplate");
set_short(GRN+"Templar"+NORM+BOLD+" Fullplate"+NORM);
set_long(
"  This is the armor of a Templar Knight.  It is made from a heavy\n"+
"steel, and covers the chest, shoulders, and upper legs.  A large\n"+
"cross is imprinted on the breast plate, and is outlined in gold\n"+
"work.\n");

set_ac(4);
set_type("armor");
set_weight(2);
set_value(3500);
}

