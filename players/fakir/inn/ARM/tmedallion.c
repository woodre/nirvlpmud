#include "/players/fakir/color.h"
inherit "obj/armor";

reset(arg) {
set_name("medallion");
set_alias("medallion");
set_short("A Silver Medallion");
set_long(
  "A finely crafted silver medallion in the form of a shield engraved\n"+
  "with crossed swords. This is the symbol and entry token for warriors\n"+
  "who wish to participate in the grand tournament.\n");

set_ac(1);
set_type("amulet");  
set_weight(1);
set_value(600);
}

