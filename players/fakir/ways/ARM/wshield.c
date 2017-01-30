#include "/players/fakir/color.h"
inherit "obj/armor";

reset(arg) {
set_name("shield");
set_short("A Battered Shield");
set_long(
  "A wooden shield with leather arm straps and\n"+
  "a twelve inch steel spike in the center.\n");

set_ac(1);
set_type("shield"); 
set_weight(2);
set_value(400);
}

