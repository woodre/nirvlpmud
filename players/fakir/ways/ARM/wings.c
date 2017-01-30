#include "/players/fakir/color.h"
inherit "obj/armor";

reset(arg) {
set_name("wings");
set_short(RED+"Myrddraal Wings"+OFF);
set_long(
  "The leather wings from a slain Myrddraal.  With no way\n"+
  "to attach them, you cannot use them to fly, but they\n"+
  "would provide good protection if worn.\n");

set_ac(4);
set_type("armor"); 
set_weight(2);
set_value(1000);
}

