#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("pike");
set_short("a heavy pike");
set_long(
"  This is a very long and sturdy pike. Its head is made of thick steel\n"+
"and carries a razor edge.  The shaft is made of wood and is bound in\n"+
"leather for a better grip. It is heavy.\n");
set_type("polearm"); 
set_class(18);
set_weight(4);
set_value(300);
}

