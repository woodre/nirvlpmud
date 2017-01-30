#include "/players/fakir/color.h"
inherit "obj/armor";

reset(arg) {
set_name("Silver Medallion");
set_alias("medallion");
set_short("A silver medallion");
set_long(
  "A finely crafted silver medallion in the form of a balance\n"+
  "scales.  It is the token worn by the mayor of the Two Rivers.\n");

set_ac(1);
set_type("necklace");  
set_weight(1);
set_value(600);
}

