#include "/players/maledicta/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("shield");
set_short("a round shield");
set_long(
  "  Much like its name says, this shield is made of wood and is\n"+
  "designed in a circular shape.  A strip of steel binds the wooden\n"+
  "pieces together in an edge.\n");
set_ac(1);
set_type("shield");
set_weight(2);
set_value(80);
}

	
